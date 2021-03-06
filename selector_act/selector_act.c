#include "C:\Users\agustin\Documents\Youngg board\selector_act\selector_act.h"
  #ZERO_RAM
  int boton; 
  int b1,b2;
  void config();
  void code();
#int_EXT
void  EXT_isr(void) 
{
   boton++;
  
   if(boton==3)
   {
     boton=0;
   }
   clear_interrupt(INT_EXT);
}
void main()
{
  config(); 
  code();
}
void config()
{

   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_CLOCK_DIV_2);
   setup_psp(PSP_DISABLED);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);
   enable_interrupts(INT_EXT);
   enable_interrupts(GLOBAL);

   // TODO: USER CODE!!
} 
void code()
{
  while(true)
  {
    b1 = input(PIN_B1);
    b2 = input(PIN_B2); 
    switch(boton)
    {
     case 0:
     lcd_init();
     lcd_gotoxy(1,1);
     printf(lcd_putc,"Iniciar comandos");
     lcd_gotoxy(1,2);
     printf(lcd_putc,"Youngg Board");
     if(b1 == 1)
     {
      output_low(PIN_A0);
     }
     if(b2 == 1)
     {
      output_low(PIN_A1);
     }
     break;
     case 1:
      lcd_init();
       lcd_gotoxy(3,1);
       printf(lcd_putc,"Comando 1"); 
       lcd_gotoxy(3,2);
       printf(lcd_putc,"Encender leds");
     if(b1 == 1)
     {
      output_high(PIN_A0);
     }
     else{ output_low(PIN_A0);}
     if(b2 == 1)
     {
      output_high(PIN_A1);
     }
      else{ output_low(PIN_A1);}
     break;
      case 2: 
      lcd_init();
       lcd_gotoxy(3,1);
       printf(lcd_putc,"Comando 2"); 
       lcd_gotoxy(3,2);
       printf(lcd_putc,"Parpadear leds");
      if(b1 == 1)
     {
      output_high(PIN_A0);
      delay_ms(500); 
      output_low(PIN_A0);
      delay_ms(500);
     }
     if(b2 == 1)
     {
      output_high(PIN_A1);
      delay_ms(500); 
      output_low(PIN_A1);
      delay_ms(500);
     }
     break;
     default: 
     output_low(PIN_A0);
     output_low(PIN_A1);
    }
  }
}
