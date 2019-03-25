#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define mosfet_base 9
#define res1 A0
#define res2 A1
#define res3 A2

float v1;
float v2;
float v3;
boolean discharging =false;
int count=0;
int count1=0;
boolean charged=false;
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  Serial.begin(9600);
  pinMode(mosfet_base,OUTPUT);
  pinMode(res1,INPUT);
  pinMode(res2,INPUT);
  pinMode(res3,INPUT);
  lcd.begin();
  lcd.setCursor(0,0);
  lcd.print(" BATTERY CHARGER ");
  lcd.setCursor(0,1);
  lcd.print(" AND DISCHARGER! ");
  delay(3000);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  battery();
  //delay(100);
  Serial.println("##############");
}
