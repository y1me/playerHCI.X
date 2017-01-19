
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
	unsigned spi:1; 
	unsigned tim0:1; 
	unsigned int1:1; 
	unsigned tim1:1; 
	unsigned uartrx:1; 
	unsigned first:1; 
	unsigned nodisc:1; 
	unsigned bit7:1;

}flag ;

volatile struct flagspi{
	unsigned bit0:1;
	unsigned bit1:1;
	unsigned info:1;
	unsigned aux:1;
	unsigned bit4:1;
	unsigned bit5:1;
	unsigned ready:1;
	unsigned bit7:1;

}flagspi ;


volatile   DATA_SPI        dataDAC;
volatile   DATA_SPI        dataSRC;
volatile   DATA_DISPLAY    dataDSPY1;
volatile   DATA_DISPLAY    dataDSPY2;
volatile   DATA_DISPLAY    dataDSPY3;
volatile   DATA_DISPLAY    dataDSPY4;
volatile   DATA_DISPLAY    dataDSPY5;
volatile   DATA_DISPLAY    dataBlank;
volatile   DATA_DISPLAY    dataREAD;

volatile   DATA_DISPLAY    dataDSPY1_info;
volatile   DATA_DISPLAY    dataDSPY2_info;
volatile   DATA_DISPLAY    dataDSPY3_info;
volatile   DATA_DISPLAY    dataDSPY4_info;
volatile   DATA_DISPLAY    dataDSPY5_info;

volatile char data[64];
char *ptest;

volatile char DataTX[16];
char *pDataTX;
char *pDataTXEnd;

volatile char DataRX[16];
char *pDataRX;

char keypad;
long trameok;
int CDStatus;
int TrackToPlay;
int NumbOfTrack;
unsigned char MuteState, RightVol, LeftVol, AudioStatus;
unsigned char TimeoutEN;
char buffer[20];
int length;


/** P R I V A T E  P R O T O T Y P E S ***************************************/
unsigned char ProcessIrCode(long *);
void HandleSIRSC(void);
unsigned char ConvertDigit4(unsigned char );
unsigned char ConvertDigit2(unsigned char );
/*****************************************************************************/
void InitMCP23S17(void)
{   

	S_DISPLAY=1;
	S_DISPLAY = 0;
	spi_out(0x40);
	spi_out(0x00);
	spi_out(0xE0);
	spi_out(0xF0);
	spi_out(0x00);
	spi_out(0x00);
	spi_out(0x00);
	spi_out(0xF0);
	spi_out(0x00);
	spi_out(0xF0);
	spi_out(0x00);
	spi_out(0xF0);
	spi_out(0x08);
	spi_out(0x08);
	spi_out(0x00);
	spi_out(0x00);
	spi_out(0x00);
	spi_out(0x00);
	spi_out(0x00);
	spi_out(0x00);
	spi_out(0x1F);
	spi_out(0x00);
	S_DISPLAY = 1;

	S_DISPLAY = 1;
	S_DISPLAY = 0;
	spi_out(0x42);
	spi_out(0x00);
	spi_out(0x00);
	spi_out(0x00);
	spi_out(0x00);
	spi_out(0x00);
	spi_out(0x00);
	spi_out(0x00);
	spi_out(0x00);
	spi_out(0x00);
	spi_out(0x00);
	spi_out(0x00);
	spi_out(0x08);
	spi_out(0x08);
	spi_out(0x00);
	spi_out(0x00);
	spi_out(0x00);
	spi_out(0x00);
	spi_out(0x00);
	spi_out(0x00);
	spi_out(0x00);
	spi_out(0x00);
	S_DISPLAY = 1;

	S_DISPLAY = 1;
	S_DISPLAY = 0;
	spi_out(0x44);
	spi_out(0x00);
	spi_out(0xF0);//0x00
	spi_out(0xFF);//0x01
	spi_out(0x00);//0x02
	spi_out(0x00);//0x03
	spi_out(0x00);//0x04
	spi_out(0x0F);//0x05
	spi_out(0x00);//0x06
	spi_out(0x0F);//0x07
	spi_out(0x00);//0x08
	spi_out(0x0F);//0x09
	spi_out(0x08);//0x0A
	spi_out(0x08);//0x0B
	spi_out(0x00);//0x0C
	spi_out(0x00);//0x0D
	spi_out(0x00);//0x0E
	spi_out(0x00);//0x0F
	spi_out(0x00);
	spi_out(0x00);
	spi_out(0x00);
	spi_out(0x00);
	S_DISPLAY = 1;

}

