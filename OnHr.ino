int j;

int settings() {
  
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
    lcd.setCursor(0,1);
    lcd.print(j);
    delay(300);
  }
  return j;
}
