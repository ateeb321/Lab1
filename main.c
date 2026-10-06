/************************************
 * #pragma directives...
************************************/
#pragma config FEXTOSC = HS
#pragma config RSTOSC = EXTOSC_4PLL 
#pragma config WDTE = OFF        

/************************************
 * #include directives...
 ************************************/
#include <xc.h>

/************************************
 * #define directives...
 ************************************/
#define _XTAL_FREQ 64000000 

/************************************
/ main function
 * ...
************************************/
void main(void) {    
    // setup pin for output (connected to LED)
    LATDbits.LATD7=0;   //set initial output state for LED 1 (off))
    TRISDbits.TRISD7=0; //set TRIS value for pin 1 (making it an output pin)
    LATHbits.LATH3=1;   //set initial output state for LED 2 (on)
    TRISHbits.TRISH3=0; //set TRIS value for pin 2 (making it an output pin)
    
    // setup pin for input (connected to button)
    TRISFbits.TRISF2=1;   //set TRIS value for pin 1 (making it an input pin)
    ANSELFbits.ANSELF2=0; //turn off analogue input on pin 1 
    TRISFbits.TRISF3=1;   //set TRIS value for pin 2 (making it an input pin)
    ANSELFbits.ANSELF3=0; //turn off analogue input on pin 2
    
    while (1) { //infinite while loop - repeat forever
        
        while (PORTFbits.RF2 && PORTFbits.RF3); //empty while loop (wait for either button press)
        
        if (!PORTFbits.RF2)
            LATDbits.LATD7 = !LATDbits.LATD7; //toggle LED 1
        
        else if (!PORTFbits.RF3)
            LATHbits.LATH3 = !LATHbits.LATH3; //toggle LED 2
        
        __delay_ms(200); // call built in delay function 
    }
}