int j;

int settings() {
  lcd.clear();
  // put your main code here, to run repeatedly:
  int a = digitalRead(button_up);
  if (a == 1) {
    j = j + 1;
    lcd.setCursor(0,0);
    lcd.print("Set Hour");
    Serial.println(j);
    lcd.setCursor(0,1);
    lcd.print(j);
    delay(300);
  }

  int b = digitalRead(button_down);
  if (b == 1) {
    j = j - 1;
    Serial.println(j);
    lcd.setCursor(0,0);
    lcd.print("Set Hour");
    lcd.setCursor(0,1);
    lcd.print(j);
     if(j == -1){
      lcd.setCursor(0,1);
      lcd.print("Invalid Hours");
    }
    delay(300);
  }
  if(j==12){
   j = 0;
  }
   if(j <= -1){
     j = 0;
  }
  return j;
}
