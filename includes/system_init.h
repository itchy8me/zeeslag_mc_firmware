 
#define REGGET(x) *((volatile unsigned int *)(x))

#define SCRB REGGET(0x400FE000)	// System configure register
#define CLKGATING REGGET(0x400FE608) // Clock ouput pin gating

/* GPIO configuration and data transfer */
#define GPIOAFSEL_PORTC REGGET(0x40006420)


/* Array of ports */
#define GPIODIR_PORTC REGGET(0x40006400)	// I/O direction 
#define GPIODIR_PORTF REGGET(0x40025400)	// I/O direction

/* General purpose timer configuration */
#define GPTMCFG_T0 REGGET(0x40036000)

/* STEPPINGMOTOR INIT */
#define ENABLE_STROBE ((CLKGATING |= 0x20) & (GPIODIR_PORTF |= 0x02)) // Just for aesthetic pleasure
#define ENABLE_STEPPINGMOTOR() ((CLKGATING |= 0x04) & (GPIODIR_PORTC |= 0x10) & (GPIOAFSEL_PORTC |= 0x07) & (GPTMCFG_T0 &= ~(0x01))) // Stepping motor (problem with GPTMCFG)
#define CLOCK REGGET(0x400FE060)
//#define LED1_OUT REGGET()
#define LED1_DEN REGGET(0x4002551C)
#define LED1_ON REGGET(0x400253FC)
#define LED1OUTT REGGET(0x40025504)

#define LED1UNLOCK REGGET(0x40025520)
#define LED1COMMIT REGGET(0x40025524)
#define LED
  
// #define step_motor() (RCGCGPIO |= (PC4 << 1) &\
// 		      GPIOAFSEL |= () &\
// 		      GPIOPCTL |= () &\
// 		      )
		      
 int system_init();'\