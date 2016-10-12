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

#include "LIDAR_Lite.h"


    uint8 buf[2] = { RegisterMeasure , MeasureValue };
    uint8 readbuf[1] = { RegisterHighLowB };
    uint8 distArray[2];

uint16 getDistance( void )
{
    uint16 distValue;
    nackack = 100;
    while( nackack != 0 )
    {
        nackack = I2C_I2CMasterWriteBuf( LIDARLite_ADDRESS , buf , 2 , I2C_I2C_MODE_REPEAT_START );
        CyDelay(1);
    }
    
    CyDelay(20);
    
    nackack = 100;
    while( nackack != 0 )
    {
        nackack = I2C_I2CMasterWriteBuf( LIDARLite_ADDRESS , readbuf , 1 , I2C_I2C_MODE_REPEAT_START );
        CyDelay(1);
    }
    
    nackack = 100;
    while( nackack != 0 )
    {
        nackack = I2C_I2CMasterReadBuf( LIDARLite_ADDRESS , distArray , 2 , I2C_I2C_MODE_REPEAT_START );
        CyDelay(1);
    }
    
    return distValue = ( distArray[0] << 8 ) + distArray[1];
}

/* [] END OF FILE */
