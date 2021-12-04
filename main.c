#include <stm32f10x.h>
void inicializar(void);
void notas(int);
void primeiraOitava(void);
void segundaOitava(void);

static int oitava1[13] = {151, 142, 134, 126, 119, 113, 106, 100, 95, 89, 84, 79, 151};
static int oitava2[13] = {75, 70, 67, 63, 59, 56, 52, 50, 47, 44, 42, 39, 70};

int main(){
	int oitava = 1;
	inicializar();
	while(1){ 
		notas(oitava);
	}
}
void inicializar(){
	/// Inicializa e configura todas as portas necessários para o projeto
	RCC -> APB2ENR |= 0xFC ; // Enable the clocks for GPIO ports RCC
	RCC -> APB2ENR |= RCC_APB2ENR_AFIOEN ; 
	AFIO -> MAPR |= AFIO_MAPR_SWJ_CFG_JTAGDISABLE ; 
	RCC->APB2ENR |= 0xFC; // enable GPIO clocks 
	RCC->APB1ENR |= (1<<1); // enable TIM3 clock 
	TIM3->CCR3 = 0; // start the square signal at 0s 
	TIM3->CCER = 0x1 << 8; // 0 em CC3P, 1 em CC3E 
	TIM3->CCMR2 = 0x0030; // toggle channel 3 
	TIM3->PSC = 7200-1; // prescale of 7200Hz 
	TIM3->ARR = 38-1; // counter 
	TIM3->CR1 = 1; // base of score
	GPIOA ->CRL = 0x44444444 ; /* PA0 :PA7 as inputs */ 
	GPIOA ->CRH = 0x44444444 ; /* PA8 : PA15 as inputs */ 
	GPIOB ->CRL = 0x4444444B ; /* PB0 :PB7 as inputs */ 
	GPIOB ->CRH = 0x44444444 ; /* PB8 : PB15 as inputs */
	GPIOC ->CRL = 0x44444444 ; /* PC0 :PB7 as inputs */ 
	GPIOC ->CRH = 0x44444444 ; /* PC8 : PB15 as inputs */
}
void notas(int oitava){
	if(oitava == 1)
		primeiraOitava();
	if(oitava == 2)
		segundaOitava();
}
void primeiraOitava(){
	if(!(GPIOB ->IDR & (1<<5))){//testa o bit do SW5
		TIM3->ARR = oitava1[0];  
		TIM3->CCER = 0x1 << 8; // enable TIM3
	}else if(!(GPIOB ->IDR & (1<<10))){ //testa o bit do SW13
		TIM3->ARR = oitava1[1]; 
		TIM3->CCER = 0x1 << 8; // enable TIM3
	}else	if(!(GPIOB ->IDR & (1<<4))){ //testa o bit do SW6
		TIM3->ARR = oitava1[2]; 
		TIM3->CCER = 0x1 << 8; // enable TIM3 
	}else	if(!(GPIOA ->IDR & (1<<7))){ //testa o bit do SW14 
		TIM3->ARR = oitava1[3]; 
		TIM3->CCER = 0x1 << 8; // enable TIM3 
	}else	if(!(GPIOB ->IDR & (1<<3))){ //testa o bit do SW7
		TIM3->ARR = oitava1[4]; 
		TIM3->CCER = 0x1 << 8; // enable TIM3 
	}else if(!(GPIOA ->IDR & (1<<3))){ //testa o bit do SW8 
		TIM3->ARR = oitava1[5]; 
		TIM3->CCER = 0x1 << 8; // enable TIM3 
	}else if(!(GPIOC ->IDR & (1<<15))){ //testa o bit do SW15
		TIM3->ARR = oitava1[6]; 
		TIM3->CCER = 0x1 << 8; // enable TIM3 
	}else if(!(GPIOA ->IDR & (1<<4))){ //testa o bit do SW9
		TIM3->ARR = oitava1[7]; 
		TIM3->CCER = 0x1 << 8; // enable TIM3 
	}else if(!(GPIOC ->IDR & (1<<14))){ //testa o bit do SW16
		TIM3->ARR = oitava1[8]; 
		TIM3->CCER = 0x1 << 8; // enable TIM3 
	}else if(!(GPIOB ->IDR & (1<<8))){ //testa o bit do SW10
		TIM3->ARR = oitava1[9]; 
		TIM3->CCER = 0x1 << 8; // enable TIM3 
	}else if(!(GPIOC ->IDR & (1<<13))){ //testa o bit do SW17
		TIM3->ARR = oitava1[10];
		TIM3->CCER = 0x1 << 8; // enable TIM3 
	}else if(!(GPIOB ->IDR & (1<<9))){ //testa o bit do SW11
		TIM3->ARR = oitava1[11];
		TIM3->CCER = 0x1 << 8; // enable TIM3 
	}else if(!(GPIOB ->IDR & (1<<11))){ //testa o bit do SW12
		TIM3->ARR = oitava1[12]; 
		TIM3->CCER = 0x1 << 8; // enable TIM3 
	}else{
		TIM3->CCER = 0x1 << 0; // disable TIM3
	}
}

void segundaOitava(){
}
