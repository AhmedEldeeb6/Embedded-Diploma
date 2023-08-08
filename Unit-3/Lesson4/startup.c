//Startup.c
//Ahmed Eldeeb

#include <stdint.h>
#define _stack_top 0x20001000
extern int main(void);

void Reset_Handler();

void Default_Handler()
{
	Reset_Handler();
}

void NMI_Handler()__attribute__((weak,alias("Default_Handler"))) ;
void H_Fault_Handler()__attribute__((weak,alias("Default_Handler")));

//booking 1024 B located by .bss through unnitialized array of int 256 element (256*4=1024)
static unsigned long Stack_top[256];


void (* const g_p_fn_Vectors[]) ()__attribute__((section(".vectors"))) =
{
(void (*)())	((unsigned long)Stack_top + sizeof(Stack_top)),
				&Reset_Handler,
				&NMI_Handler,
				&H_Fault_Handler ,

};
extern unsigned int _E_text ;
extern unsigned int _S_DATA ;
extern unsigned int _E_DATA ;
extern unsigned int _S_bss ;
extern unsigned int _E_bss ;
void Reset_Handler()
{ 
	//copy data section from flash tot sram 
	unsigned int DATA_size = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA;
	unsigned char* P_src =(unsigned char*)& _E_text;
	unsigned char* P_dst =(unsigned char*)& _S_DATA;

	for(int i =0 ; i < DATA_size ; i++)
	{
	*(unsigned char*)(P_dst++) = *(unsigned char*)P_src;
	}

	//init .bss section in SRAM = 0; 
	unsigned int bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	P_dst=(unsigned char*)& _S_bss;
	for(int i =0 ; i < bss_size ; i++)
	{
	*(unsigned char*)(P_dst++) = (unsigned char) 0;
	}

	//jump main()
	main();
}


