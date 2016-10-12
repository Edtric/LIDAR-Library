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
#ifndef LIDAR_LITE_H
#define LIDAR_LITE_H
    
    #include <project.h>
    #include <stdlib.h>
    #include <stdio.h>
        
    #define LIDARLite_ADDRESS   (0x62u)
    #define RegisterMeasure     (0x00u)
    #define MeasureValue        (0x04u)
    #define RegisterHighLowB    (0x8Fu)
        
    uint8 nackack;
    char distance[5];
    uint16 getDistance( void );
    
#endif

/* [] END OF FILE */
