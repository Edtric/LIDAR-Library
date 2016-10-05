/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#include <stdlib.h>
#include <stdio.h>
    
#define LIDARLite_ADDRESS   0x62u
#define RegisterMeasure     0x00u
#define MeasureValue        0x04u
#define RegisterHighLowB    0x8Fu

int main()
{
    CyGlobalIntEnable;
    
    uint8 nackack;
    uint8 buff[2] = { RegisterMeasure , MeasureValue };
    uint8 readbuff[1] = { RegisterHighLowB };
    uint8 distArray[2];
    uint16 distValue;
    char distance[5];
    
    UART_Start();
    I2C_Start();
    
    CyDelay(100);

    for(;;)
    {
        nackack = 100;
        while( nackack != 0 )
        {
            nackack = I2C_I2CMasterWriteBuf( LIDARLite_ADDRESS , buff , 2 , I2C_I2C_MODE_REPEAT_START );
            CyDelay(1);
        }
        
        CyDelay(20);
        
        nackack = 100;
        while( nackack != 0 )
        {
            nackack = I2C_I2CMasterWriteBuf( LIDARLite_ADDRESS , readbuff , 1 , I2C_I2C_MODE_REPEAT_START );
            CyDelay(1);
        }
        
        nackack = 100;
        while( nackack != 0 )
        {
            nackack = I2C_I2CMasterReadBuf( LIDARLite_ADDRESS , distArray , 2 , I2C_I2C_MODE_REPEAT_START );
            CyDelay(1);
        }
        
        distValue = ( distArray[0] << 8 ) + distArray[1];
        
        sprintf( distance , "%d" , distValue );
        UART_UartPutString( distance );
        UART_UartPutString( "\r\n" );
    }
}

/* [] END OF FILE */
