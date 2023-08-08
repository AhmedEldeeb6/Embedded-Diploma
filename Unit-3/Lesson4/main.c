//Ahmed Eldeeb

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#define SYSTL_RCGC2_R (*((volatile unsigned long*)(0x400FE108)))
#define GPIO_PROTF_DIR_R (*((volatile unsigned long*)(0x40025400)))
#define GPIO_PROTF_DEN_R (*((volatile unsigned long*)(0x4002551C)))
#define GPIO_PROTF_DATA_R (*((volatile unsigned long*)(0x400253FC)))

int main()
{
	volatile unsigned long delay_count; 
	SYSTL_RCGC2_R = 0x20;
	//delay to make sure GPIOf is up and runnig 
	for (delay_count=0; delay_count < 200; delay_count ++);
	GPIO_PROTF_DIR_R |= 1<<3; //DIR is output for pin 3 port F
	GPIO_PROTF_DEN_R |= 1<<3;
	while (1)
	{
		GPIO_PROTF_DATA_R |= 1<<3;
		for (delay_count=0; delay_count < 20000; delay_count ++);
		GPIO_PROTF_DATA_R &= ~(1<<3);
		for (delay_count=0; delay_count < 20000; delay_count ++);
	}
	return 0 ;
}