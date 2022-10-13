#include "myapp.h"

// 定义指示灯寄存器地址和寄存器类型
#define LBDS (*((unsigned int *)0x400001))
#define
void INTR_init( void );
void TIMER_init(void);

int nCount;

main()
{
	nCount=0;
	PLL_Init(100);
	SDRAM_init();
	LBDS=0;
	INTR_init();
	TIMER_init();
	while ( 1 )
	{
	}
}

void interrupt Timer()
{
	nCount++; nCount%=1000;
	if ( nCount==0 )
		LBDS^=0xf;
}

void INTR_init( void )
{
	IVPD=0xd0;
	IVPH=0xd0;
	IER0=0x10;
	DBIER0 =0x10;
	IFR0=0xffff;
	asm(" BCLR INTM");

}

void TIMER_init(void)
{
    ioport unsigned int *tim0; 
    ioport unsigned int *prd0; 
    ioport unsigned int *tcr0; 
    ioport unsigned int *prsc0;  
	tim0  =  (unsigned int *)0x1000;
	prd0  =  (unsigned int *)0x1001;
	tcr0  =  (unsigned int *)0x1002;
	prsc0 =  (unsigned int *)0x1003;
   *tcr0 = 0x04f0;
   *tim0 = 0;
   *prd0 = 0x0270f;
   *prsc0 = 9;
   *tcr0 = 0x00e0;
}

