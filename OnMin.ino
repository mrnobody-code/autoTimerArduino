int i;

int mint() {
  
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
    lcd.setCursor(0,1);
    lcd.print(i);
    delay(300);
  }
  return i;
}
