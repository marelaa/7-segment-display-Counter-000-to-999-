#include <xc.h>
#define _XTAL_FREQ 4000000  
#define k RB0 // k is a switch if k=0 the switch is closed             

//  7 segment display(format common anode)
unsigned char list[10] = {0x7E, 0x0C, 0xB6, 0x9E, 0xCC, 0xDA, 0xF8, 0x0E, 0xFE, 0xCE};
unsigned int compt,i ;     
void Init() {
    TRISB = 0x01;   // RB0 input, RBi output
    PORTB = 0x00;   
    TRISC = 0x00;   // PORTC output to control digits
    PORTC = 0x00;
}

void display(unsigned int number) {
    unsigned char hundreds = number / 100;
    unsigned char tens = (number / 10) % 10;
    unsigned char units= number % 10;
    
    RC1=1;
    RC2=1;
    PORTB = list[hundreds];
    RC0=0;
    __delay_ms(1);

    RC0=1;
    RC2=1;
    PORTB = list[tens];
    RC1=0;; // activate the digit of tens
    __delay_ms(1);
    RC1=1;
    RC0=1;
    PORTB = list[units];
    RC2=0; // Activate the digit of units
    __delay_ms(1);
}

void main() {
    Init();  
    
    while(1) {
        if(k==0)
        {
         {for(i=0;i<251;i++)
           {display(compt);}
		 }
          if(k==1) 
              {while(k==1)
              {display(compt);}
              compt++;}
		}
				}
}
				
        
         
        
       
        
            
       
    
