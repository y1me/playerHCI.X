
// PIC18F6722 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1H
#pragma config OSC = HSPLL      // Oscillator Selection bits (HS oscillator, PLL enabled (Clock Frequency = 4 x FOSC1))
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Two-Speed Start-up disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = SBORDIS  // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 3         // Brown-out Voltage bits (Minimum setting)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer (WDT enabled)
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3L

// CONFIG3H
#pragma config CCP2MX = PORTC   // CCP2 MUX bit (ECCP2 input/output is multiplexed with RC1)
#pragma config LPT1OSC = OFF    // Low-Power Timer1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RG5 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled)
#pragma config BBSIZ = BB2K     // Boot Block Size Select bits (1K word (2 Kbytes) Boot Block size)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit Block 0 (Block 0 (000800, 001000 or 002000-003FFFh) not code-protected)
#pragma config CP1 = OFF        // Code Protection bit Block 1 (Block 1 (004000-007FFFh) not code-protected)
#pragma config CP2 = OFF        // Code Protection bit Block 2 (Block 2 (008000-00BFFFh) not code-protected)
#pragma config CP3 = OFF        // Code Protection bit Block 3 (Block 3 (00C000-00FFFFh) not code-protected)
#pragma config CP4 = OFF        // Code Protection bit Block 4 (Block 4 (010000-013FFFh) not code-protected)
#pragma config CP5 = OFF        // Code Protection bit Block 5 (Block 5 (014000-017FFFh) not code-protected)
#pragma config CP6 = OFF        // Code Protection bit Block 6 (Block 6 (01BFFF-018000h) not code-protected)
#pragma config CP7 = OFF        // Code Protection bit Block 7 (Block 7 (01C000-01FFFFh) not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot Block (000000-0007FFh) not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit Block 0 (Block 0 (000800, 001000 or 002000-003FFFh) not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit Block 1 (Block 1 (004000-007FFFh) not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit Block 2 (Block 2 (008000-00BFFFh) not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit Block 3 (Block 3 (00C000-00FFFFh) not write-protected)
#pragma config WRT4 = OFF       // Write Protection bit Block 4 (Block 4 (010000-013FFFh) not write-protected)
#pragma config WRT5 = OFF       // Write Protection bit Block 5 (Block 5 (014000-017FFFh) not write-protected)
#pragma config WRT6 = OFF       // Write Protection bit Block 6 (Block 6 (01BFFF-018000h) not write-protected)
#pragma config WRT7 = OFF       // Write Protection bit Block 7 (Block 7 (01C000-01FFFFh) not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block (000000-007FFF, 000FFF or 001FFFh) not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit Block 0 (Block 0 (000800, 001000 or 002000-003FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit Block 1 (Block 1 (004000-007FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit Block 2 (Block 2 (008000-00BFFFh) not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit Block 3 (Block 3 (00C000-00FFFFh) not protected from table reads executed in other blocks)
#pragma config EBTR4 = OFF      // Table Read Protection bit Block 4 (Block 4 (010000-013FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR5 = OFF      // Table Read Protection bit Block 5 (Block 5 (014000-017FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR6 = OFF      // Table Read Protection bit Block 6 (Block 6 (018000-01BFFFh) not protected from table reads executed in other blocks)
#pragma config EBTR7 = OFF      // Table Read Protection bit Block 7 (Block 7 (01C000-01FFFFh) not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot Block (000000-007FFF, 000FFF or 001FFFh) not protected from table reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <p18f6722.h>
#include "./h/pic_init.h"
#include "./h/hwprofile.h"
#include "./h/user_interface.h"
//#include <delays.h>
#include "./h/spi_ide.h"
#include "./h/user.h"
#include <stdio.h>
#include <string.h>






extern volatile struct chbits{
						unsigned spi:1; 
						unsigned tim0:1; 
						unsigned int1:1; 
						unsigned tim1:1; 
						unsigned uartrx:1; 
						unsigned Dtime:1; 
						unsigned Data1:1; 
						unsigned Data2:1;
		
					}flag ;
extern volatile struct flagspi{
						unsigned strinfo:1;
						unsigned bit1:1;
						unsigned info:1;
						unsigned bit0:1;
						unsigned bit4:1;
						unsigned bit5:1;
						unsigned ready:1;
						unsigned bit7:1;

					}flagspi ;



