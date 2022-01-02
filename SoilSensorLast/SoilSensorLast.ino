/* 
 *  Project Name: Portable Soil Moisture Sensor
 *  Revision Date: 24.12.2021
 *  Author: Meis Çoksüren
*/
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3f,16,2); 
int sensorPin = A0;                  //the pin on which the sensor will be installed 
int buzzerPin = 8;                  //the pin on which the buzzer will be installed
int veri;                           

// put your setup code here, to run once:
void setup() {
 Serial.begin(9600);
  lcd.begin();       // LCD display will have backlight 
  lcd.backlight();
  lcd.clear();
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  delay(1000);
  lcd.setCursor(0, 0);              //After opening backlight, "MOISTURE SENSOR IS ON" will be written on display
  lcd.print("MOISTURE");
  lcd.setCursor(0, 1);
  lcd.print("SENSOR IS ON ");
    lcd.print("");
    delay(3000);
  lcd.clear();

  pinMode(sensorPin, INPUT);        //Sensor is Input
 pinMode(buzzerPin, OUTPUT);       //Buzzer is Output 
}

// put your main code here, to run repeatedly:
void loop() {
 int value = analogRead(A0);      
  Serial.println(value);

 if (0 < value && value < 300) {             // If the sensor value is less than 300, display will write "Plant Feels OK,Moisture : HIGH"
    lcd.setCursor(0, 0);           
    lcd.print("Plant Feels OK ");
 }
  else if (value < 300) {             // If the sensor value is less than 300, display will write "Plant Feels OK,Moisture : HIGH"
    lcd.setCursor(0, 0);           
    lcd.print("Plant Feels OK ");
    lcd.setCursor(0, 1);
    lcd.print("Moisture : HIGH");
  } 
  else if (value > 300 && value < 950) {
    lcd.setCursor(0, 0);          //If the sensor value is in between 300 and 950, display will write "Plant Feels OK,Moisture : MİD"
    lcd.print("Plant Feels OK ");
    lcd.setCursor(0, 1);
    lcd.print("Moisture : MID ");
  } 
  else if (value > 950) {
    lcd.setCursor(0, 0);  // If the sensor value is greater than 950, display will write "Water The Plant,Moisture : LOW"
    lcd.print("Water The Plant");
    lcd.setCursor(0, 1);
    lcd.print("Moisture : LOW ");
  }

  veri = analogRead(sensorPin);     //Digital reading is performed from the sensor.
  if(veri > 950){           // If the value is greater than 950 buzzer will start to sound 
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);
    delay(100);
  }
  else if (veri >300 && veri<950){        // If the value is less than 950, buzzer will not start to sound                     
    digitalWrite(buzzerPin, LOW);
  }
  else if (veri<300){                             
    digitalWrite(buzzerPin, LOW);
  }
}
