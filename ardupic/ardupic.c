#include "C:\Users\agustin\Documents\Youngg board\ardupic\ardupic.h"
  #ZERO_RAM

int puto; 
void main()
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
   
   while(true)
 {
  puto = input(PIN_B0);
  if(puto == 1)
  {
   output_high(PIN_A0);
  /* delay_ms(500); 
   output_low(PIN_A0);
   delay_ms(500);*/
  }
   else
   {
    output_low(PIN_A0);
    //esewey
   }
 }
}
