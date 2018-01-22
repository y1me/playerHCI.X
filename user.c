
#include "./h/user.h"
#include "./h/spi_ide.h"
//#include "delays.h"
#include "./h/hwprofile.h"
#include "./h/user_interface.h"
#include <p18f6722.h>
#include <stdio.h>
#include <string.h>
#include <xc.h>

/** V A R I A B L E S ********************************************************/
volatile struct chbits{
	unsigned IR:1; 
	unsigned tim0:1; 
	unsigned int1:1; 
	unsigned tim1:1; 
	unsigned Dtime:1; 
	unsigned Data1:1; 
	unsigned Data2:1; 
	unsigned bit7:1;

}flag ;


volatile char data[8];
volatile char datainfo[64];
char *pdata;
char *pdataInfoEnd;
char *pdataInfo;
char *ptest;

volatile char DataTX[20];
char *pDataTX;
char *pDataTXEnd;

volatile char DataRX[20];
char *pDataRX;

char keypad, release, count_dspy;
long trameok;

volatile int count_100us, count_led = 0;

char Init23S17_40[25] = { 0x40,0x00,0xE0,0xF0,0x00,0x00,0x00,0xF0,0x00,0xF0,0x00,0xF0,0x08,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x0F };
//IODIRA,IODIRB,IPOLA,IPOLB,GPINTENA,GPINTENB,DEFVALA,DEFVALB,INTCONA,INTCONB,IOCON,IOCON,GPPUA,GPPUB,INTFA,INTFB,INTCAPA,INTCAPB,GPIOA,GPIOB
char Init23S17_42[25] = { 0x42,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };
char Init23S17_44[25] = { 0x44,0x00,0x00,0x0F,0x00,0x00,0x00,0x0F,0x00,0x0F,0x00,0x0F,0x08,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x00 };
char spi_read[25];

int test;



/** P R I V A T E  P R O T O T Y P E S ***************************************/
unsigned char ProcessIrCode(long *);
void HandleSIRSC(char);
unsigned char ConvertDigit4(unsigned char );
unsigned char ConvertDigit2(unsigned char );
char ReadKeypad(void);
void UpdateLED(char );
void UpdateDSPY(char , char , char );
/*****************************************************************************/
void InitMCP23S17(void)
{   
    char lenght = 0; 
    CS_DSPY = 1;
    CS_DSPY = 0;
    lenght = SPI1_Exchange8bitBuffer(&Init23S17_40[0], 22, &spi_read[0]);
    CS_DSPY = 1;
    CS_DSPY = 1;
    CS_DSPY = 1;
    CS_DSPY = 0;
    lenght = SPI1_Exchange8bitBuffer(&Init23S17_42[0], 22, &spi_read[0]);
    CS_DSPY = 1;
    CS_DSPY = 1;
    CS_DSPY = 1;
    CS_DSPY = 0;
    lenght = SPI1_Exchange8bitBuffer(&Init23S17_44[0], 22, &spi_read[0]);
    CS_DSPY = 1;
    CS_DSPY = 1;
    CS_DSPY = 1;
}

void UpdateDSPY(char data1, char data2, char digit)
{
    char lenght = 0; 
    char reg[8] = { 0x42,0x12,0x00,0x00,0x00,0x00,0x00,0x00 };
    reg[2] = data1;
    reg[3] = data2;
    CS_DSPY = 1;
    CS_DSPY = 0;
    lenght = SPI1_Exchange8bitBuffer(&reg[0], 4, &spi_read[0]);
    CS_DSPY = 1;
    CS_DSPY = 1;
    CS_DSPY = 1;
    lenght = 0; 
    reg[0] = 0x40;
    reg[2] = digit;
    CS_DSPY = 1;
    CS_DSPY = 0;
    lenght = SPI1_Exchange8bitBuffer(&reg[0], 3, &spi_read[0]);
    CS_DSPY = 1;
    CS_DSPY = 1;
    CS_DSPY = 1;   
  
}

void UpdateLED(char led)
{
    char lenght = 0; 
    char reg[8] = { 0x44,0x12,0x00,0x00,0x00,0x00,0x00,0x00 };
    switch ( led )
        {
            case 1:
                reg[2] = 8;
                break;

            case 2:
                reg[2] = 4;
                break;

            case 4:
                reg[2] = 2;
                break;

            case 8:
                reg[2] = 1;
                break;

            case 16:
                reg[2] = 16;
                break;

            case 32:
                reg[2] = 32;
                break;

            case 64:
                reg[2] = 64;
                break;

            case 128:
                reg[2] = 128;
                break;
            
            case 255:
                reg[2] = 255;
                break;
                
            default:
                reg[2] = 0;
	
        }
    CS_DSPY = 1;
    CS_DSPY = 0;
    lenght = SPI1_Exchange8bitBuffer(&reg[0], 3, &spi_read[0]);
    CS_DSPY = 1;
    CS_DSPY = 1;
    CS_DSPY = 1;
}

