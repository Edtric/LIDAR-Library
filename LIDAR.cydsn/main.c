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

int main()
{
    CyGlobalIntEnable;

    UART_Start();
    I2C_Start();
    
    CyDelay(100);

    for(;;)
    {
        sprintf( distance , "%d" , getDistance() );
        UART_UartPutString( distance );
        UART_UartPutString( "\r\n" );
    }
}

/* [] END OF FILE */
