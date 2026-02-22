/* Standard includes. */
#include <stdio.h>
#include <stdint.h>
#include <lcd.h>
#include <time.h>
#include <stdlib.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "lcd.h"
#include "semphr.h"
#include "string.h"


/* Task priorities. */
#define mainFLASH_TASK_PRIORITY	( tskIDLE_PRIORITY + 1)
#define mainUSART_TASK_PRIORITY	( tskIDLE_PRIORITY + 1)
#define mainLCD_TASK_PRIORITY	( tskIDLE_PRIORITY + 1)

#define PLAYER_WIDTH 30
#define PLAYER_THICCNESS 2
#define BALL_RADIUS 3
#define BALL_SPEED 1
#define PAIRING_MSG 0xBEEF

#define mainFLASH_DELAY			( ( TickType_t ) 100 / portTICK_RATE_MS )
#define mainTEMP_DELAY			( ( TickType_t ) 50 / portTICK_RATE_MS )
#define pairingTEMP_DELAY		( ( TickType_t ) 1000 / portTICK_RATE_MS )



static void prvSetupRCC( void );
static void prvSetupGPIO( void );
static void drawMap( void );
static void drawTickedLine( void );
static void drawPlayersTask( void *pvParameters);
static void updateBallTask( void *pvParameters);
static void checkColisionsTask( void *pvParameters);
static void getBallSpeed( int n );
static void prvSetupUSART2( void );
static void prvSendMessageUSART2(char *message);
static void prvSetupUSART1INT( void );
static void init( void );
static void clearLcd( void );
void prvSetupUSART1( void );
static void prvSendMessageUSART1();
static void configEXTI(void);
static void printWinScreen( void );
static void printLoseScreen( void );
static void printScore( void );
static void resetBall( void );
static void pairingTask( void *pvParameters );
static void gameEndingTask( void *pvParameters );
static void ending( void );
static void resetPlayers( void );
static void restart( void );
static void pairingTask( void *pvParameters );
static void pairingScreen( void );
static void suspendGame( void );
static void resumeGame( void );
static void flash( void *pvParameters);

char buff[20];
int ball_x=64, ball_y=79, ball_vel_x = 0, ball_vel_y=-1;
int player_position=60, enemy_position=60, playerScore=0, enemyScore=0, last_player_position=0, last_enemy_position=0;
int gameOverFlag= 0, new_ball_data_flag=0;
int data[3];
SemaphoreHandle_t xSemaphore, pairingSemaphore, usartSemaphore;

typedef struct msg{
	int aa;
	int bb;
	int cc;
}msg;

/***************************************/

/* Task handlers. */
TaskHandle_t playerTaskHandler, ballTaskHandler, checkColisionsTaskHandler, gameTaskHandler, pairingTaskHandler, handler;

/* Queue Variables. */
QueueHandle_t queueusart1, queueusendusart1;


int main( void )
{
	init();

	xSemaphore = xSemaphoreCreateBinary();
	pairingSemaphore = xSemaphoreCreateBinary();
	usartSemaphore = xSemaphoreCreateBinary();
	queueusart1=xQueueCreate( 50, sizeof(msg) );
	queueusendusart1=xQueueCreate( 5, sizeof(uint16_t) );

	/* Create the tasks */
 	xTaskCreate( drawPlayersTask, "Player", configMINIMAL_STACK_SIZE, NULL, mainFLASH_TASK_PRIORITY+1, &playerTaskHandler );
 	xTaskCreate( updateBallTask, "Ball", configMINIMAL_STACK_SIZE, NULL, mainFLASH_TASK_PRIORITY+2, &ballTaskHandler );
 	xTaskCreate( checkColisionsTask, "collisions", configMINIMAL_STACK_SIZE, NULL, mainFLASH_TASK_PRIORITY, &checkColisionsTaskHandler );
 	xTaskCreate( gameEndingTask, "gameEnd", configMINIMAL_STACK_SIZE, NULL, mainFLASH_TASK_PRIORITY, &gameTaskHandler );
 	xTaskCreate( pairingTask, "pairing", configMINIMAL_STACK_SIZE, NULL, mainFLASH_TASK_PRIORITY, &pairingTaskHandler );
 	xTaskCreate( flash, "flash", configMINIMAL_STACK_SIZE, NULL, mainFLASH_TASK_PRIORITY, &handler );
 	suspendGame();
 	vTaskSuspend(gameTaskHandler);
 	pairingScreen();



	/* Start the scheduler. */
	vTaskStartScheduler();

	/* should never get here */
	while(1);

	return 0;
}


