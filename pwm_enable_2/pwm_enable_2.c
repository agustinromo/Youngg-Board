#include "C:\Users\VAIOPC\Documents\ADATA\Adquisicion\Youngg board\pwm_enable_2\pwm_enable_2.h"
  #ZERO_RAM

int16 pot=0; 
int8 boton,boton2=0;
int Timer2,Poscaler;
void main()
{
   Timer2=249;
   Poscaler=1; 
   setup_timer_2(T2_DIV_BY_16,255,1);    // 819 us overflow 
   setup_ccp1(ccp_pwm); 
   setup_ccp2(ccp_pwm); 
   set_pwm1_duty(0);        
   set_pwm2_duty(0);
   setup_adc_ports(all_analog);
   setup_adc(adc_clock_internal);

   // TODO: USER CODE!! 
   while(true){ 
 boton = input(PIN_B0);
 boton2 = input(PIN_B1);
 if(boton == 1 && boton2 == 0 )
 { 
  set_adc_channel(0); 
  delay_us(100); 
  pot=read_adc(); 
  set_pwm2_duty(pot); 
  output_high(PIN_C4);
  output_low(PIN_C5); 
  lcd_gotoxy(3,1);
       printf(lcd_putc," ");
 } 
  if(boton2 == 1 && boton == 0 )
  { 
   set_adc_channel(0); 
   delay_us(100); 
   pot=read_adc(); 
   set_pwm2_duty(pot); 
   output_high(PIN_C4); 
   output_low(PIN_C5); 
   lcd_gotoxy(3,1);
       printf(lcd_putc," ");
   }  
   if(boton == 0 && boton2 == 0) 
   {
    set_pwm2_duty(0);
    output_low(PIN_C4); 
    output_low(PIN_C5); 
    lcd_init();
       lcd_gotoxy(3,1);
       printf(lcd_putc," "); 
   } 
    if(boton == 1 && boton2 == 1) 
   {
    set_pwm2_duty(0);
    output_low(PIN_C4); 
    output_low(PIN_C5); 
     lcd_init();
       lcd_gotoxy(3,1);
       printf(lcd_putc,"ey ey ey"); 
       lcd_gotoxy(3,2);
       printf(lcd_putc,"calmado PUTO");
   }
 } 
 } 

