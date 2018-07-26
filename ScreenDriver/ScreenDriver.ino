#include <Arduino.h>
#define CLK 6
#define CS 5
#define DIN 4

const prog_uint8_t NormalOp[2] = {B00001111,B00000000}; // store in program memory

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  //pinMode(CLK, OUTPUT);
  //pinMode(CS,OUTPUT);
  //pinMode(DIN,OUTPUT);
  DDRD = DDRD | B01110000; //seting CLK, CS and DIN as OUTPUT and leaving the rest untouch
  PORTD = PORTD | B00000000; //seting all of port d to LOW
}

void initialize(){

}

void setIntensity(int i){

}

void shiftOutByte(byte b){

}