extern volatile DATA_SPI        dataDAC;
extern volatile DATA_SPI        dataSRC;
extern volatile DATA_DISPLAY    dataDSPY1;
extern volatile DATA_DISPLAY    dataDSPY2;
extern volatile DATA_DISPLAY    dataDSPY3;
extern volatile DATA_DISPLAY    dataDSPY4;
extern volatile DATA_DISPLAY    dataDSPY5;
extern volatile DATA_DISPLAY    dataBlank;
extern volatile DATA_DISPLAY    dataREAD;

extern volatile	DATA_DISPLAY    dataDSPY1_info;
extern volatile	DATA_DISPLAY    dataDSPY2_info;
extern volatile	DATA_DISPLAY    dataDSPY3_info;
extern volatile	DATA_DISPLAY    dataDSPY4_info;
extern volatile	DATA_DISPLAY    dataDSPY5_info;

volatile DATA_DISPLAY    p_dataDSPY;

extern volatile char data[64];
extern volatile char datainfo[64];
extern char *pdatainfo;
extern char *pdatainfoEnd;
extern char *pdata;
extern char *ptest;

extern char *pDataTX;
extern char *pDataTXEnd;

extern volatile char DataRX[16];
extern char *pDataRX;

extern char keypad;
extern long trameok;
char keypad_log[3];
volatile long trame_capt;
volatile long count_IR;
volatile long count_IR_BIT;
volatile unsigned long start_IR_MSB, start_IR_LSB;
volatile int count_spi;
volatile int count_info;
unsigned char *p_spi;

