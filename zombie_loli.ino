#include <Adafruit_GFX.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
#include <SPI.h>
#include <Adafruit_ILI9341.h>
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#define TFT_CLK 13
#define TFT_MISO 12
#define TFT_MOSI 11
#define TFT_DC 10
#define TFT_CS 8
#define TFT_RST 9

static const unsigned char PROGMEM girl[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x03, 0xfe, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x20, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x20, 0x3f, 0xff, 0xe0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x20, 0xfb, 0xb6, 0xf0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x21, 0xff, 0xdf, 0xf8, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x6f, 0xf7, 0xff, 0x7c, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xff, 0xef, 0xbf, 0xee, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xdf, 0x5f, 0xff, 0xfe, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xf6, 0xfd, 0xdf, 0xbf, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xff, 0xed, 0xf6, 0xfd, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x6e, 0xff, 0xef, 0xfd, 0x80, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xbf, 0x6d, 0xbd, 0xdf, 0x80, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xfa, 0xfd, 0xef, 0xfe, 0xe0, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xed, 0xff, 0xfe, 0xb7, 0xf0, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xff, 0xfa, 0xb7, 0xff, 0xf0, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xec, 0x7f, 0xdb, 0xbf, 0xf8, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xef, 0x9f, 0xfe, 0xf7, 0xf8, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xfb, 0xdf, 0xff, 0xbd, 0xf8, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xe7, 0x6e, 0xfe, 0xff, 0x70, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xff, 0xff, 0x80, 0xb5, 0xf0, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xfb, 0xfb, 0xbf, 0xfe, 0xc0, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xfd, 0xef, 0xef, 0x77, 0x40, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xbf, 0xfb, 0xf3, 0xdb, 0xa0, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xff, 0xf6, 0xff, 0xfa, 0xd0, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xbf, 0xff, 0xff, 0x6b, 0xc8, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xcf, 0x7b, 0xfb, 0xfa, 0xc0, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xcb, 0xdf, 0xed, 0x6b, 0xe0, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xd7, 0x95, 0x20, 0x70, 0xe0, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x43, 0x3b, 0xd4, 0xf9, 0xe0, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x01, 0x4b, 0xa9, 0xf9, 0xa0, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0xa4, 0x8f, 0xd9, 0xe0, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x01, 0x3a, 0xbf, 0xf8, 0xe0, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x02, 0x41, 0x1f, 0xfb, 0xa0, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0xa6, 0x5f, 0xf2, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x02, 0x89, 0x2f, 0xf0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0xa5, 0x2e, 0xe0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x02, 0x44, 0x97, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x12, 0x21, 0x80, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x80, 0x0a, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x89, 0x50, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x02, 0x40, 0x28, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x14, 0x44, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x05, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x0a, 0x44, 0x40, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x01, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x08, 0x44, 0x20, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x05, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x10, 0x44, 0x80, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x05, 0x10, 0x40, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x45, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x15, 0x10, 0x40, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x45, 0x10, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x05, 0x10, 0x40, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x20, 0x45, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x0a, 0x10, 0x50, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x41, 0x45, 0x08, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x11, 0x42, 0xa0, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x01, 0x51, 0xc0, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0xef, 0xb0, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x5e, 0xf4, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x71, 0x5c, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x58, 0x36, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x38, 0x3c, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x30, 0x24, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x1c, 0x1c, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x1e, 0x38, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x0e, 0x28, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x0e, 0x10, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


const int debounceDelay= 10 ;
const int buttonAPin = 2; //將A鍵的Pin設在2
const int buttonBPin = 3; //將B鍵的Pin設在3
const int buttonCPin = 4; //將C鍵的Pin設在4
boolean  buttonState[3];
volatile boolean buttonAState = HIGH;  //宣告A鍵狀態變數，因為是在中斷程式中被更新的變數，所以在前面加上volatile
volatile boolean buttonBState = HIGH;  //宣告B鍵狀態變數，因為是在中斷程式中被更新的變數，所以在前面加上volatile
volatile boolean buttonCState = HIGH;  //宣告C鍵狀態變數，因為是在中斷程式中被更新的變數，所以在前面加上volatile

int divide=4;
int one_or_two;
bool states[4][3];
uint16_t color_states[4][3];
uint16_t color[10]={ILI9341_YELLOW,ILI9341_PURPLE,ILI9341_RED,ILI9341_YELLOW,ILI9341_ORANGE,ILI9341_GREEN,ILI9341_WHITE,ILI9341_BLUE|ILI9341_GREEN,ILI9341_ORANGE|ILI9341_YELLOW,ILI9341_YELLOW|ILI9341_PURPLE};
int zombie_state;  //0~2代表zombie現在在第幾個位置

const int speakerPin = 6;
unsigned int speed = 1000;
int jumpdelay=20;

int score;
int gametime=30; //遊戲時間限制

unsigned long startTime ;
unsigned long currentTime ;
int timeElapsed ;

unsigned long previousMillis = 0;
const long interval = 1000;

bool tag=true;


//建立LCD class
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

float jumproad[5]={2.9,2.8,2.7,2.6,2.5};//設定彈跳路徑

bool debounce(int pin){  
  bool state;
  bool previousState;
  previousState = digitalRead(pin);  //記錄開關狀態
  for(int counter=0 ; counter<debounceDelay ; counter++){  //設定連續幾次檢查，狀態都不變
    delay(1);   //等1毫秒
    state = digitalRead(pin);  //讀取
    if(state != previousState){  
      counter = 0;     //如果狀態變化，重設counter
      previousState = state;   //儲存當下狀態
    }
  }
  return state;   //當開關狀態穩定超過debounce period , 即回傳
}
//消除音符
void clearNote( int x , int y) { 
    tft.drawBitmap((y+1)*(tft.width()/divide)-40,(x)*tft.height()/divide-40,girl,80,80,ILI9341_BLACK);
    //tft.drawRect( x*(tft.width()/8) + 20/2, tft.height()/2-60, 11, 60,  ILI9341_BLACK);
}

//顯示音符，可藉由參數來設定為藍色或是紅色
void ShowNote( int x , int y, uint16_t color ){
    tft.drawBitmap((y+1)*(tft.width()/divide)-40,(x)*tft.height()/divide-40,girl,80,80,color);
    //tft.drawRect( x*(tft.width()/8) + 20/2, tft.height()/2-60, 11, 60,  color);
}

void clearJumpNoteNote( float x , float y) { 
    tft.drawBitmap((y+1)*(tft.width()/divide)-40,(x)*tft.height()/divide-40,girl,80,80,ILI9341_BLACK);
    //tft.drawRect( x*(tft.width()/8) + 20/2, tft.height()/2-60, 11, 60,  ILI9341_BLACK);
}

void ShowJumpNote( float x , float y, uint16_t color ){
    tft.drawBitmap((y+1)*(tft.width()/divide)-40,(x)*tft.height()/divide-40,girl,80,80,color);
    //tft.drawRect( x*(tft.width()/8) + 20/2, tft.height()/2-60, 11, 60,  color);
}

void NoteJump(int zombie_state , uint16_t color){
        if(zombie_state==0){
            clearJumpNoteNote(3,zombie_state); delay(jumpdelay);for(int j=0;j<=2;j++){if(states[2][j]==true){ShowNote(2,j,color);}}

          for(int i=0; i<=4 ;i++){
             ShowJumpNote(jumproad[i],zombie_state,color);delay(jumpdelay);
             clearJumpNoteNote(jumproad[i],zombie_state);delay(jumpdelay);for(int j=0;j<=2;j++){if(states[2][j]==true){ShowNote(2,j,color);}}
          }
          for(int i=3; i>=0 ;i--){
             ShowJumpNote(jumproad[i],zombie_state,color);delay(jumpdelay);
             clearJumpNoteNote(jumproad[i],zombie_state);delay(jumpdelay);for(int j=0;j<=2;j++){if(states[2][j]==true){ShowNote(2,j,color);}}
          }
          ShowJumpNote(3,zombie_state,color);delay(jumpdelay);           
                                          
          }
    else if(zombie_state==1){
      clearJumpNoteNote(3,zombie_state); delay(jumpdelay);for(int j=0;j<=2;j++){if(states[2][j]==true){ShowNote(2,j,color);}}

          for(int i=0; i<=4 ;i++){
             ShowJumpNote(jumproad[i],zombie_state,color);delay(jumpdelay);
             clearJumpNoteNote(jumproad[i],zombie_state);delay(jumpdelay);for(int j=0;j<=2;j++){if(states[2][j]==true){ShowNote(2,j,color);}}
          }
          for(int i=3; i>=0 ;i--){
             ShowJumpNote(jumproad[i],zombie_state,color);delay(jumpdelay);
             clearJumpNoteNote(jumproad[i],zombie_state);delay(jumpdelay);for(int j=0;j<=2;j++){if(states[2][j]==true){ShowNote(2,j,color);}}
          }
          ShowJumpNote(3,zombie_state,color);delay(jumpdelay);
                                              
          }
    else if(zombie_state==2){
      clearJumpNoteNote(3,zombie_state); delay(jumpdelay);for(int j=0;j<=2;j++){if(states[2][j]==true){ShowNote(2,j,color);}}

          for(int i=0; i<=4 ;i++){
             ShowJumpNote(jumproad[i],zombie_state,color);delay(jumpdelay);
             clearJumpNoteNote(jumproad[i],zombie_state);delay(jumpdelay);for(int j=0;j<=2;j++){if(states[2][j]==true){ShowNote(2,j,color);}}
          }
          for(int i=3; i>=0 ;i--){
             ShowJumpNote(jumproad[i],zombie_state,color);delay(jumpdelay);
             clearJumpNoteNote(jumproad[i],zombie_state);delay(jumpdelay);for(int j=0;j<=2;j++){if(states[2][j]==true){ShowNote(2,j,color);}}
          }
          ShowJumpNote(3,zombie_state,color);delay(jumpdelay);
                                                  
    }
}

void all_circle_print(){
  for(int i=0;i<=3;i++){
          for(int j=0;j<=2;j++){
            if(states[i][j]==false){clearNote(i,j);}
          }
         }
         for(int i=0;i<=3;i++){
          for(int j=0;j<=2;j++){
            if(states[i][j]==true){ShowNote(i,j,color[score/10]);}
          }
         }
}

void final_show_score(int score){
  tft.setTextColor(ILI9341_RED);
              tft.setCursor(20, tft.height()/2);
              tft.setTextSize(4);
              tft.println("Time Out");
              delay(2000);
  tft.fillScreen(ILI9341_BLACK);
      for(int i=0; i<=5 ;i++){
          tft.setTextColor(color[score/10]);
          tft.setCursor(1, tft.height()/4);
          tft.setTextSize(3);
          tft.println("the score is");
          if(score>=10){tft.setCursor(tft.width()/2-60, tft.height()/2);}
          else{tft.setCursor(tft.width()/2-30, tft.height()/2);}
          tft.setTextSize(10);
          tft.println(score);
          delay(300);
          tft.setTextColor(ILI9341_BLACK);
          if(score>=10){tft.setCursor(tft.width()/2-60, tft.height()/2);}
          else{tft.setCursor(tft.width()/2-30, tft.height()/2);}
          tft.setTextSize(10);
          tft.println(score);
          delay(300);
      }
          //消掉"the score"
          tft.setTextColor(ILI9341_BLACK);
          tft.setCursor(1, tft.height()/4);
          tft.setTextSize(3);
          tft.println("the score is");
        
          //顯示"press A continue"
          tft.setTextColor(ILI9341_WHITE);//
          tft.setTextSize(2);
          tft.setCursor(1, tft.height()/2);
          tft.println("  press A continue");
}

void showTime(){
  tft.fillRect(1, tft.height()-30,30,30,ILI9341_BLACK);
              
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.setCursor(1, tft.height()-30);
  tft.println(gametime-timeElapsed);
}

void showScore(){
  tft.setTextColor(ILI9341_BLACK);
  tft.setTextSize(2);
  tft.setCursor(tft.width()-30, tft.height()-30);
  tft.println(score-1);
              
  tft.setTextColor(color[(score)/10]);
  tft.setTextSize(2);
  tft.setCursor(tft.width()-30, tft.height()-30);
  tft.println(score);
}

void setup() {
  Serial.begin(9600);
  pinMode(buttonAPin,INPUT);
  pinMode(buttonBPin,INPUT);
  pinMode(speakerPin,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(buttonAPin),Apress,FALLING); //buttonAPin為負緣觸發，並執行Apress()
  attachInterrupt(digitalPinToInterrupt(buttonBPin),Bpress,FALLING); //buttonBPin為負緣觸發，並執行Bpress()
  attachInterrupt(digitalPinToInterrupt(buttonCPin),Cpress,FALLING); //buttonCPin為負緣觸發，並執行Cpress()
  Serial.println("ILI9341 Test!"); 
  tft.begin();//若輸出皆為0x0，請RESET arduino並確認接線是否有誤
  // read diagnostics (optional but can help debug problems)
  uint8_t x = tft.readcommand8(ILI9341_RDMODE);
  Serial.print("Display Power Mode: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDMADCTL);
  Serial.print("MADCTL Mode: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDPIXFMT);
  Serial.print("Pixel Format: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDIMGFMT);
  Serial.print("Image Format: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDSELFDIAG);
  Serial.print("Self Diagnostic: 0x"); Serial.println(x, HEX);
  tft.fillScreen(ILI9341_BLACK);

  tft.setTextSize(5);      //顯示遊戲開始
  tft.setCursor(tft.width()/10, tft.height()/2);			
  tft.setTextColor(ILI9341_PURPLE); 
  tft.println("START!!");
  delay(2000);
  tft.setTextSize(5);      
  tft.setCursor(tft.width()/10, tft.height()/2);	
  tft.setTextColor(ILI9341_BLACK); 
  tft.println("START!!");

  randomSeed(analogRead(0));

  //設定初始狀態
  for(int i=0;i<=3;i++){
      int zero_to_two=random(0,3);
           for(int j=0;j<=2;j++){
             if(j==zero_to_two){states[i][j]=true;}
             else{states[i][j]=false;}
           }       
  }

  for(int j=0;j<=2;j++){//更新僵屍的位置
          if(states[3][j]==true){zombie_state=j;}
         }

  score=0;
  startTime = 0;
  currentTime = 0;
  timeElapsed = 0;
  startTime=millis();
  
  //輸出畫面
  all_circle_print();
  showScore();
}

void loop() {

  if(tag==true){
          currentTime = millis();
          timeElapsed = (currentTime - startTime) / 1000;

        if (timeElapsed <= gametime) {
          if (currentTime - previousMillis >= interval) {
              previousMillis = currentTime;
              showTime();
            }
          
          buttonAState = debounce(buttonAPin); //讀取A鍵狀態
          buttonBState = debounce(buttonBPin); //讀取B鍵狀態
          buttonCState = debounce(buttonCPin); //讀取C鍵狀態

          if(    (buttonAState == LOW && zombie_state==0 ) 
              || (buttonBState == LOW && zombie_state==1 ) 
              || (buttonCState == LOW && zombie_state==2 )   ){//按對按鍵就可以更新
          
              //更新第一行到第三行的狀態
                for(int i=3;i>=1;i--){ 
                  for(int j=2;j>=0;j--){ 
                  states[i][j]=states[i-1][j];
                  color_states[i][j]=color_states[i-1][j];
                  }
                }
                
              //更新第零行的狀態
                int g=random(0,3);
                  for(int j=0;j<=2;j++){
                    if(j==g){states[0][j]=true;}
                    else{states[0][j]=false;}
                  }
                  
                score++;
              //重新輸出畫面
                all_circle_print();
                
                //更新所有按鈕的狀態
                buttonAState=HIGH;
                buttonBState=HIGH;
                buttonCState=HIGH;
                for(int j=0;j<=2;j++){//更新僵屍的位置
                  if(states[3][j]==true){zombie_state=j;}
                }
                
                showScore();
            } 


            if(    (buttonAState == LOW && (zombie_state==1 || zombie_state==2) ) 
                || (buttonBState == LOW && (zombie_state==0 || zombie_state==2) ) 
                || (buttonCState == LOW && (zombie_state==0 || zombie_state==1) )   ){//按錯按鍵會跳跳

                      NoteJump(zombie_state,color[(score)/10]);
                      
            }
          }
        else{
              tag=false;
              final_show_score(score);
          }
     }
     else{
          buttonAState = debounce(buttonAPin); //讀取A鍵狀態
          if(buttonAState==LOW){
            tag=true;
            setup();
          }
     }
     
}

void Apress() {    //按下A鍵時，執行此中斷處理程式，讓buttonAState為LOW，再回loop中進行判斷
     buttonAState=LOW;
}
void Bpress() {    //按下B鍵時，執行此中斷處理程式，讓buttonBState為LOW，再回loop中進行判斷
     buttonBState=LOW;
}
void Cpress() {    //按下C鍵時，執行此中斷處理程式，讓buttonCState為LOW，再回loop中進行判斷
     buttonCState=LOW;
}
