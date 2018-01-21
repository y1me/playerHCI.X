
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
						unsigned Dtime:1; 
						unsigned Data1:1; 
						unsigned Data2:1; 
						unsigned bit7:1;
		
					}flag ;


extern volatile char data[8];
extern volatile char datainfo[64];
extern char *pdata;
extern char *pdataInfoEnd;
extern char *ptest;

extern char *pDataTX;
extern char *pDataTXEnd;

extern volatile char DataRX[20];
extern char *pDataRX;

extern long trameok;
volatile long trame_capt;
volatile long count_IR;
volatile long count_IR_BIT;
volatile unsigned long start_IR_MSB, start_IR_LSB;
volatile int count_info;
extern volatile int count_100us;

void interrupt high_int(void)
{      
	
    if(TIMDSPY_INT_F)
	{
        count_100us++;
        TIMERDSPY_REG = 0;
        TIMDSPY_INT_F = 0;
	}
    

	if(INT1_INT_F)
	{
            if (flag.bit7)
            {
                if(start_IR_MSB > 3) trame_capt |= 1;
                trame_capt = trame_capt << 1;
                count_IR_BIT++;
                if (count_IR_BIT == 32)
                {
                    trameok = trame_capt;
                    flag.bit7 = 0;
                }
            }

            count_IR = 0;
            start_IR_MSB = 0;
            start_IR_LSB = 0;
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
        if (count_IR > 40 && !flag.bit7)
        {
             EN_TIMIR = 0;
             if (start_IR_MSB < 16 && start_IR_LSB > 500)
             {
                 flag.bit7 = 1;
                 count_IR_BIT = 0;
                 trame_capt = 0;
             }
        }		
        TIMERIR_REGH = 0xF4;
		TIMERIR_REG = 0x47;
		TIMIR_INT_F = 0;
                                       

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
            }
            if (*(pDataRX +2) == 'B' && *(pDataRX +3) == '=')
            {
                // command : ~#B=XXXXXX info 6 letter
                data[0] = *(pDataRX +4);
                data[1] = *(pDataRX +5);
                data[2] = *(pDataRX +6);
                data[3] = *(pDataRX +7);
                data[4] = *(pDataRX +8);
                data[5] = *(pDataRX +9);
            }
            
            if (*(pDataRX +2) == 'C' && *(pDataRX +3) == '=')
            {
                // command : ~#C=XXXXXX info data 64 symbols 
                flag.Data2 = 1;
                pdata = &datainfo[0];
                *pdata = *(pDataRX +4); 
            }
            
            if (*(pDataRX +2) == 'D' && *(pDataRX +3) == '=')
            {
                // command : ~#D=XXXXXX time info data?
                count_info = *(pDataRX +4);
                count_info = count_info << 8;
                count_info |= *(pDataRX +5);
            }
            if (*(pDataRX +2) == 'E' && *(pDataRX +3) == '=')
            {
                // command : ~#E=XXXXXX show info data

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
                    pdataInfoEnd = pdata +10;
                    flag.Data2 = 0;
                }
                else *pdata = *(pDataRX +4);    
                if (pdata == &datainfo[53]) flag.Data2 = 0;
            }
        }

    }
}


void interrupt low_priority low_int(void)
{
	if(TIMSUB_INT_F)
	{

		flag.tim0 = 1;//0,6s
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
	flag.int1 = 0; 
	flag.tim1 = 0; 
	flag.Dtime = 0; 
	flag.Data1 = 0; 
	flag.Data2 = 0; 
	flag.bit7 = 0;
 

	CS_DSPY = 1;
	count_info = Time_info;
    INT_Init();
	InitMCP23S17();
	Timer2_Init();
	trameok = 0;
	InitDSPY();
    strcpy(datainfo,"the pixies where is my mind");
    ptest = &data[0];
    pDataRX = &DataRX[0];
    

        PORTTEST = 0;

	while(1)
	{
		ProcessIO();
	}


}