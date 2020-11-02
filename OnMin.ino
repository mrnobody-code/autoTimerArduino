int i;

int mint() {
  lcd.clear();
  // put your main code here, to run repeatedly:
  int a = digitalRead(button_right);
  if (a == 1) {
    i = i + 1;
    lcd.setCursor(0,0);
    lcd.print("Set Minutes");
    Serial.println(i);
    lcd.setCursor(0,1);
    lcd.print(i);
    delay(300);
  }

  int b = digitalRead(button_left);
  if (b == 1) {
    i = i - 1;
    Serial.println(i);
    lcd.setCursor(0,0);
    lcd.print("Set Minutes");
    lcd.setCursor(0,1);
    lcd.print(i);
    if(i == -1){
      lcd.setCursor(0,1);
      lcd.print("Invalid Minutes");
    }
    delay(300);
  }
  if(i == 60){
    i = 0;
  }
  if(i <= -1){
     i = 0;
  }
  return i;
}
