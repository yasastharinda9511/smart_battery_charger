void battery(){
  v1=((float(analogRead(res1))/1024)*5)*6.9/3.6;
  v2=((float(analogRead(res2))/1024)*5)*6.9/3.6;
  v3=((float(analogRead(res3))/1024)*5)*4.6/2.6;
  float percentage=(v2-v3)*100/9;
  if(charged and!(v1-v2<0 and (v1-v2)/10<-0.025)){
    lcd.clear();
    Serial.println("charged");
    lcd.setCursor(0,0);
    lcd.print("....Charged....");
    delay(1000);
    return;
    }
  
  if(discharging and percentage<10){
    analogWrite(mosfet_base,0);
    lcd.clear();
    Serial.println("Caution");
    lcd.setCursor(0,1);
    lcd.print("Caution");
    return ;
    }
  if(percentage>=95 and (v1-v2)/10>0.025 ){
    analogWrite(mosfet_base,0);
    Serial.println("charged");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("....Charged....");
    delay(1000);
    charged=true;
    return;
    }
  if (v1-v2<0 and (v1-v2)/10<-0.025 ){
    analogWrite(mosfet_base,255);
    Serial.println("discharging to the load");
    Serial.print("battery percentage:");
    Serial.print((v2-v3)*100/9);
    Serial.println("%");
    Serial.print("current through the battery:");
    Serial.println((v1-v2)/10);
    discharging=true;
    charged=false;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Discharging");
    for(int i=0;i<count;i++){
      lcd.print(".");
      }
    if(count==6){
      count=0;
      }else{
        count=count+1;
        }
     lcd.setCursor(0,1);
     lcd.print("Battery : ");
     lcd.print(int(((v2-v3)*100/9)+8));
     lcd.print(" %");
     delay(1000);
    return;
    }
  if(v1-v2<0){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("....No Load....");
    delay(1000);
    return;
    }
  if(v2-v3<=9 && v1!=0 && v2!=0 && v3!=0){
    analogWrite(mosfet_base,255);
    Serial.println("charging");
    Serial.print("battery voltage:");
    Serial.println(v2-v3);
    Serial.print("current through the battery:");
    Serial.println((v1-v2)/10);
    Serial.print("battery percentage:");
    Serial.print((v2-v3)*100/9);
    Serial.println("%");
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Charging");
    for(int i=0;i<count1;i++){
      lcd.print(".");
      }
    if(count1==9){
      count1=0;
      }else{
        count1=count1+1;
        }
    /*lcd.setCursor(0,1);
    lcd.print("Vol:");
    lcd.print(v2-v3);
    lcd.print("V");

    lcd.print("I:");
    lcd.print((v1-v2)/10);*/
    lcd.setCursor(0,1);
    lcd.print("Battery : ");
    lcd.print(int((v2-v3)*100/9));
    lcd.print(" %");
    delay(1000);
    discharging=false;
    return;
    }
  if(v3==0){
    Serial.println("battery is not connected");
    lcd.clear();
    discharging=false;
    charged=false;
    lcd.setCursor(0,0);
    lcd.print("     Battery      ");
    lcd.setCursor(0,1);
    lcd.print("Is Not Connected");
    delay(2000);
    return ;
    }
  }
