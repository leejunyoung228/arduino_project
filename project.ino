#include <Adafruit_NeoPixel.h>
#define PIN 3
#define LEDNUM 8
int s = A1;
int n=0;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDNUM, PIN, NEO_GRB + NEO_KHZ800);
#define bu 4
void setup() {
  strip.begin();
  Serial.begin(9600);                                       
}
int r,g,b;
void loop() {
  Serial.println(analogRead(s));
  if(analogRead(s)>=1023&&n==1){
    for(int i=0;i<8;i++){
      strip.setPixelColor(i, 0, 0, 0);
      strip.show();
    }
    n=0;
  }
  if(analogRead(s)>=1023&&n==0){
    r=random(0,255);
    g=random(0,255);
    b=random(0,255);
    for(int i=0;i<8;i++){
      strip.setPixelColor(i, r, g, b);
      strip.show();
    }
    n=1;
  }
  
  if(digitalRead(bu)==HIGH){
      r=random(0,255);
      g=random(0,255);
      b=random(0,255);
    for(int i=0;i<8;i++){
      strip.setPixelColor(i, r, g, b);
      strip.show();
    }
    n=1;
    delay(50);
  }
}
