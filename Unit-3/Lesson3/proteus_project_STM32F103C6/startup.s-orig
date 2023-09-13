/* startup_cortexM3.s
Eng.Ahmed Eldeeb
*/

/* SRAM 0x20000000 */

.section .vectors

.word 0x20001000 		/* 32 byte */ 
.word _reset 			/* 1 Reset  */
.word Vector_handler	/* 2 NMI */
.word Vector_handler	/* 3 HARD fault */ 
.word Vector_handler	/* 4 MM fault */
.word Vector_handler	/* 5 Bus fault */
.word Vector_handler	/* 6 Usage fault */
.word Vector_handler	/* 7 Reserved */
.word Vector_handler	/* 8 Reserved */
.word Vector_handler	/* 9 Reserved */
.word Vector_handler	/* 10 Reserved */
.word Vector_handler	/* 11 SV call */
.word Vector_handler	/* 12 Debug resrved */
.word Vector_handler	/* 13 Reserved */
.word Vector_handler	/* 14 PendSV */
.word Vector_handler	/* 15 SysTick */
.word Vector_handler	/* 16 IRQ0 */
.word Vector_handler	/* 17 IRQ1 */
.word Vector_handler	/* 18 IRQ2 */
.word Vector_handler	/* 19 ...  */
		/* On to IRQ67 */


.section .text

_reset:
	bl main 
	b . 
.thumb_func
Vector_handler:
	b _reset
