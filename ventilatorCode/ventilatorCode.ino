#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20,20,4); //set up LCD

//pins
const int dirPin = 4; //ctrls direction of motor
const int speedPin = 5; //ctrls speed of motor
const int modePin = 12; //ctrls mode
const int manualPin = 11; //sets push on manual mode
const int airPin = 1; //gets pot 1 setting
const int freqPin = 2; //gets pot 2 setting
const int flowPin = 5; //gets airflow

//constants
int threshold = 210; //airflow threshold
const float delayBetweenInOut = 650; //delay in between breath in and out
const float maxExtention = 2500; //min and max extention of piston (ms)
const float minExtention  = 600; 
const float maxDelay = 2500; //min and max delays between pushes (ms)
const float minDelay = 300;

int mode = 0; //mode, 0 is manual, 1 is timed, 2 is dynamic airflow
bool inPush = false; //is it piushing?
int airTime; //how long to push?
int delayBetweenBreaths; //delay between breaths (for timed)
int air; //airflow
bool calibrated = false;
int loops = 0;

//String modeList = ["MAN", "TIM", "DYN"];

void setup() {

  lcd.init();                      // initialize the lcd 
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Ventilator");
  
  Serial.begin(9600); //debugging
  Serial.println(analogRead(flowPin));
  pinMode(dirPin, OUTPUT); //setting output/input
  pinMode(speedPin, OUTPUT);
  pinMode(modePin, INPUT);
  pinMode(manualPin, INPUT);
  delay(3000);

}

void showData(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("t=");
  lcd.setCursor(2, 0);
  lcd.print(airTime);

  if(mode == 0){
    lcd.setCursor(13, 0);
    lcd.print("MAN");
  
  }else if(mode == 1){
    lcd.setCursor(13, 0);
    lcd.print("AUT");
  }else{
    lcd.setCursor(13, 0);
    lcd.print("DYN");
  }
  
}

void pushIn(int amount){ //for pushing in, and then pulling out
  inPush = true;
  
  
  analogWrite(speedPin, 1023);
  digitalWrite(dirPin, HIGH);
  delay(amount);
  analogWrite(speedPin, 0);
  
  delay(delayBetweenInOut);

  analogWrite(speedPin, 1023);
  digitalWrite(dirPin, LOW);
  delay(amount);
  analogWrite(speedPin, 0);
  
  inPush = false;
}

void loop() {
  //sensing potentiometers
  airTime = map(analogRead(airPin), 0, 1023, minExtention, maxExtention);
  delayBetweenBreaths = map(analogRead(freqPin), 0, 1023, minDelay, maxDelay);
  
 if(mode == 0){ //manual mode
    loops = 0;
    showData();
    if(!inPush){
      if(digitalRead(manualPin)){
        lcd.setCursor(2, 1);
        lcd.print("COMPRESSING");
        pushIn(airTime);
      }
    }
    
  }else if(mode == 1){ //timed mode 
    loops++;
    showData();      
    lcd.setCursor(6, 0);
    lcd.print("d=");
    lcd.setCursor(8, 0);
    lcd.print(delayBetweenBreaths);
    
    if(!inPush && loops > 2){
      lcd.setCursor(2, 1);
      lcd.print("COMPRESSING");
      pushIn(airTime);

      showData();      
      lcd.setCursor(6, 0);
      lcd.print("d=");
      lcd.setCursor(8, 0);
      lcd.print(delayBetweenBreaths);


      
    }
    delay(delayBetweenBreaths);
    
  }else if(mode == 2){ //dynamic airflow mode
    loops = 0;
    air = analogRead(flowPin);
    showData();
    delay(100);
    Serial.println(calibrated);
    if (!calibrated){
      lcd.setCursor(2,1);
      lcd.print("CALIBRATING");
      delay(25000);
      calibrated = true;
      lcd.clear();
    }
    lcd.setCursor(8, 0);
    lcd.print(threshold);
    lcd.setCursor(6, 1);
    lcd.print(air);
    
    if(air > threshold){
      if(!inPush){
        lcd.setCursor(2, 1);
        lcd.print("COMPRESSING");
        pushIn(airTime);
      }
      delay(800);
    }
    
  }
  if(digitalRead(modePin)){
    Serial.println("done");
    mode = mode + 1;
    mode = mode % 3;
    Serial.println(mode);
    
    if(mode == 0){
      lcd.setCursor(13, 0);
      lcd.print("MAN");
    
    }else if(mode == 1){
      lcd.setCursor(13, 0);
      lcd.print("AUT");
    }else{
      lcd.setCursor(13, 0);
      lcd.print("DYN");
    }
    
    delay(1500);
  }
  delay(100);


}
