#include "C:\Users\agustin\Documents\Youngg board\contador\contador.h"
  #ZERO_RAM
int i,j,k;
void config();
void code();
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

   // TODO: USER CODE!!
}
void code()
{
  while(true)
   { 
   for(i=0; i<=23; i++) //hours
    {
     for(j=0;j<=59;j++) //minutes
      {
       for(k=0;k<=59;k++) //seconds
        {
         delay_ms(250); //***
         lcd_init(); 
         lcd_gotoxy(4,2); 
         printf(lcd_putc,"%i/%i/%i",i,j,k); //printing clock 
        }
       } 
     }
  }
}
