#define portOfPin(P)\
  (((P)>=0&&(P)<8)?&PORTD:(((P)>7&&(P)<14)?&PORTB:&PORTC))
#define ddrOfPin(P)\
  (((P)>=0&&(P)<8)?&DDRD:(((P)>7&&(P)<14)?&DDRB:&DDRC))
#define pinOfPin(P)\
  (((P)>=0&&(P)<8)?&PIND:(((P)>7&&(P)<14)?&PINB:&PINC))
#define pinIndex(P)((uint8_t)(P>13?P-14:P&7))
#define pinMask(P)((uint8_t)(1<<pinIndex(P)))

#define pinAsInput(P) *(ddrOfPin(P))&=~pinMask(P)
#define pinAsInputPullUp(P) *(ddrOfPin(P))&=~pinMask(P);digitalHigh(P)
#define pinAsOutput(P) *(ddrOfPin(P))|=pinMask(P)
#define digitalLow(P) *(portOfPin(P))&=~pinMask(P)
#define digitalHigh(P) *(portOfPin(P))|=pinMask(P)
#define isHigh(P)((*(pinOfPin(P))& pinMask(P))>0)
#define isLow(P)((*(pinOfPin(P))& pinMask(P))==0)
#define digitalState(P)((uint8_t)isHigh(P))


// Thus, you can save valuable code space and get dramatically faster execution by changing:
// pinMode( pin, INPUT ); with pinAsInput( pin );
// pinMode( pin, OUTPUT ); with pinAsOutput( pin );
// pinMode( pin, INPUT_PULLUP); with pinAsInputPullUp( pin );
// digitalWrite( pin, LOW ); with digitalLow( pin );
// digitalWrite( pin, HIGH ); with digitalHigh( pin );
// digitalRead( pin ) with digitalState( pin )

// Additionally, rather than typing if( digitalState( pin ) == HIGH ) you can type if( isHigh( pin ) ) for clearer code clarity. Also use isLow( pin ) rather than digitalState( pin ) == LOW.

// Now let's try it in action. Load the Blink.pde example sketch and try to compile. You'll get 1,084 bytes of compiled code. Now insert our new macros in the beginning of the file, and replace the code according to
// changing guide above.

// Your source code will be like this (comments removed, newly inserted macros are not shown):

// #define led 13;

// void setup() {              
//   pinAsOutput(led);
// }

// void loop() {
//   digitalHigh( led );
//   delay( 1000 );
//   digitalLow( led );
//   delay( 1000 );
// }