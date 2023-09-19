#include <Adafruit_NeoPixel.h>

char chr;
uint32_t color = 0;

#define IDLE 0
#define NORMAL 0xff
#define VISUAL 0xffff00
#define SELECT 0xff00ff
#define INSERT 0xffffffff
#define CMD 0xff0000
#define EX 0xff1000
#define TERMINAL 0x00ff00

Adafruit_NeoPixel strip(1, 6, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  strip.begin();
  strip.show();
  strip.setBrightness(50);
  

}

void loop() {
  

    if (Serial.available())
    {
        chr = Serial.read();

        switch (chr) {
          case '0':
            color = IDLE;
            break;
          case '1':
            color = NORMAL;
            break;
          case '2':
            color = VISUAL;
            break;
          case '3':
            color = SELECT;
            break;
          case '4':
            color = INSERT;
            break;
          case '5':
            color = CMD;
            break;
          case '6':
            color = EX;
            break;
          case '7':
            color = TERMINAL;
            break;
          default:
            break;
        }
        strip.setPixelColor(0, color);
        strip.show();
    }

}
