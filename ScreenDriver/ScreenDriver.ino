#include <Arduino.h>

#include "FastArduino.h"

#define CLK 6
#define CS 5
#define DIN 4

#define CLK_HIGH (PORTD |= (1 << CLK)) //equal to digitalWrite(CLK,HIGH) but faste
#define CLK_LOW (PORTD &= ~(1 << CLK)) //equal to digitalWrite(CLK,LOW) but faster
#define CS_HIGH (PORTD |= (1 << CS))
#define CS_LOW (PORTD &= ~(1 << CS))
//typedef uint8_t PROGMEM prog_uint8_t;

// store in program memory
uint8_t NormalOp[2] = {B00001111, B00000000};
uint8_t DisplayTest[2] = {B00001111, B00000001};
uint8_t IntensityMax[2] = {0, 0};
uint8_t IntensityMed[2] = {0, 0};
uint8_t IntensityMin[2] = {0, 0};
uint8_t Test[16][2] =
    {
        {B00000001, B10000000},
        {B00000000, B00000000},
        {B00000000, B00000000},
        {B00000000, B00000000},
        {B00000000, B00000000},
        {B00000000, B00000000},
        {B00000000, B00000000},
        {B00000000, B00000000},
        {B00000000, B00000000},
        {B00000000, B00000000},
        {B00000000, B00000000},
        {B00000000, B00000000},
        {B00000000, B00000000},
        {B00000000, B00000000},
        {B00000000, B00000000},
        {B10000000, B00000001}};

void setup()
{
  // initialize digital pin LED_BUILTIN as an output.
  pinAsOutput(CLK);
  pinAsOutput(CS);
  pinAsOutput(DIN);

  digitalLow(CLK);
  digitalLow(CS);
  digitalLow(DIN);

  Serial.begin(9600);
  initialize();
}

void initialize()
{
  CS_LOW;
  shiftOutByte(NormalOp, 2);
  shiftOutByte(NormalOp, 2);
  shiftOutByte(NormalOp, 2);
  shiftOutByte(NormalOp, 2);
  CS_HIGH;

  delay(1000);

  CS_LOW;
  shiftOutByte(DisplayTest, 2);
  shiftOutByte(DisplayTest, 2);
  shiftOutByte(DisplayTest, 2);
  shiftOutByte(DisplayTest, 2);
  CS_HIGH;

  delay(1000);

  CS_LOW;
  shiftOutByte(NormalOp, 2);
  shiftOutByte(NormalOp, 2);
  shiftOutByte(NormalOp, 2);
  shiftOutByte(NormalOp, 2);
  CS_HIGH;
}

void loop()
{
}

void setIntensity(int i)
{
}

void shiftOutByte(uint8_t *data, uint8_t size)
{
  for (uint8_t i = 0; i < size; i++)
  {
    for (uint8_t j = 8; j > 0; j--)
    {
      CLK_LOW;

      if (data[i] & (1 << (j - 1)))
      {
        digitalHigh(DIN);
      }
      else
      {
        digitalLow(DIN);
      }
      CLK_HIGH;
    }
  }
}
