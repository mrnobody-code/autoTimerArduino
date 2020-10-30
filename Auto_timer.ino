#define OnHr
#define OnMin

#include <DS3232RTC.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

//Setting the button variables
int button_left = 2;
int button_right = 3;
int button_up = 4;
int button_down = 5;
int button_show = 6;
int button_set = 7;

//ON Time
int setOnHour = 0;
int setOnMinutes = 0;
int setHrs = 0;

bool setSetOn = false;
int c = 0;

int Heater = 8;
void setup() {
  // put your setup code here, to run once:
  pinMode(button_left, INPUT_PULLUP);
  pinMode(button_right, INPUT_PULLUP);
  pinMode(button_up, INPUT_PULLUP);
  pinMode(button_down, INPUT_PULLUP);
  pinMode(button_show, INPUT_PULLUP);
  pinMode(button_set, INPUT_PULLUP);
  pinMode(Heater, OUTPUT);

  setSyncProvider(RTC.get);
  Serial.begin(9600);

  lcd.init();                      
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.print("Welcome");

}

void loop() {

  setOnHour = setHr();
  setOnMinutes = setMn();

  if (digitalRead(button_set) == HIGH) {
    //For Serial Monitor
    Serial.print("Set Time is: ");
    Serial.print(setOnHour);
    Serial.print(" Hours ");
    Serial.print(setOnMinutes);
    Serial.println(" Minutes");
    //For LCD
    lcd.setCursor(0,0);
    lcd.print("Set Time is:");
    lcd.setCursor(0,1);
    lcd.print(setOnHour);
    lcd.print(" Hrs ");
    lcd.print(setOnMinutes);
    lcd.print(" Mins");
    delay(500);
    lcd.clear();
  }


  if (digitalRead(button_set) == HIGH) {
    setSetOn = true;
    c = 1;
    Serial.print(setSetOn);
    Serial.print("  ");
    Serial.println(c);
    delay(300);
  }

  if (hour()>12){
    setHrs = 12 + setOnHour; 
  }
  else{
    setHrs = setOnHour;
  }
  
  if (setSetOn == true && c == 1) {
    //Serial.println(setHrs);
    if (hour() == setHrs && minute() == setOnMinutes) {
      Serial.println("Heater On");
      lcd.setCursor(0,0);
      lcd.print("Hazard");
      lcd.setCursor(0,1);
      lcd.print("Heater On");
      digitalWrite(Heater, HIGH);
      delay(500);
    }

    else if (hour() == setHrs + 1 && minute() == setOnMinutes) {
      Serial.println("Heater Off");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Safe Mode");
      lcd.setCursor(0,1);
      lcd.print("Heater Off");
      digitalWrite(Heater, LOW);
      c = 0;
      delay(200);
    }
  }
  if (c > 1) {
    setSetOn = false;
    c = 0;

    Serial.print(setSetOn);
    Serial.print("  ");
    Serial.println(c);
  }

  if (digitalRead(button_show) == HIGH) {
    Serial.print("Current Time is  : ");
    
    lcd.setCursor(0,0);
    lcd.print("Current Time is:");
    lcd.setCursor(0,1);
    
    if (hour() > 12) {
      Serial.print(hour() - 12);
      lcd.print(hour() - 12);
     
    }
    else {
      Serial.print(hour());
      lcd.print(hour());
    }
    lcd.print(" Hrs ");
    Serial.print(" Hour ");
    Serial.print(minute());
    Serial.println("  Minute");
   
    //For Lcd
    lcd.print(minute());
    lcd.print(" Mins");
    delay(500);
    lcd.clear();   
   
  }

}

int setHr() {
  setOnHour = OnHr::settings();
  if (setOnHour <= 0) {
    setOnHour = 0;
  }
  return setOnHour;
}

int setMn() {
  setOnMinutes = OnMin::mint();
  if (setOnMinutes <= 0) {
    setOnMinutes = 0;
  }
  return setOnMinutes;
}