char ReadKeypad(void)
{
    char lenght = 0; 
    char key = 0;
    char reg[8] = { 0x41,0x0E,0x00,0x00,0x00,0x00,0x00,0x00 };
    CS_DSPY = 1;
    CS_DSPY = 0;
    lenght = SPI1_Exchange8bitBuffer(&reg[0], 8, &spi_read[0]);
    CS_DSPY = 1;
    CS_DSPY = 1;
    CS_DSPY = 1;
    key = spi_read[3];
    key &= 0xF0;
    lenght = 0;
    reg[0] = 0x45;
    CS_DSPY = 0;
    lenght = SPI1_Exchange8bitBuffer(&reg[0], 8, &spi_read[0]);
    CS_DSPY = 1;
    CS_DSPY = 1;
    CS_DSPY = 1;
    key |= spi_read[3];
    CS_DSPY = 1;
    CS_DSPY = 1;
    return key;
}

void HandleSIRSC(char data)
{
	switch ( data )
	{
		case 1:
			trameok = KEY1;
			break;

		case 2:
			trameok = KEY5;
			break;

		case 4:
			trameok = KEY6;
			break;

		case 8:
			trameok = KEY9;
			break;

		case 16:
			trameok = KEY3;
			break;

		case 32:
			trameok = KEY7;
			break;

		case 64:
			trameok = KEY10;
			break;

		case 128:
			trameok = KEY11;
			break;

		default:
			keypad = keypad;
	}

	if (ProcessIrCode(&trameok) == 1)
    {
        if (flag.IR)
        {
            UpdateLED(255);
            count_led = 5;
            flag.IR = 0; 
        }
        trameok = 0;
        
    }
        
}

unsigned char ProcessIrCode(long *trameToProcess)
{		

	switch ( *trameToProcess )
	{
		case KEY1:
			strcpy(DataTX,"POWER\r\n");
            pDataTX = &DataTX[0];
            pDataTXEnd = &DataTX[6];
            TX_UART_INT_E = 1;  
			return 1;
            break;

		case KEY2:
			strcpy(DataTX,"RECALL\r\n");
            pDataTX = &DataTX[0];
            pDataTXEnd = &DataTX[7];
            TX_UART_INT_E = 1; 
			return 1;
			break;

		case KEY7:
  			strcpy(DataTX,"MENU\r\n");
            pDataTX = &DataTX[0];
            pDataTXEnd = &DataTX[5];
            TX_UART_INT_E = 1;
			return 1;
			break;
            
        case KEY8:
  			strcpy(DataTX,"UP\r\n");
            pDataTX = &DataTX[0];
            pDataTXEnd = &DataTX[3];
            TX_UART_INT_E = 1;
			return 1;
			break;

		case KEY9:
            strcpy(DataTX,"DOWN\r\n");
            pDataTX = &DataTX[0];
            pDataTXEnd = &DataTX[5];
            TX_UART_INT_E = 1;
			return 1;
			break;

		case KEY10:
			strcpy(DataTX,"RIGHT\r\n");
            pDataTX = &DataTX[0];
            pDataTXEnd = &DataTX[6];
            TX_UART_INT_E = 1;  
			return 1;
			break;

		case KEY11:
            strcpy(DataTX,"LEFT\r\n");
            pDataTX = &DataTX[0];
            pDataTXEnd = &DataTX[5];
            TX_UART_INT_E = 1;   
			return 1;
			break;

		case KEY4:
			strcpy(DataTX,"MUTE\r\n");
            pDataTX = &DataTX[0];
            pDataTXEnd = &DataTX[5];
            TX_UART_INT_E = 1;
			return 1;
			break;

		case KEY6:
            strcpy(DataTX,"VOLDW\r\n");
            pDataTX = &DataTX[0];
            pDataTXEnd = &DataTX[6];
            TX_UART_INT_E = 1;
			return 1;
			break;

		case KEY5:
            strcpy(DataTX,"VOLUP\r\n");
            pDataTX = &DataTX[0];
            pDataTXEnd = &DataTX[6];
            TX_UART_INT_E = 1;
			return 1;
			break;

		case KEY3:
            strcpy(DataTX,"RGBVIDEO\r\n");
            pDataTX = &DataTX[0];
            pDataTXEnd = &DataTX[9];
            TX_UART_INT_E = 1;
			return 1;
			break;

		default: 
			*trameToProcess = *trameToProcess;
			return 0;
	}
	return 0;
}

