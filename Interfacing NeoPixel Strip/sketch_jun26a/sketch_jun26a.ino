#include <Adafruit_NeoPixel.h>

#define PIN 2
#define N_LEDS 4

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

void setup(){
  strip.begin();
}

void loop(){
  chase(strip.Color(255, 0, 0));//RED
  chase(strip.Color(0, 255, 0));//GREEN
  chase(strip.Color(0, 0, 255));//BLUE
}

static void chase(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels()+4; i++) {
    strip.setPixelColor(i , c);
    strip.setPixelColor(i-4 , 0);
    strip.show();
    delay(25);
  }
}