static void pairingTask( void *pvParameters ){

	TickType_t xLastExecutionTime;
	xLastExecutionTime = xTaskGetTickCount();


	for(;;){
		if(xSemaphoreTake(pairingSemaphore, (TickType_t) 10) == pdTRUE){

			restart();
			vTaskSuspend(pairingTaskHandler);
		}
		vTaskDelayUntil( &xLastExecutionTime, pairingTEMP_DELAY );
	}
}


static void flash( void *pvParameters ){
	TickType_t xLastExecutionTime;
	xLastExecutionTime = xTaskGetTickCount();

	for(;;){
		if(xSemaphoreTake(usartSemaphore, (TickType_t) 10) == pdTRUE){
			xQueueReceive(queueusart1, &data, ( TickType_t ) 10);

			lcd_draw_circle( ball_x, ball_y, BALL_RADIUS, 0 );
			enemy_position = data[0];
			ball_x = data[1];
			ball_y = data[2];
		}

		vTaskDelayUntil( &xLastExecutionTime, mainTEMP_DELAY );
	}
}


static void init( void ){
	prvSetupRCC();
	prvSetupGPIO();
	prvSetupUSART2();
	prvSetupUSART1();
	configEXTI();
	prvSetupUSART1INT();
	lcd_init();
	clearLcd();
}


static void clearLcd( void ){
	lcd_draw_fillrect(0, 0, LCD_WIDTH, LCD_HEIGHT, 0);
}


static void drawMap( void )
{
	lcd_draw_fillrect(0, 0, LCD_WIDTH, LCD_HEIGHT, 0xffff);
	lcd_draw_fillrect(1, 1, LCD_WIDTH-2, LCD_HEIGHT-2, 0);
}


static void drawTickedLine( void ){
	lcd_draw_line(0 ,79, 7, 79,0xffff);
	lcd_draw_line(13 ,79, 23, 79, 0xffff);
	lcd_draw_line(27 ,79, 37, 79, 0xffff);
	lcd_draw_line(43 ,79, 53, 79, 0xffff);
	lcd_draw_line(59 ,79, 69, 79, 0xffff);
	lcd_draw_line(75 ,79, 85, 79, 0xffff);
	lcd_draw_line(90 ,79, 100, 79, 0xffff);
	lcd_draw_line(105 ,79, 115, 79, 0xffff);
	lcd_draw_line(120 ,79, 127, 79, 0xffff);
}


static void drawPlayersTask( void *pvParameters)
{
	TickType_t xLastExecutionTime;
	xLastExecutionTime = xTaskGetTickCount();
	int position;

	for(;;){
		//draw player
		if(last_player_position != player_position){
			lcd_draw_fillrect(0, 150, LCD_WIDTH, PLAYER_THICCNESS , 0);
			lcd_draw_fillrect(player_position, 150, PLAYER_WIDTH, PLAYER_THICCNESS , 0xd4c3);
			last_player_position = player_position;
		}

	    //draw enemy
	    if(last_enemy_position != enemy_position){
	    	lcd_draw_fillrect(0, 10, LCD_WIDTH, PLAYER_THICCNESS , 0);
			lcd_draw_fillrect(enemy_position, 10, PLAYER_WIDTH, PLAYER_THICCNESS , 0xd4c3);
			last_enemy_position = enemy_position;
	    }

	    position = LCD_WIDTH - player_position - PLAYER_WIDTH;
	    xQueueSendToBack(queueusendusart1, ( void * ) &position, ( TickType_t ) 10);
		prvSendMessageUSART1();


    	vTaskDelayUntil( &xLastExecutionTime, mainFLASH_DELAY );
	}
}


static void updateBallTask( void *pvParameters ){
    TickType_t xLastExecutionTime;
    xLastExecutionTime = xTaskGetTickCount();

    for(;;){


        lcd_draw_circle( ball_x, ball_y, BALL_RADIUS, 0 );

        //check ticked line
        if(ball_y < LCD_HEIGHT/2 + BALL_RADIUS && ball_y > LCD_HEIGHT/2 - BALL_RADIUS){
            drawTickedLine();
        }
        //check to redraw score board
        if(ball_x > 105 && ball_y > 53 && ball_y < 103) printScore();

        ball_x += BALL_SPEED * ball_vel_x;
        ball_y += BALL_SPEED * ball_vel_y;

        //check boundaries
        if(ball_x >= LCD_WIDTH - (BALL_RADIUS+2)) ball_x = LCD_WIDTH - (BALL_RADIUS+2);
        if(ball_x <= (BALL_RADIUS+2)) ball_x = (BALL_RADIUS+2);


        lcd_draw_circle( ball_x, ball_y, BALL_RADIUS, 0xb3df );

        vTaskDelayUntil( &xLastExecutionTime, mainFLASH_DELAY );
    }

}


