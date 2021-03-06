#include "./h/pic_init.h"
#include "./h/hwprofile.h"
#include <xc.h>




/************************************************************************
*						PIC INIT        								*
************************************************************************/
void Port_Init(void)  //init i/o PIC for enable DAC
{
//UART pin
	TRISGbits.TRISG1 = OUTPUT_PIN;
	TRISGbits.TRISG2 = INPUT_PIN;
//Chip select pin
    TRISCbits.TRISC0 = OUTPUT_PIN;
//Int0 pin
	TRISBbits.TRISB0 = INPUT_PIN;
//Disable analog pin
	ADCON1 = 0x0F;
//Int1 pin
	TRISBbits.TRISB1 = INPUT_PIN;
//Test pin
	TRISEbits.TRISE0 = OUTPUT_PIN;

}

void Spi_Init(void)  //init SPI Bus
{
//SPI Bus pin
	TRISCbits.TRISC3 = OUTPUT_PIN;
	TRISCbits.TRISC5 = OUTPUT_PIN;
	TRISCbits.TRISC4 = INPUT_PIN;
	TRISDbits.TRISD6 = OUTPUT_PIN;
	TRISDbits.TRISD7 = OUTPUT_PIN;
	PORTDbits.RD6 = 1;
	PORTDbits.RD7 = 1;

//SPI Bus register

	SSP1STATbits.CKE = 1;

	SSP1CON1bits.SSPEN = 1;
}

void USART_Init(void)  //init USART
{
    RCSTA2bits.SPEN = 1;

    TXSTA2bits.TX9 = 0;
    TXSTA2bits.SYNC = 0;
    TXSTA2bits.SENDB = 0;
    TXSTA2bits.BRGH = 1;
    
    RCSTA2bits.RX9 = 0;
    BAUDCON2bits.BRG16 = 1;
    SPBRGH2 = 0x00;
    SPBRG2 = 86;
    
    RCSTA2bits.CREN = 1;
    TXSTA2bits.TXEN = 1;
    
}

void INT_Init(void)  //init Interrupt
{
	RCONbits.IPEN = 1;
	
	INTCONbits.GIE_GIEH = 1;
	INTCONbits.PEIE_GIEL = 1;

	//INT1 interrupt

	INTCON3bits.INT1IE = 1;
	INTCON3bits.INT1IP = 1;
	INTCON2bits.INTEDG1 = 0;
	
	//SPI interrupt
	
	//IPR1bits.SSP1IP = 1;
	PIR1bits.SSP1IF = 0;
	PIE1bits.SSP1IE = 0;
    
    //UART interrupt
    
    PIE3bits.TX2IE = 0;
    IPR3bits.TX2IP = 0;
    
    PIE3bits.RC2IE = 1;
    IPR3bits.RC2IP = 1;   

}

void Timer0_Init(void)  //init timer0
{
	
	T0CONbits.T08BIT = 0;
	T0CONbits.T0CS = 0;
	T0CONbits.PSA = 0;
	T0CONbits.T0PS0 = 1;
	T0CONbits.T0PS1 = 1;
	T0CONbits.T0PS2 = 1;
	//TMR0L = 75;
	INTCONbits.TMR0IE = 1;
	INTCON2bits.TMR0IP = 0;

	T0CONbits.TMR0ON = 1; //count 25,6�s
}

void Timer1_Init(void)  //init timer1
{
	
	T1CONbits.RD16 = 1;
	T1CONbits.TMR1CS = 0;
	T1CONbits.T1CKPS1 = 0;
	T1CONbits.T1CKPS0 = 0;

	//TMR0L = 75;
	PIE1bits.TMR1IE = 1;
	IPR1bits.TMR1IP = 1;

	T1CONbits.TMR1ON = 0;
}

void Timer2_Init(void)  //init timer2
{

	T2CONbits.T2OUTPS0 = 1;
    T2CONbits.T2OUTPS1 = 0;
    T2CONbits.T2OUTPS2 = 0;
    T2CONbits.T2OUTPS3 = 0;
	T2CONbits.T2CKPS = 1;

        PR2 = 120; // T = 100�s
        TMR2 = 0;

	PIE1bits.TMR2IE = 1;
	IPR1bits.TMR2IP = 1;

	T2CONbits.TMR2ON = 1;

}