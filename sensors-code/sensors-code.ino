/*
  Automatic Irrigation - MYOSA / ESP32
  ------------------------------------

  Sensors:
    - HW-103 OR HW-080
      Soil moisture, analog -> GPIO 34

    - APDS9960
      Ambient light, I2C

    - BMP180
      Barometric pressure and temperature, I2C

  Display:
    - OLED SSD1306 128x64, I2C

  Actuator:
    - Solenoid valve -> GPIO 14

  Valve logic:
    - Turns ON when:
        light < LUX_NIGHT_THRESHOLD
        AND
        soil moisture > SOIL_DRY_THRESHOLD

    - Turns OFF when either condition is no longer true.

  Display:
    - Screens alternate every 10 seconds:
        1) Soil moisture
        2) Light level
        3) Pressure / temperature

  Libraries:
    - MYOSA
    - LightProximityAndGesture
    - BarometricPressure
    - oled
*/

#include <Wire.h>
#include <LightProximityAndGesture.h>
#include <BarometricPressure.h>
#include <oled.h>

// APDS9960
LightProximityAndGesture lightSensor;

// BMP180
BarometricPressure pressureSensor(ULTRA_HIGH_RESOLUTION);

// OLED SSD1306
oLed display(SCREEN_WIDTH, SCREEN_HEIGHT);

// Soil moisture sensor
// Use HW-103 OR HW-080
const uint8_t SOIL_PIN = 34;

// Solenoid valve
const uint8_t VALVE_PIN = 14;

// Thresholds
const int LUX_NIGHT_THRESHOLD = 3000;
const int SOIL_DRY_THRESHOLD  = 400;

// Sensor readings
int soilValue = 0;

float luxValue = 0.0;

float pressureHPa = 0.0;

float temperatureC = 0.0;

// Valve state
bool valveState = false;

// Sensor reading timer
unsigned long previousSensorMillis = 0;

const unsigned long sensorReadInterval = 1000;

// Screen change timer
unsigned long previousScreenMillis = 0;

const unsigned long screenInterval = 10000;

// Current screen
uint8_t currentScreen = 0;

const uint8_t totalScreens = 3;

void setup() {

  /* Serial communication */
  Serial.begin(115200);

  /* I2C communication */
  Wire.begin();
  Wire.setClock(100000);

  pinMode(VALVE_PIN, OUTPUT);

  // Valve starts OFF
  digitalWrite(VALVE_PIN, LOW);

  if (!display.begin()) {

    Serial.println("Failed to initialize SSD1306 display");

  } else {

    display.clearDisplay();

    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);

    display.println("Irrigation");
    display.println("System");
    display.println();
    display.println("Starting...");

    display.display();

    delay(1000);

    display.clearDisplay();
    display.display();
  }

  if (lightSensor.begin()) {

    Serial.println("APDS9960 connected");

  } else {

    Serial.println("Failed to initialize APDS9960");
  }

  if (pressureSensor.begin()) {

    Serial.println("BMP180 connected");

  } else {

    Serial.println("Failed to initialize BMP180");
  }

  readSensors();

  updateValve();

  showScreen(currentScreen);
}

void loop() {

  unsigned long currentMillis = millis();

  if (currentMillis - previousSensorMillis >= sensorReadInterval) {

    previousSensorMillis = currentMillis;

    readSensors();

    updateValve();
  }

  if (currentMillis - previousScreenMillis >= screenInterval) {

    previousScreenMillis = currentMillis;

    currentScreen++;

    if (currentScreen >= totalScreens) {
      currentScreen = 0;
    }

    showScreen(currentScreen);
  }
}

void readSensors() {

  soilValue = analogRead(SOIL_PIN);

  /*
    The MYOSA library provides the ambient light level
    directly in lux.

    false = do not automatically print the result.
  */

  luxValue = lightSensor.getAmbientLight(false);

  /*
    getPressurePascal() returns pressure in Pascal.

    Conversion:
        1 hPa = 100 Pa
  */

  pressureHPa =
      pressureSensor.getPressurePascal(false) / 100.0;

  temperatureC =
      pressureSensor.getTempC(false);

  Serial.print("Soil = ");
  Serial.print(soilValue);

  Serial.print(" | Lux = ");
  Serial.print(luxValue, 1);

  Serial.print(" | Pressure = ");
  Serial.print(pressureHPa, 1);
  Serial.print(" hPa");

  Serial.print(" | Temp = ");
  Serial.print(temperatureC, 1);
  Serial.print(" C");

  Serial.print(" | Valve = ");

  if (valveState) {
    Serial.println("ON");
  } else {
    Serial.println("OFF");
  }
}

void updateValve() {

  bool isNight =
      (luxValue < LUX_NIGHT_THRESHOLD);

  bool isDry =
      (soilValue > SOIL_DRY_THRESHOLD);

  bool shouldOpen =
      isNight && isDry;

  if (shouldOpen != valveState) {

    valveState = shouldOpen;

    if (valveState) {

      digitalWrite(VALVE_PIN, HIGH);

      Serial.println(">>> VALVE OPEN");

    } else {

      digitalWrite(VALVE_PIN, LOW);

      Serial.println(">>> VALVE CLOSED");
    }
  }
}

void showScreen(uint8_t screen) {

  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0, 0);

  switch (screen) {

    case 0:

      display.println("== SOIL MOISTURE ==");

      display.print("Reading: ");
      display.println(soilValue);

      display.println();

      display.print("Status: ");

      if (soilValue > SOIL_DRY_THRESHOLD) {
        display.println("DRY");
      } else {
        display.println("WET");
      }

      break;

    case 1:

      display.println("== LIGHT LEVEL ==");

      display.print("Lux: ");
      display.println(luxValue, 1);

      display.println();

      display.print("Period: ");

      if (luxValue < LUX_NIGHT_THRESHOLD) {
        display.println("NIGHT");
      } else {
        display.println("DAY");
      }

      break;

    case 2:

      display.println("== PRESSURE / TEMP ==");

      display.print("Pressure: ");
      display.print(pressureHPa, 1);
      display.println(" hPa");

      display.print("Temp: ");
      display.print(temperatureC, 1);
      display.println(" C");

      break;
  }

  display.println();

  display.print("Valve: ");

  if (valveState) {
    display.println("OPEN");
  } else {
    display.println("CLOSED");
  }

  display.display();
}