unsigned char ConvertDigit4(unsigned char letter)
{
	switch ( letter )
	{
		case  '0':
			return d_0;
			break;

		case  '1':
			return d_1;
			break;

		case  '2':
			return d_2;
			break;

		case  '3':
			return d_3;
			break;

		case  '4':
			return d_4;
			break;

		case  '5':
			return d_5;
			break;

		case  '6':
			return d_6;
			break;

		case  '7':
			return d_7;
			break;

		case  '8':
			return d_8;
			break;

		case  '9':
			return d_9;
			break;

		case  'a':
			return d_a;
			break;

		case  'b':
			return d_b;
			break;

		case  'c':
			return d_c;
			break;

		case  'd':
			return d_d;
			break;

		case  'e':
			return d_e;
			break;

		case  'f':
			return d_f;
			break;

		case  'g':
			return d_g;
			break;

		case  'h':
			return d_h;
			break;

		case  'i':
			return d_i;
			break;

		case  'j':
			return d_j;
			break;

		case  'k':
			return d_k;
			break;

		case  'l':
			return d_l;
			break;

		case  'm':
			return d_m;
			break;

		case  'n':
			return d_n;
			break;

		case  'o':
			return d_o;
			break;

		case  'p':
			return d_p;
			break;

		case  'q':
			return d_q;
			break;

		case  'r':
			return d_r;
			break;

		case  's':
			return d_s;
			break;

		case  't':
			return d_t;
			break;

		case  'u':
			return d_u;
			break;

		case  'v':
			return d_v;
			break;

		case  'w':
			return d_w;
			break;

		case  'x':
			return d_x;
			break;

		case  'y':
			return d_y;
			break;

		case  'z':
			return d_z;
			break;

		default:
			return 255;

	}
}

unsigned char ConvertDigit2(unsigned char letter)
{
	switch ( letter )
	{
		case  '0':
			return D_0;
			break;

		case  '1':
			return D_1;
			break;

		case  '2':
			return D_2;
			break;

		case  '3':
			return D_3;
			break;

		case  '4':
			return D_4;
			break;

		case  '5':
			return D_5;
			break;

		case  '6':
			return D_6;
			break;

		case  '7':
			return D_7;
			break;

		case  '8':
			return D_8;
			break;

		case  '9':
			return D_9;
			break;

		case  'a':
			return D_a;
			break;

		case  'b':
			return D_b;
			break;

		case  'c':
			return D_c;
			break;

		case  'd':
			return D_d;
			break;

		case  'e':
			return D_e;
			break;

		case  'f':
			return D_f;
			break;

		case  'g':
			return D_g;
			break;

		case  'h':
			return D_h;
			break;

		case  'i':
			return D_i;
			break;

		case  'j':
			return D_j;
			break;

		case  'k':
			return D_k;
			break;

		case  'l':
			return D_l;
			break;

		case  'm':
			return D_m;
			break;

		case  'n':
			return D_n;
			break;

		case  'o':
			return D_o;
			break;

		case  'p':
			return D_p;
			break;

		case  'q':
			return D_q;
			break;

		case  'r':
			return D_r;
			break;

		case  's':
			return D_s;
			break;

		case  't':
			return D_t;
			break;

		case  'u':
			return D_u;
			break;

		case  'v':
			return D_v;
			break;

		case  'w':
			return D_w;
			break;

		case  'x':
			return D_x;
			break;

		case  'y':
			return D_y;
			break;

		case  'z':
			return D_z;
			break;

		default:
			return 255;

	}
}

void ProcessIO(void)
{      
    if ( !(count_100us % 1024) )
    {
        
        if (!release)
        {
            keypad = ReadKeypad();
            count_led = 10;
            UpdateLED(keypad);
        }
        release = ReadKeypad();       
        count_100us++;
        count_led--;
        if (count_led < 0)
        {
            count_led == 0;
            UpdateLED(0);
        }
            
    }
    
    HandleSIRSC(keypad);
    keypad = 0;
    
    if (UART_RX_OERR)
    {
        UART_RX_EN = 0;
        Nop();
        Nop();
        Nop();
        UART_RX_EN = 1;
        
    }

    if (flag.tim0)    
    {
        switch ( count_dspy )
        {
            case 1:
                UpdateDSPY( d_z,D_y ,~count_dspy );
                count_dspy = 2;
                break;

            case 2:
                UpdateDSPY( d_x,D_w ,~count_dspy );
                count_dspy = 4;
                break;

            case 4:
                UpdateDSPY( 1,1 ,~count_dspy );
                count_dspy = 8;
                break;

            case 8:
                UpdateDSPY( d_p,d_q ,~count_dspy );
                count_dspy = 16;
                break;

            case 16:
                UpdateDSPY( d_a,d_b ,~count_dspy );
                count_dspy = 1;
                break;
            default:
                count_dspy = 1;
        }
        flag.tim0 = 0;
    }
    	
}
