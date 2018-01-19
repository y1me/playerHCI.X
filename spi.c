#include "./h/hwprofile.h"
#include <xc.h>
#include "./h/spi_ide.h"

extern volatile struct chbits{
						unsigned spi:1; 
						unsigned bit1:1; 
						unsigned bit2:1; 
						unsigned bit3:1; 
						unsigned bit4:1; 
						unsigned bit5:1; 
						unsigned bit6:1; 
						unsigned bit7:1;
		
					}flag ;

char SPI1_Exchange8bit(char data)
{
    // Clear the Write Collision flag, to allow writing
    SPI_WCOL = 0;

    SPI_BUF = data;

    while(!SPI_BF);

    return (SPI_BUF);
}

char SPI1_Exchange8bitBuffer(char *dataIn, char bufLen, char *dataOut)
{
    char bytesWritten = 0;
    
    if ( dataOut == NULL || dataIn == NULL)  return bytesWritten;

    if( bufLen != 0 )
    {

        while(bytesWritten < bufLen)
        {
            *dataOut = SPI1_Exchange8bit(*dataIn);
            *dataIn++;
            *dataOut++;
            bytesWritten++;
        }
    }
    return bytesWritten;

}

bool SPI1_IsBufferFull(void)
{
    return (SPI_BF);
}

bool SPI1_HasWriteCollisionOccured(void)
{
    return (SPI_WCOL);
}

void SPI1_ClearWriteCollisionStatus(void)
{
    SPI_WCOL = 0;
}