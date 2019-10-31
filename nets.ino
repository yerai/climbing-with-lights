#include <FastLED.h>

// Bottom
#define LED_PIN_1 7
#define NUM_LEDS_1 50
CRGB leds_1[NUM_LEDS_1];

// Middle
#define LED_PIN_2 8
#define NUM_LEDS_2 39
CRGB leds_2[NUM_LEDS_2];

// Top
#define LED_PIN_3 9
#define NUM_LEDS_3 29
CRGB leds_3[NUM_LEDS_3];

const int flexPin_0 = A0; // Blue - TOP
const int flexPin_1 = A1; // Black - BOTTOM CABLE
const int flexPin_2 = A2; // Brown - MIDDLE NON CABLE
const int flexPin_3 = A3; // Orange - MIDDLE CABLE
const int flexPin_4 = A4; // Yellow - BOTTOM NON CABLE

int value_0;
int value_1;
int value_2;
int value_3;
int value_4;

char sounds[5] = {'0', '0', '0', '0', '0'};

int usingIt;


void setup(){

  FastLED.addLeds<WS2812, LED_PIN_1, GRB>(leds_1, NUM_LEDS_1);
  FastLED.addLeds<WS2812, LED_PIN_2, GRB>(leds_2, NUM_LEDS_2);
  FastLED.addLeds<WS2812, LED_PIN_3, GRB>(leds_3, NUM_LEDS_3);
  Serial.begin(9600);      

}

void loop(){

    // TOP PURPLE
    value_0 = analogRead(flexPin_0);
    //Serial.println(value_0);
    if(value_0 > 600){
      for (int i = 0; i < 29; i++) {
        leds_3[i] = CRGB (138,43,226); //PURPLE
        FastLED.show(); 
       }
      sounds[0]='1';
    }else{
      for (int i = 0; i < 29; i++) {
        leds_3[i] = CRGB ( 0, 0, 0);
        FastLED.show();
       }
      sounds[0]='0';
    }

    // BOTTOM CABLE YELLOW
    value_1 = analogRead(flexPin_1);
    //Serial.println(value_1);
    if(value_1 > 490){
      for (int i = 0; i < 25; i++) {
        leds_1[i] = CRGB (255,255,0); //YELLOW
        FastLED.show(); 
       }
      sounds[1]='1';
    }else{
      for (int i = 0; i < 25; i++) {
        leds_1[i] = CRGB (0, 0, 0);
        FastLED.show();
       }
      sounds[1]='0';
    }

    // MIDDLE NONCABLE RED
    value_2 = analogRead(flexPin_2);
    //Serial.println(value_2);
    if(value_2 > 700){
      for (int i = 20; i < 39; i++) {
        leds_2[i] = CRGB (255,0,0); //RED
        FastLED.show(); 
       }
      sounds[2]='1';
    }else{
      for (int i = 20; i < 39; i++) {
        leds_2[i] = CRGB (0, 0, 0);
        FastLED.show();
       }
      sounds[2]='0';
    }

    // MIDDLE CABLE BLUE
    value_3 = analogRead(flexPin_3);
    //Serial.println(value_3);
    if(value_3 > 610){
      for (int i = 0; i < 20; i++) {
        leds_2[i] = CRGB (30,144,255); //BLUE
        FastLED.show(); 
       }
      sounds[3]='1';
    }else{
      for (int i = 0; i < 20; i++) {
        leds_2[i] = CRGB (0, 0, 0);
        FastLED.show();
       }
      sounds[3]='0';
    }

    // BOTTOM NONCABLE GREEN
    value_4 = analogRead(flexPin_4);
    //Serial.println(value_4);
    if(value_4 > 785){
      for (int i = 25; i < 50; i++) {
        leds_1[i] = CRGB (0,128,0); //GREEN
        FastLED.show(); 
       }
      sounds[4]='1';
    }else{
      for (int i = 25; i < 50; i++) {
        leds_1[i] = CRGB (0, 0, 0);
        FastLED.show();
       }
      sounds[4]='0';
    }

  

  Serial.println(sounds);

  if(sounds[0]=='0' && sounds[1]=='0' && sounds[2]=='0' && sounds[3]=='0' && sounds[4]=='0'){

    leds_1[random(0,49)] = CRGB (random(0,255),random(0,255),random(0,255));
    leds_1[random(0,49)] = CRGB (random(0,255),random(0,255),random(0,255));
    leds_1[random(0,49)] = CRGB (random(0,255),random(0,255),random(0,255));
    leds_1[random(0,49)] = CRGB (random(0,255),random(0,255),random(0,255));
    leds_2[random(0,38)] = CRGB (random(0,255),random(0,255),random(0,255));
    leds_2[random(0,38)] = CRGB (random(0,255),random(0,255),random(0,255));
    leds_2[random(0,38)] = CRGB (random(0,255),random(0,255),random(0,255));
    leds_2[random(0,38)] = CRGB (random(0,255),random(0,255),random(0,255));
    leds_3[random(0,28)] = CRGB (random(0,255),random(0,255),random(0,255));
    leds_3[random(0,28)] = CRGB (random(0,255),random(0,255),random(0,255));
    leds_3[random(0,28)] = CRGB (random(0,255),random(0,255),random(0,255));
    leds_3[random(0,28)] = CRGB (random(0,255),random(0,255),random(0,255));
    FastLED.show(); 

    delay(100);
    
    
   }

     
 
   delay(100);                   //Small delay
  
}
