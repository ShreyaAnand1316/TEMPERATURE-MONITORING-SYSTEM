#include <LiquidCrystal.h>

// Initialize the LCD pins
// RS, E, D4, D5, D6, D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// Define the DHT sensor type and pin
#define DHTPIN 2     // DHT sensor is connected to pin D2
#define DHTTYPE DHT11  // DHT 11 sensor type
#include <DHT.h>
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Initialize the LCD
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Temp Monitor");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(2000);
  lcd.clear();

  // Initialize the DHT sensor
  dht.begin();
}

void loop() {
  // Read temperature from the DHT sensor
  float temp = dht.readTemperature();

  // Check if the reading is valid
  if (isnan(temp)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!");
    lcd.setCursor(0, 1);
    lcd.print("Check Wiring!");
  } else {
    // Display the temperature
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temp);
    lcd.print(" C");

    // Optional: Add a delay between readings
    delay(1000);
  }
}
