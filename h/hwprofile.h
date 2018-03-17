#ifndef HARDWARE_PROFILE_H
#define HARDWARE_PROFILE_H



    #define CLOCK_FREQ          40000000
    #define _XTAL_FREQ          40000000
    #define Time_info           20000
    #define Scan_time           70 //x * 0.01s
    #define Nb_Retry            50000
    #define SPI_DATA_SIZE       20
    #define DISPLAY_DATA_SIZE   16
    #define TRUE                1
    #define FALSE               0

/**Code telecommande HITACHI CP-RD1***************************/
    #define KEY1                0x0AF5E816	//Power
    #define KEY2                0x0AF508F6	//Recall
    #define KEY3                0x0AF5906E	//RGB/video
    #define KEY4                0x0AF5D02E	//Mute
    #define KEY5                0x0AF548B6	//Vol Up
    #define KEY6                0x0AF5A856	//Vol Down
    #define KEY7                0x0AF5CA34	//Menu
    #define KEY8                0x0AF50EF0	//Select Up
    #define KEY9                0x0AF58E70	//Select Down
    #define KEY10               0x0AF54EB0	//Select Right
    #define KEY11               0x0AF5CE30	//Select Left


/** DEBUG ***********************************************************/
	#define	TRIS_PORTTEST		TRISE0
	#define PORTTEST            PORTEbits.RE0

/** TRIS ***********************************************************/
	#define INPUT_PIN           1
	#define OUTPUT_PIN          0
	#define INPUT_PORT          0xFF
	#define OUTPUT_PORT         0x00

    
    /** SPI ************************************************************/
    #define SPI_RX_IN_PROGRESS  0
    #define SPI_WCOL            SSP1CON1bits.WCOL
    #define SPI_BUF             SSP1BUF
    #define SPI_BF              SSP1STATbits.BF
    #define CS_DSPY             PORTCbits.RC0
   
    /** EUSART ************************************************************/   
    #define UART_TX_INT_F       PIR3bits.TX2IF
    #define TX_UART_REG         TXREG2
    #define TX_UART_INT_E       PIE3bits.TX2IE
    #define UART_RX_INT_F       PIR3bits.RC2IF
    #define RX_UART_REG         RCREG2
    #define UART_RX_OERR        RCSTA2bits.OERR
    #define UART_RX_EN          RCSTA2bits.CREN

    /** Timer telecommande ************************************************************/

 	#define TIMIR_INT_F         TMR1IF
	#define TIMERIR_REGH        TMR1H
	#define TIMERIR_REG         TMR1L
	#define EN_TIMIR            TMR1ON

    /** Timer SubChannel ************************************************************/

 	#define TIMSUB_INT_F        TMR0IF
	#define TIMERSUB_REGH       TMR0H
	#define TIMERSUB_REG        TMR0L
	#define EN_TIMSUB           TMR0ON

    /** Timer Display ************************************************************/

 	#define TIMDSPY_INT_F       TMR2IF
	#define TIMERDSPY_REG       TMR2
	#define EN_TIMDSPY          TMR2ON
   
    /** External Int1 ****************************************************/

 	#define INT1_INT_F          INT1IF
	#define INPUT_IR            PORTBbits.RB1
	#define EN_INT1             INT1IE

    /** Display **********************************************************/

 	#define D_a                 72
 	#define D_b                 224
 	#define D_c                 209
 	#define D_d                 100
 	#define D_e                 80
 	#define D_f                 216
 	#define D_g                 66
 	#define D_h                 232
 	#define D_i                 239
 	#define D_j                 103
 	#define D_k                 104
 	#define D_l                 241
 	#define D_m                 73
 	#define D_n                 236
 	#define D_o                 228
 	#define D_p                 88
 	#define D_q                 74
 	#define D_r                 252
 	#define D_s                 194
 	#define D_t                 240
 	#define D_u                 97
 	#define D_v                 229
 	#define D_w                 229
 	#define D_x                 104
 	#define D_y                 98
 	#define D_z                 84
 	#define D_0                 65
 	#define D_1                 111
 	#define D_2                 84
 	#define D_3                 70
 	#define D_4                 106
 	#define D_5                 194
 	#define D_6                 192
 	#define D_7                 79
 	#define D_8                 64
 	#define D_9                 66
 	#define D_void              255

 	#define d_a                 136
 	#define d_b                 133
 	#define d_c                 147
 	#define d_d                 196
 	#define d_e                 144
 	#define d_f                 153
 	#define d_g                 160
 	#define d_h                 141
 	#define d_i                 239
 	#define d_j                 230
 	#define d_k                 140
 	#define d_l                 151
 	#define d_m                 138
 	#define d_n                 205
 	#define d_o                 197
 	#define d_p                 152
 	#define d_q                 168
 	#define d_r                 221
 	#define d_s                 161
 	#define d_t                 149
 	#define d_u                 199
 	#define d_v                 134
 	#define d_w                 134
 	#define d_x                 140
 	#define d_y                 164
 	#define d_z                 208
 	#define d_0                 130
 	#define d_1                 238
 	#define d_2                 208
 	#define d_3                 224
 	#define d_4                 172
 	#define d_5                 161
 	#define d_6                 129
 	#define d_7                 234
 	#define d_8                 128
 	#define d_9                 160
 	#define d_minus             253
 	#define d_void              255
    #define d_pp                250

    #define STAY_3S             30000
    #define INFO_IT             3
    #define INFO_STAY           250

#endif  //HARDWARE_PROFILE_H