void InitDSPY(void)
{
	dataDSPY1.DataToWrite = 8;
	dataDSPY1.DataRead = 0;
	dataDSPY1.DataWrite = 0;
	dataDSPY1._byte[4] = 0x40;
	dataDSPY1._byte[5] = 0x12;
	dataDSPY1._byte[6] = 0xFE;// supply digit
	dataDSPY1._byte[7] = 0x00;// switch & diode
	dataDSPY1._byte[8] = 0x42;
	dataDSPY1._byte[9] = 0x12;
	dataDSPY1._byte[10] = 0xEE;//digit 1/4
	dataDSPY1._byte[11] = 0xE4;//digit 2/2

	dataDSPY2.DataToWrite = 8;
	dataDSPY2.DataRead = 0;
	dataDSPY2.DataWrite = 0;
	dataDSPY2._byte[4] = 0x40;
	dataDSPY2._byte[5] = 0x12;
	dataDSPY2._byte[6] = 0xFD;// supply digit
	dataDSPY2._byte[7] = 0x00;// switch & diode
	dataDSPY2._byte[8] = 0x42;
	dataDSPY2._byte[9] = 0x12;
	dataDSPY2._byte[10] = 0xCD;//digit 2/4
	dataDSPY2._byte[11] = 0x5A;//digit 1/2

	dataDSPY3.DataToWrite = 8;
	dataDSPY3.DataRead = 0;
	dataDSPY3.DataWrite = 0;
	dataDSPY3._byte[4] = 0x40;
	dataDSPY3._byte[5] = 0x12;
	dataDSPY3._byte[6] = 0xF7;// supply digit
	dataDSPY3._byte[7] = 0x00;// switch & diode
	dataDSPY3._byte[8] = 0x42;
	dataDSPY3._byte[9] = 0x12;
	dataDSPY3._byte[10] = 0xEF;//digit 3/4
	dataDSPY3._byte[11] = 0x45;

	dataDSPY4.DataToWrite = 8;
	dataDSPY4.DataRead = 0;
	dataDSPY4.DataWrite = 0;
	dataDSPY4._byte[4] = 0x40;
	dataDSPY4._byte[5] = 0x12;
	dataDSPY4._byte[6] = 0x0F;// supply digit
	dataDSPY4._byte[7] = 0x00;// switch & diode
	dataDSPY4._byte[8] = 0x42;
	dataDSPY4._byte[9] = 0x12;
	dataDSPY4._byte[10] = d_p;//0x95;//digit 4/4
	dataDSPY4._byte[11] = 0xA2;

	dataDSPY5.DataToWrite = 8;
	dataDSPY5.DataRead = 0;
	dataDSPY5.DataWrite = 0;
	dataDSPY5._byte[4] = 0x40;
	dataDSPY5._byte[5] = 0x12;
	dataDSPY5._byte[6] = 0xFB;// supply digit
	dataDSPY5._byte[7] = 0x00;// switch & diode
	dataDSPY5._byte[8] = 0x42;
	dataDSPY5._byte[9] = 0x12;
	dataDSPY5._byte[10] = 0xFF;//digit dp/4
	dataDSPY5._byte[11] = 0x22;

	dataDSPY1_info.DataToWrite = 8;
	dataDSPY1_info.DataRead = 0;
	dataDSPY1_info.DataWrite = 0;
	dataDSPY1_info._byte[4] = 0x40;
	dataDSPY1_info._byte[5] = 0x12;
	dataDSPY1_info._byte[6] = 0xFE;// supply digit
	dataDSPY1_info._byte[7] = 0x00;// switch & diode
	dataDSPY1_info._byte[8] = 0x42;
	dataDSPY1_info._byte[9] = 0x12;
	dataDSPY1_info._byte[10] = 0xEE;//digit 1/4
	dataDSPY1_info._byte[11] = 0xE4;//digit 2/2

	dataDSPY2_info.DataToWrite = 8;
	dataDSPY2_info.DataRead = 0;
	dataDSPY2_info.DataWrite = 0;
	dataDSPY2_info._byte[4] = 0x40;
	dataDSPY2_info._byte[5] = 0x12;
	dataDSPY2_info._byte[6] = 0xFD;// supply digit
	dataDSPY2_info._byte[7] = 0x00;// switch & diode
	dataDSPY2_info._byte[8] = 0x42;
	dataDSPY2_info._byte[9] = 0x12;
	dataDSPY2_info._byte[10] = 0xCD;//digit 2/4
	dataDSPY2_info._byte[11] = 0x5A;//digit 1/2

	dataDSPY3_info.DataToWrite = 8;
	dataDSPY3_info.DataRead = 0;
	dataDSPY3_info.DataWrite = 0;
	dataDSPY3_info._byte[4] = 0x40;
	dataDSPY3_info._byte[5] = 0x12;
	dataDSPY3_info._byte[6] = 0xF7;// supply digit
	dataDSPY3_info._byte[7] = 0x00;// switch & diode
	dataDSPY3_info._byte[8] = 0x42;
	dataDSPY3_info._byte[9] = 0x12;
	dataDSPY3_info._byte[10] = 0xEF;//digit 3/4
	dataDSPY3_info._byte[11] = 0x45;

	dataDSPY4_info.DataToWrite = 8;
	dataDSPY4_info.DataRead = 0;
	dataDSPY4_info.DataWrite = 0;
	dataDSPY4_info._byte[4] = 0x40;
	dataDSPY4_info._byte[5] = 0x12;
	dataDSPY4_info._byte[6] = 0x0F;// supply digit
	dataDSPY4_info._byte[7] = 0x00;// switch & diode
	dataDSPY4_info._byte[8] = 0x42;
	dataDSPY4_info._byte[9] = 0x12;
	dataDSPY4_info._byte[10] = 0x95;//digit 4/4
	dataDSPY4_info._byte[11] = 0xA2;

	dataDSPY5_info.DataToWrite = 8;
	dataDSPY5_info.DataRead = 0;
	dataDSPY5_info.DataWrite = 0;
	dataDSPY5_info._byte[4] = 0x40;
	dataDSPY5_info._byte[5] = 0x12;
	dataDSPY5_info._byte[6] = 0xFB;// supply digit
	dataDSPY5_info._byte[7] = 0x00;// switch & diode
	dataDSPY5_info._byte[8] = 0x42;
	dataDSPY5_info._byte[9] = 0x12;
	dataDSPY5_info._byte[10] = 0xFF;//digit dp/4
	dataDSPY5_info._byte[11] = 0x22;

	dataBlank.DataToWrite = 8;
	dataBlank.DataRead = 0;
	dataBlank.DataWrite = 0;
	dataBlank._byte[4] = 0x40;
	dataBlank._byte[5] = 0x12;
	dataBlank._byte[6] = 0xFF;// supply digit
	dataBlank._byte[7] = 0x00;// switch & diode
	dataBlank._byte[8] = 0x42;
	dataBlank._byte[9] = 0x12;
	dataBlank._byte[10] = 0xFF;//digit dp/4
	dataBlank._byte[11] = 0xFF;

	dataREAD.DataToWrite = 8;
	dataREAD.DataRead = 0;
	dataREAD.DataWrite = 0;
	dataREAD._byte[4] = 0x45;
	dataREAD._byte[5] = 0x0E;
	dataREAD._byte[6] = 0x00;
	dataREAD._byte[7] = 0x00;
	dataREAD._byte[8] = 0x45;
	dataREAD._byte[9] = 0x10;
	dataREAD._byte[10] = 0x00;
	dataREAD._byte[11] = 0x00;
}