static void prvSetupRCC( void )
{
    /* RCC configuration - 72 MHz */
    ErrorStatus HSEStartUpStatus;

    RCC_DeInit();
    /*Enable the HSE*/
    RCC_HSEConfig(RCC_HSE_ON);
    /* Wait untill HSE is ready or time out */
    HSEStartUpStatus = RCC_WaitForHSEStartUp();
    if(HSEStartUpStatus == SUCCESS)
    {
        /* Enable The Prefetch Buffer */
        FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
        /* 72 MHZ - 2 wait states */
        FLASH_SetLatency(FLASH_Latency_2);

        /* No division HCLK = SYSCLK */
        RCC_HCLKConfig(RCC_SYSCLK_Div1);
        /* PCLK1 = HCLK/2 (36MHz) */
        RCC_PCLK1Config(RCC_HCLK_Div2);
        /* PCLK2 = HCLK (72MHz)*/
        RCC_PCLK2Config(RCC_HCLK_Div1);

        /* Use PLL with HSE=12MHz */
        RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_6);
        /* Enable the PLL */
        RCC_PLLCmd(ENABLE);
        /* Wait for PLL ready */
        while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET );

        /* Select the PLL as system clock source */
        RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
        /* Wait until PLL is used as system clock */
        while( RCC_GetSYSCLKSource() != 0x08 );
    }
    else
    {
        while(1);
    }
}


static void prvSetupGPIO( void )
{
    /* GPIO configuration - GREEN LED*/
    GPIO_InitTypeDef GPIO_InitStructure;

    /* Enable GPIO Clock */
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA , ENABLE );
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB , ENABLE );
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC , ENABLE );

    /*SW1 and SW3*/
    GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_13 | GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	/*SW5*/
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);


    /*LED D1*/
    GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_0 | GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

}


static void configEXTI(void){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,  ENABLE);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource13);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource11);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource1);

    EXTI_InitTypeDef EXTI1_InitStructure;
	EXTI1_InitStructure.EXTI_Line = EXTI_Line13 | EXTI_Line11 | EXTI_Line1;
	EXTI1_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI1_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI1_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI1_InitStructure);


    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,  DISABLE);

    NVIC_InitTypeDef NVIC_EXTI1_InitStructure;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_EXTI1_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_EXTI1_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_EXTI1_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_EXTI1_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_EXTI1_InitStructure);

	NVIC_EXTI1_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;
	NVIC_Init(&NVIC_EXTI1_InitStructure);


}


static void prvSetupUSART1INT( void ){
	/* ACTIVATE USART1 INT */
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	NVIC_EnableIRQ(USART1_IRQn);
}


void prvSetupUSART2( void )
{
USART_InitTypeDef USART_InitStructure;
GPIO_InitTypeDef GPIO_InitStructure;

    /* USART2 is configured as follow:
        - BaudRate = 115200 baud
        - Word Length = 8 Bits
        - 1 Stop Bit
        - No parity
        - Hardware flow control disabled (RTS and CTS signals)
        - Receive and transmit enabled */

    /* Enable GPIOA clock */
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA , ENABLE );

    /* USART Periph clock enable */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

    GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);


    USART_InitStructure.USART_BaudRate = 115200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;

    /* Configure the USART2 */
    USART_Init(USART2, &USART_InitStructure);
    /* Enable the USART2 */
    USART_Cmd(USART2, ENABLE);
}


void prvSetupUSART1( void )
{
USART_InitTypeDef USART_InitStructure;
GPIO_InitTypeDef GPIO_InitStructure;

    /* USART1 is configured as follow:
        - BaudRate = 9600 baud
        - Word Length = 8 Bits
        - 1 Stop Bit
        - No parity
        - Hardware flow control disabled (RTS and CTS signals)
        - Receive and transmit enabled */

    /* Enable GPIOA clock */
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA , ENABLE );

    /* USART Periph clock enable */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

    GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);


    USART_InitStructure.USART_BaudRate = 9600;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;

    /* Configure the USART1 */
    USART_Init(USART1, &USART_InitStructure);
    /* Enable the USART1*/
    USART_Cmd(USART1, ENABLE);
}


static void prvSendMessageUSART1()
{
	uint16_t message;
	xQueueReceive(queueusendusart1, &message, ( TickType_t ) 10);

	USART_SendData(USART1, message);
	while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET)
	{
	}
	char buff22[20];
	sprintf(buff22,"%d\n", message);
	prvSendMessageUSART2(buff22);
}


static void prvSendMessageUSART2(char *message)
{
uint16_t cont_aux=0;

    while(cont_aux != strlen(message))
    {
        USART_SendData(USART2, (uint8_t) message[cont_aux]);
        while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET)
        {
        }
        cont_aux++;
    }
}


