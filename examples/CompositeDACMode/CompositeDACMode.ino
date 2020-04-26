//You need to connect a composite TV input cable to the pins specified below.
//cc by-sa 4.0 license
//Martin-Laclaustra
/*
    CONNECTION

    A) voltageDivider = false; B) voltageDivider = true

       55 shades                  179 shades

    ESP32        TV            ESP32                       TV     
    -----+                     -----+    ____ 100 ohm
        G|-                        G|---|____|+          
    pin25|--------- Comp       pin25|---|____|+--------- Comp    
    pin26|-                    pin26|-        220 ohm
         |                          |
         |                          |
    -----+                     -----+                              

    Connect pin 25 or 26
  
    C) R–2R resistor ladder; D) unequal rungs ladder

       55 shades                  up to 254 shades?

    ESP32        TV           ESP32                       TV
    -----+                    -----+    ____ 
        G|-+_____                 G|---|____|
    pinA0|-| R2R |- Comp      pinA0|---|____|+--------- Comp
    pinA1|-|     |            pinA1|---|____|
    pinA2|-|     |              ...|
      ...|-|_____|                 |
    -----+                    -----+

    Connect pins of your choice (A0...A8=any pins).
    Custom ladders can be used by tweaking colorMinValue and colorMaxValue
*/

#include <ESP32Lib.h>
#include <Ressources/Font6x8.h>
#include <Composite/CompMode.h>

//pin configuration for DAC
const int outputPin = 25;

CompositeGrayDAC display;
//CompositeGrayLadder display;

void setup()
{
  //initializing composite at the specified pins
  //output pin and boolean for voltage divider can be omitted
  //see Composite/CompMode.h for other modes
  display.init(CompMode::MODEPAL288P, 25, false);
  //display.init(CompMode::MODEPAL288P, display.XPlayer);

  //selecting the font
  display.setFont(Font6x8);
  //displaying the test pattern
  display.rect(30, 88, 255+5, 40+4, 127);
  for(int x = 0; x < 256; x++)
  {
    display.fillRect(x + 32, 90, 1, 40, x);
    if(x % 16 == 0)
    {
      display.fillRect(x + 32, 85, 1, 4, 255);
      display.setCursor(x + 32 - 3, 78);
      display.print(x,HEX);
    }
  }
}

void loop()
{
}