void interrupt high_int(void)
{      
	if(SPI_INT_F)
	{
            flag.spi = 1;
            SPI_INT_F = 0;

            if (flagspi.bit4)
            {
                 PORTTEST = ~PORTTEST;
                *p_spi = SPI_BUFF;
                dataSRC.DataRead++;
                *p_spi++;

                if ( dataSRC.DataWrite < dataSRC.DataToWrite)
                {
                    //PORTTEST = ~PORTTEST;
                    SPI_BUFF = *p_spi;
                    dataSRC.DataWrite++;
                }
                else
                {
                    //PORTTEST = ~PORTTEST;
                    S_DRCV = 1;
                    dataSRC.DataToWrite = 0;
                    flagspi.bit4 = 0;
                }

            }

            if (flagspi.bit0)
            {
                *p_spi = SPI_BUFF;
                dataDAC.DataRead++;
                *p_spi++;

               
                if ((dataDAC.DataWrite & 0x01) == 0)
                //if (dataDAC.DataWrite % dataDAC.CSTiming == 0)
                {
                    S_DAC = 1;
                    S_DAC = 1;
                    S_DAC = 1;
                    S_DAC = 1;
                    S_DAC = 1;
                    S_DAC = 0;
                    S_DAC = 0;
                }
                

                if ( dataDAC.DataWrite < dataDAC.DataToWrite)
                {
                    SPI_BUFF = *p_spi;
                    dataDAC.DataWrite++;
                }
                else
                {
                    S_DAC = 1;
                    dataDAC.DataToWrite = 0;
                    flagspi.bit0 = 0;
                }
   
            }

            if (flagspi.bit1)
            {
                *p_spi = SPI_BUFF;
                p_dataDSPY.DataRead++;
                *p_spi++;

                if (p_dataDSPY.DataWrite == 4)
                //if (dataDAC.DataWrite % dataDAC.CSTiming == 0)
                {
                    S_DISPLAY = 1;
                    S_DISPLAY = 1;
                    S_DISPLAY = 1;
                    S_DISPLAY = 1;
                    S_DISPLAY = 0;
                }

                if ( p_dataDSPY.DataWrite < p_dataDSPY.DataToWrite)
                {
                    SPI_BUFF = *p_spi;
                    p_dataDSPY.DataWrite++;
                }
                else
                {
                    S_DISPLAY = 1;
                    p_dataDSPY.DataWrite = 0;
                    p_dataDSPY.DataRead = 0;
                    if(flagspi.bit5)
                    {
                        flagspi.bit5 = 0;
                        keypad_log[0] = keypad_log[1];
                        keypad_log[1] = keypad_log[2];
                        keypad_log[2] = p_dataDSPY._byte[7];
                        if(keypad_log[2] != 0 && keypad_log[1] == 0 && keypad_log[0] == 0)
                        {
                            keypad = keypad_log[2];
                        }
                    }
                    flagspi.bit1 = 0;
                }

            }

	}


    if(TIMDSPY_INT_F)
	{
            if (flagspi.info)
            {
                    count_info = 0;
                    flagspi.info = 0;
                    flagspi.strinfo = 1;
            }
            count_spi++;
            count_info++;
            switch (count_spi)
            {
                case 10:
                    if (dataDAC.DataToWrite != 0 && dataDAC.DataToWrite < 20)
                    {
                        S_DAC = 0;
                        p_spi = &dataDAC._byte[4];
                        SPI_BUFF = *p_spi;
                        dataDAC.DataWrite++;
                        flagspi.bit0 = 1;                    }
                break;

                case 14:
                    if (dataSRC.DataToWrite != 0 && dataSRC.DataToWrite < 20)
                    {
                        S_DRCV = 0;
                        p_spi = &dataSRC._byte[4];
                        PORTTEST = ~PORTTEST;
                        SPI_BUFF = *p_spi;
                        dataSRC.DataWrite++;
                        flagspi.bit4 = 1;
                    }
                break;

                case 18:
                    p_dataDSPY = dataBlank;
                    if (p_dataDSPY.DataToWrite != 0 && p_dataDSPY.DataToWrite < 20 && !flagspi.bit1)
                    {
                        S_DISPLAY = 0;
                        p_spi = &p_dataDSPY._byte[4];
                        SPI_BUFF = *p_spi;
                        p_dataDSPY.DataWrite++;
                        flagspi.bit1 = 1;
                    }
                break;
                case 19:
                    p_dataDSPY = dataDSPY1;
                    if (count_info < Time_info)	p_dataDSPY = dataDSPY1_info;
                    if (p_dataDSPY.DataToWrite != 0 && p_dataDSPY.DataToWrite < 20 && !flagspi.bit1)
                    {
                        S_DISPLAY = 0;
                        p_spi = &p_dataDSPY._byte[4];
                        SPI_BUFF = *p_spi;
                        p_dataDSPY.DataWrite++;
                        flagspi.bit1 = 1;
                    }
                break;

                case 28:
                        p_dataDSPY = dataREAD;
                        flagspi.bit5 = 1;
                        if (p_dataDSPY.DataToWrite != 0 && p_dataDSPY.DataToWrite < 20 && !flagspi.bit1)
                        {
                            S_DISPLAY = 0;
                            p_spi = &p_dataDSPY._byte[4];
                            SPI_BUFF = *p_spi;
                            p_dataDSPY.DataWrite++;
                            flagspi.bit1 = 1;
                        }
                break;

                case 29:
                        p_dataDSPY = dataREAD;
                        flagspi.bit5 = 1;
                        p_dataDSPY._byte[4] = 0x41;
                        p_dataDSPY._byte[8] = 0x41;
                        if (p_dataDSPY.DataToWrite != 0 && p_dataDSPY.DataToWrite < 20 && !flagspi.bit1)
                        {
                            S_DISPLAY = 0;
                            p_spi = &p_dataDSPY._byte[4];
                            SPI_BUFF = *p_spi;
                            p_dataDSPY.DataWrite++;
                            flagspi.bit1 = 1;
                        }
                break;

                case 30:
                    if (dataDAC.DataToWrite != 0 && dataDAC.DataToWrite < 20)
                    {
                        S_DAC = 0;
                        p_spi = &dataDAC._byte[4];
                        SPI_BUFF = *p_spi;
                        dataDAC.DataWrite++;
                        flagspi.bit0 = 1;                    }
                break;

                case 34:
                    if (dataSRC.DataToWrite != 0 && dataSRC.DataToWrite < 20)
                    {
                        S_DRCV = 0;
                        p_spi = &dataSRC._byte[4];
                        PORTTEST = ~PORTTEST;
                        SPI_BUFF = *p_spi;
                        dataSRC.DataWrite++;
                        flagspi.bit4 = 1;
                    }
                break;

                case 38:
                    p_dataDSPY = dataBlank;
                    if (p_dataDSPY.DataToWrite != 0 && p_dataDSPY.DataToWrite < 20 && !flagspi.bit1)
                    {
                        S_DISPLAY = 0;
                        p_spi = &p_dataDSPY._byte[4];
                        SPI_BUFF = *p_spi;
                        p_dataDSPY.DataWrite++;
                        flagspi.bit1 = 1;
                    }
                break;
                case 39:
                    p_dataDSPY = dataDSPY2;
					if (count_info < Time_info)	p_dataDSPY = dataDSPY2_info;
                    if (p_dataDSPY.DataToWrite != 0 && p_dataDSPY.DataToWrite < 20 && !flagspi.bit1)
                    {
                        S_DISPLAY = 0;
                        p_spi = &p_dataDSPY._byte[4];
                        SPI_BUFF = *p_spi;
                        p_dataDSPY.DataWrite++;
                        flagspi.bit1 = 1;
                    }
                break;

                case 50:
                    if (dataDAC.DataToWrite != 0 && dataDAC.DataToWrite < 20)
                    {
                        S_DAC = 0;
                        p_spi = &dataDAC._byte[4];
                        SPI_BUFF = *p_spi;
                        dataDAC.DataWrite++;
                        flagspi.bit0 = 1;                    }
                break;

                case 54:
                    if (dataSRC.DataToWrite != 0 && dataSRC.DataToWrite < 20)
                    {
                        S_DRCV = 0;
                        p_spi = &dataSRC._byte[4];
                        PORTTEST = ~PORTTEST;
                        SPI_BUFF = *p_spi;
                        dataSRC.DataWrite++;
                        flagspi.bit4 = 1;
                    }
                break;

                case 58:
                    p_dataDSPY = dataBlank;
                    if (p_dataDSPY.DataToWrite != 0 && p_dataDSPY.DataToWrite < 20 && !flagspi.bit1)
                    {
                        S_DISPLAY = 0;
                        p_spi = &p_dataDSPY._byte[4];
                        SPI_BUFF = *p_spi;
                        p_dataDSPY.DataWrite++;
                        flagspi.bit1 = 1;
                    }
                break;
                case 59:
                    p_dataDSPY = dataDSPY3;
					if (count_info < Time_info)	p_dataDSPY = dataDSPY3_info;
                    if (p_dataDSPY.DataToWrite != 0 && p_dataDSPY.DataToWrite < 20 && !flagspi.bit1)
                    {
                        S_DISPLAY = 0;
                        p_spi = &p_dataDSPY._byte[4];
                        SPI_BUFF = *p_spi;
                        p_dataDSPY.DataWrite++;
                        flagspi.bit1 = 1;
                    }
                break;

                case 70:
                    if (dataDAC.DataToWrite != 0 && dataDAC.DataToWrite < 20)
                    {
                        S_DAC = 0;
                        p_spi = &dataDAC._byte[4];
                        SPI_BUFF = *p_spi;
                        dataDAC.DataWrite++;
                        flagspi.bit0 = 1;                    }
                break;

                case 74:
                    if (dataSRC.DataToWrite != 0 && dataSRC.DataToWrite < 20)
                    {
                        S_DRCV = 0;
                        p_spi = &dataSRC._byte[4];
                        PORTTEST = ~PORTTEST;
                        SPI_BUFF = *p_spi;
                        dataSRC.DataWrite++;
                        flagspi.bit4 = 1;
                    }
                break;

                case 78:
                    p_dataDSPY = dataBlank;
                    if (p_dataDSPY.DataToWrite != 0 && p_dataDSPY.DataToWrite < 20 && !flagspi.bit1)
                    {
                        S_DISPLAY = 0;
                        p_spi = &p_dataDSPY._byte[4];
                        SPI_BUFF = *p_spi;
                        p_dataDSPY.DataWrite++;
                        flagspi.bit1 = 1;
                    }
                break;
                case 79:
                    p_dataDSPY = dataDSPY4;
                    if (count_info < Time_info)	p_dataDSPY = dataDSPY4_info;
                    if (p_dataDSPY.DataToWrite != 0 && p_dataDSPY.DataToWrite < 20 && !flagspi.bit1)
                    {
                        S_DISPLAY = 0;
                        p_spi = &p_dataDSPY._byte[4];
                        SPI_BUFF = *p_spi;
                        p_dataDSPY.DataWrite++;
                        flagspi.bit1 = 1;
                    }
                break;

                case 90:
                    if (dataDAC.DataToWrite != 0 && dataDAC.DataToWrite < 20)
                    {
                        S_DAC = 0;
                        p_spi = &dataDAC._byte[4];
                        SPI_BUFF = *p_spi;
                        dataDAC.DataWrite++;
                        flagspi.bit0 = 1;                    }
                break;

                case 94:
                    if (dataSRC.DataToWrite != 0 && dataSRC.DataToWrite < 20)
                    {
                        S_DRCV = 0;
                        p_spi = &dataSRC._byte[4];
                        PORTTEST = ~PORTTEST;
                        SPI_BUFF = *p_spi;
                        dataSRC.DataWrite++;
                        flagspi.bit4 = 1;
                    }
                break;

                case 98:
                    p_dataDSPY = dataBlank;
                    if (p_dataDSPY.DataToWrite != 0 && p_dataDSPY.DataToWrite < 20 && !flagspi.bit1)
                    {
                        S_DISPLAY = 0;
                        p_spi = &p_dataDSPY._byte[4];
                        SPI_BUFF = *p_spi;
                        p_dataDSPY.DataWrite++;
                        flagspi.bit1 = 1;
                    }
                break;
                case 99:
                    p_dataDSPY = dataDSPY5;
                    if (count_info < Time_info)	p_dataDSPY = dataDSPY5_info;
                    if (p_dataDSPY.DataToWrite != 0 && p_dataDSPY.DataToWrite < 20 && !flagspi.bit1)
                    {
                        S_DISPLAY = 0;
                        p_spi = &p_dataDSPY._byte[4];
                        SPI_BUFF = *p_spi;
                        p_dataDSPY.DataWrite++;
                        flagspi.bit1 = 1;
                    }
                break;


                default:
                    ;

            }
            if (count_spi == 100)           count_spi = 0;
            if (count_info >= Time_info)    count_info--;
            TIMERDSPY_REG = 0;
            TIMDSPY_INT_F = 0;
	}
    

	if(INT1_INT_F)
	{
            if (flagspi.bit7)
            {
                if(start_IR_MSB > 3) trame_capt |= 1;
                trame_capt = trame_capt << 1;
                count_IR_BIT++;
                if (count_IR_BIT == 32)
                {
                    trameok = trame_capt;
                    flagspi.bit7 = 0;
                }
            }

            count_IR = 0;
            start_IR_MSB = 0;
            start_IR_LSB = 0;
            flag.int1 = 0;
            EN_TIMIR = 1;
            INT1_INT_F = 0;
	}
    
    if(TIMIR_INT_F)
	{
            if (count_IR < 32)
            {
                start_IR_MSB = start_IR_MSB << 1;
                start_IR_MSB |= INPUT_IR;     
            }
            else
            {
                start_IR_LSB = start_IR_LSB << 1;
                start_IR_LSB |= INPUT_IR;      
            }
            count_IR++;
            if (count_IR > 40 && !flagspi.bit7)
            {
                 EN_TIMIR = 0;
                 if (start_IR_MSB < 16 && start_IR_LSB > 500)
                 {
                     flagspi.bit7 = 1;
                     count_IR_BIT = 0;
                     trame_capt = 0;
                 }
            }
            //if (count_IR > 40 && !flagspi.bit7)
		flag.tim1 = 1;
		TIMERIR_REGH = 0xF4;
		TIMERIR_REG = 0x47;
		TIMIR_INT_F = 0;
                                       

	}
}