static void getBallSpeed( int n ){
	//n=1, ball hitting player; n=2, ball hitting enemy
	float speeds[] = {-1, 0, 1};
	int i, steps=10;
	if(n==1){
		for(i=0; i<=2; i++){
			if(ball_x >= player_position + steps*i && ball_x < player_position + steps*(i+1)){
				ball_vel_x = speeds[i];
			}
		}
	}
	if(n==2){
		for(i=0; i<=2; i++){
			if(ball_x >= enemy_position + steps*i && ball_x < enemy_position + steps*(i+1)){
				ball_vel_x = speeds[i];
			}
		}
	}

}


static void resetBall( void ){
	ball_vel_x=0;
	ball_vel_y=0;
	ball_x=64;
	ball_y=79;
}


static void checkColisionsTask( void *pvParameters)
{
	TickType_t xLastExecutionTime;
	xLastExecutionTime = xTaskGetTickCount();
	//int i;
	for(;;){
		//check colisions with walls, player and middle line
		if(((ball_x >= LCD_WIDTH-(BALL_RADIUS+2)) && (ball_vel_x > 0)) || ((ball_x <= (BALL_RADIUS+2)) && (ball_vel_x < 0))) {
			ball_vel_x *= -1;
		}
		if(enemyScore==3 || playerScore==3) {
			gameOverFlag=1;
			vTaskResume(gameTaskHandler);
		}

		if(ball_y >= LCD_HEIGHT-(BALL_RADIUS+2) && ball_vel_y==1){
			//LOSE
			resetBall();
			ball_vel_y=1;
			enemyScore += 1;
			printScore();

		}

		if(ball_y <= (BALL_RADIUS+2) && ball_vel_y==-1){
			//WIN
			resetBall();
			ball_vel_y=-1;
			playerScore += 1;
			printScore();
		}

		if(ball_y >= 150 - (BALL_RADIUS+2) && ball_x >= player_position && ball_x <= player_position + PLAYER_WIDTH){
			getBallSpeed(1);
			ball_vel_y = -1;
		}

		if(ball_y <= 10 + (BALL_RADIUS+2) && ball_x >= enemy_position && ball_x <= enemy_position + PLAYER_WIDTH /* && ball_vel_y==-1*/){
			getBallSpeed(2);
			ball_vel_y = 1;
		}

    	vTaskDelayUntil( &xLastExecutionTime, mainTEMP_DELAY );

	}
}


static void gameEndingTask( void *pvParameters ){
	TickType_t xLastExecutionTime;
	xLastExecutionTime = xTaskGetTickCount();

	for(;;){
    	vTaskDelayUntil( &xLastExecutionTime, mainFLASH_DELAY );



    	if(gameOverFlag==1){
    		vTaskSuspend(playerTaskHandler);
    		vTaskSuspend(ballTaskHandler);
    		vTaskSuspend(checkColisionsTaskHandler);
    		ending();
    		gameOverFlag=0;
    	}

		if(xSemaphoreTake( xSemaphore, (TickType_t) portMAX_DELAY) == pdTRUE){
			restart();
		}

	}
}


static void ending( void ){

	if(enemyScore==3)
		printLoseScreen();

	if(playerScore==3)
		printWinScreen();
}


static void restart( void ){
	clearLcd();
	drawMap();
	drawTickedLine();
	resetBall();
	resetPlayers();
	printScore();
	resumeGame();

}


static void resetPlayers( void ){
	player_position=60;
	enemy_position=60;
	playerScore=0;
	enemyScore=0;
}


static void printWinScreen( void ){
	clearLcd();
	lcd_draw_string(30, 40, "YOU", 0xffff, 4);
	lcd_draw_string(25, 75, "WIN!", 0xffff, 4);
}


static void printLoseScreen( void ){
	clearLcd();
	lcd_draw_string(30, 40, "YOU", 0xffff, 4);
	lcd_draw_string(15, 75, "LOSE!", 0xffff, 4);
}


static void printScore( void ){
	char buffer;

	buffer = playerScore + '0';
	lcd_draw_char(108, 85, buffer, 0xffff, 3);

	buffer = enemyScore + '0';
	lcd_draw_char(108, 53, buffer, 0xffff, 3);
}


static void pairingScreen( void ){
	clearLcd();
	lcd_draw_string(20, 40, "PONG", 0xffff, 4);
	lcd_draw_string(25, 140, "Pairing ...", 0xffff, 1);
}


static void suspendGame( void ){
	vTaskSuspend(playerTaskHandler);
	vTaskSuspend(ballTaskHandler);
	vTaskSuspend(checkColisionsTaskHandler);
}


static void resumeGame( void ){
	vTaskResume(playerTaskHandler);
	vTaskResume(ballTaskHandler);
	vTaskResume(checkColisionsTaskHandler);
}


/*-----------------------------------------------------------*/

