#include <Wire.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

// Pin configuration
#define MQ2_PIN 34
#define MQ5_PIN 35
#define DHT_PIN 2
#define DHT_TYPE DHT11

#define BUZZER_PIN 18
#define RED_LED 19
#define GREEN_LED 23

// Initial test thresholds only
#define MQ2_THRESHOLD 2000
#define MQ5_THRESHOLD 2000

DHT dht(DHT_PIN, DHT_TYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);

  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);

  Wire.begin(21, 22);
  lcd.init();
  lcd.backlight();

  dht.begin();

  lcd.setCursor(0, 0);
  lcd.print("IoT Monitoring");
  lcd.setCursor(0, 1);
  lcd.print("Starting...");
  delay(2000);
}

void loop() {
  int gasMQ2 = analogRead(MQ2_PIN);
  int gasMQ5 = analogRead(MQ5_PIN);

  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();

  bool gasDetected =
    (gasMQ2 > MQ2_THRESHOLD) ||
    (gasMQ5 > MQ5_THRESHOLD);

  Serial.println("--------------------");
  Serial.print("MQ2 Value: ");
  Serial.println(gasMQ2);

  Serial.print("MQ5 Value: ");
  Serial.println(gasMQ5);

  if (isnan(temp) || isnan(humidity)) {
    Serial.println("DHT Sensor Error");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.println(" C");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  }

  lcd.clear();
  lcd.setCursor(0, 0);

  if (gasDetected) {
    lcd.print("GAS ALERT!");
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
  } else {
    lcd.print("AIR: NORMAL");
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
  }

  lcd.setCursor(0, 1);

  if (!isnan(temp)) {
    lcd.print("T:");
    lcd.print(temp, 1);
    lcd.print("C ");
  } else {
    lcd.print("T: Sensor Error");
  }

  if (!isnan(humidity)) {
    lcd.print("H:");
    lcd.print(humidity, 0);
  }

  delay(2000);
}