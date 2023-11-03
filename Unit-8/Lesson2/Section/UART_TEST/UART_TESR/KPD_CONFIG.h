/*
 * KPD_CONFIG.h
 *
 * Created: 9/13/2022 10:14:24 AM
 *  Author: 2M
 */ 


#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

//OUTPUT
#define KPD_COLS_PORT		DIO_PORTB
#define KPD_COL0_PIN		DIO_PIN0	
#define KPD_COL1_PIN		DIO_PIN5
#define KPD_COL2_PIN		DIO_PIN6
#define KPD_COL3_PIN		DIO_PIN7

//INPUT
#define KPD_ROWS_PORT		DIO_PORTC
#define KPD_ROW0_PIN		DIO_PIN3
#define KPD_ROW1_PIN		DIO_PIN4
#define KPD_ROW2_PIN		DIO_PIN5
#define KPD_ROW3_PIN		DIO_PIN6

#define KPD_KEYS			{'1','2','3','A', \
							 '4','5','6','B', \
							 '7','8','9','C', \
							 '*','0','#','D'}

#endif /* KPD_CONFIG_H_ */