void HandleSIRSC(void)
{
	switch ( keypad )
	{
		case 1:
			trameok = KEY1;
			keypad = 0;
			break;

		case 2:
			trameok = KEY9;
			keypad = 0;
			break;

		case 4:
			trameok = KEY10;
			keypad = 0;
			break;

		case 8:
			trameok = KEY11;
			keypad = 0;
			break;

		case 16:
			trameok = KEY3;
			keypad = 0;
			break;

		case 32:
			trameok = KEY6;
			keypad = 0;
			break;

		case 64:
			trameok = KEY5;
			keypad = 0;
			break;

		case 128:
			trameok = KEY7;
			keypad = 0;
			break;

		default:
			keypad = keypad;
	}

	if (ProcessIrCode(&trameok) == 1) trameok = 0;
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
			strcpy(DataTX,"RESET\r\n");
            pDataTX = &DataTX[0];
            pDataTXEnd = &DataTX[6];
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
            strcpy(DataTX,"SOURCE\r\n");
            pDataTX = &DataTX[0];
            pDataTXEnd = &DataTX[7];
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
    HandleSIRSC();
    
    if (UART_RX_OERR)
    {
        UART_RX_EN = 0;
        Nop();
        Nop();
        Nop();
        UART_RX_EN = 1;
        
    }
    if (flag.uartrx)
    {
        flag.uartrx = 0;
        if(strstr(DataRX, "test") != NULL)
        {
            
            dataDSPY2_info._byte[11] = D_void;//digit 1/2 
			dataDSPY1_info._byte[11] = D_void;//digit 2/2 
			dataDSPY1_info._byte[10] = d_s;//digit 1/4 
			dataDSPY2_info._byte[10] = d_t;//digit 2/4
			dataDSPY3_info._byte[10] = d_o;//digit 3/4
			dataDSPY4_info._byte[10] = d_p;//digit 4/4
			dataDSPY5_info._byte[10] = d_void;//digit dp/4
			flagspi.info = 1;
            strcpy(DataRX, "gggg_gggg_gggg_g");
            
        }
        
    }
    
    
    if (flag.tim0)    
    {
        flag.tim0 = 0;
        *ptest++;
        if ( ptest == &data[23] ) ptest = &data[0]; 
    }
				dataDSPY2._byte[11] = ConvertDigit2( *ptest );//digit 1/2 
				dataDSPY1._byte[11] = ConvertDigit2( *(ptest+1) );//digit 2/2
				dataDSPY1._byte[10] = ConvertDigit4( *(ptest+2) );//digit 1/4
				dataDSPY2._byte[10] = ConvertDigit4( *(ptest+3) );//digit 2/4
				dataDSPY3._byte[10] = ConvertDigit4( *(ptest+4) );//digit 3/4
				dataDSPY4._byte[10] = ConvertDigit4( *(ptest+5) );//digit 4/4		
}