void interrupt low_priority low_int(void)
{
	if(TIMSUB_INT_F)
	{
		flag.tim0 = 1;
		TIMERSUB_REGH = 0xA4;
		TIMERSUB_REG = 0x71;
		TIMSUB_INT_F =0;
	}
    
    if(UART_TX_INT_F && TX_UART_INT_E)
	{ 
        TX_UART_REG = *pDataTX;
        *pDataTX++;
        if (pDataTX > pDataTXEnd )
        {
            TX_UART_INT_E = 0;
        }
    }
    
    while(UART_RX_INT_F)
    {
        *pDataRX = *(pDataRX +1);
        *(pDataRX +1) = *(pDataRX +2);
        *(pDataRX +2) = *(pDataRX +3);
        *(pDataRX +3) = *(pDataRX +4);
        *(pDataRX +4) = *(pDataRX +5);
        *(pDataRX +5) = *(pDataRX +6);
        *(pDataRX +6) = *(pDataRX +7);
        *(pDataRX +7) = *(pDataRX +8);
        *(pDataRX +8) = *(pDataRX +9);
        *(pDataRX +9) = *(pDataRX +10);
        *(pDataRX +10) = *(pDataRX +11);
        *(pDataRX +11) = *(pDataRX +12);
        *(pDataRX +12) = *(pDataRX +13);
        *(pDataRX +13) = *(pDataRX +14);
        *(pDataRX +14) = *(pDataRX +15);
        *(pDataRX +15) = RX_UART_REG;
        flag.uartrx = 1;
        /*
        if (*pDataRX == '~' && *(pDataRX +1) == '#')
        {
            if (*(pDataRX +2) == 'A' && *(pDataRX +3) == '=')
            {
                // command : ~#A=XXXXXX time info 6 digit
                data[0] = *(pDataRX +4);
                data[1] = *(pDataRX +5);
                data[2] = *(pDataRX +6);
                data[3] = *(pDataRX +7);
                data[4] = *(pDataRX +8);
                data[5] = *(pDataRX +9);
                flag.Dtime = 1;
            }
            if (*(pDataRX +2) == 'B' && *(pDataRX +3) == '=')
            {
                // command : ~#B=XXXXXX info 6 lettres
                data[0] = *(pDataRX +4);
                data[1] = *(pDataRX +5);
                data[2] = *(pDataRX +6);
                data[3] = *(pDataRX +7);
                data[4] = *(pDataRX +8);
                data[5] = *(pDataRX +9);
                flag.Data1 = 1;
            }
            if (*(pDataRX +2) == 'C' && *(pDataRX +3) == '=')
            {
                flag.Data2 = 1;
                pdata = &datainfo[0];
                *pdata = *(pDataRX +4); 
            }
            if (*(pDataRX +2) == 'D' && *(pDataRX +3) == '=')
            {
                count_info = *(pDataRX +4);
                count_info = count_info << 8;
                count_info |= *(pDataRX +5);
            }
            if (*(pDataRX +2) == 'E' && *(pDataRX +3) == '=')
            {
                flagspi.info = 1;
            }
        }
        else
        {
            if (flag.Data2 && pdata < &datainfo[53])
            {
                *pdata++;
                if (*(pDataRX +15) == '#' && *(pDataRX +14) == '~')
                {
                    *pdata = *(pDataRX +4);
                    *(pdata +1) = *(pDataRX +4);
                    *(pdata +2) = *(pDataRX +5);
                    *(pdata +3) = *(pDataRX +6);
                    *(pdata +4) = *(pDataRX +7);
                    *(pdata +5) = *(pDataRX +8);
                    *(pdata +6) = *(pDataRX +9);
                    *(pdata +7) = *(pDataRX +10);
                    *(pdata +8) = *(pDataRX +11);
                    *(pdata +9) = *(pDataRX +12);
                    *(pdata +10) = *(pDataRX +13);
                    pdatainfoEnd = pdata +10;
                    flag.Data2 = 0;
                }
                else *pdata = *(pDataRX +4);    
                if (pdata == &datainfo[53]) flag.Data2 = 0;
            }
            

        }
         */
    }
    
}
    





void main(void)
{

	int i;

	Port_Init();
	Spi_Init();
    USART_Init();
	Timer0_Init();
	Timer1_Init();
	flag.spi = 0;
	flag.tim0 = 0;
	flag.tim1 = 0;
	flag.int1 = 0;
	flag.Dtime = 0;
	flag.Data1 = 0;
	flag.Data2 = 0;
	flagspi.info = 0;
    flagspi.bit0 = 0;
    flagspi.bit0 = 0;
    flagspi.bit4 = 0;
    dataSRC.DataToWrite = 0;
	dataDAC.DataToWrite = 0;
	dataDSPY1.DataToWrite = 0;
	dataDSPY2.DataToWrite = 0;
	dataDSPY3.DataToWrite = 0;
	dataDSPY4.DataToWrite = 0;
	S_DRCV = 1;
	S_DAC = 1;
	S_DISPLAY = 1;
	count_spi = 0;
	count_info = Time_info;
    INT_Init();
	InitMCP23S17();
	Timer2_Init();
	trameok = 0;
	InitDSPY();
    strcpy(data,"the pixies where is my mind");
    ptest = &data[0];
    pDataRX = &DataRX[0];
    

        PORTTEST = 0;

	while(1)
	{
		ProcessIO();
	}


}