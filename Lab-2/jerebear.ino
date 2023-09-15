#include <Arduino.h>
#include <EEPROM.h>
#include <limits.h>
#include <LiquidCrystal.h>

// Constants
const int eepromSize = 1024; // EEPROM size
const int tokenCount = 10;   // Number of tokens to generate
const unsigned short USHRT_MAX_LIMIT = USHRT_MAX;
const int buttonPin = 7;     // Button is connected to pin 7

// Pin configuration for LCD
const int rs = 11;            // Pin 11 on Arduino
const int enable = 12;        // Pin 12 on Arduino
const int d0 = 5;             // Pin 5 on Arduino
const int d1 = 4;             // Pin 4 on Arduino
const int d2 = 3;             // Pin 3 on Arduino
const int d3 = 2;             // Pin 2 on Arduino
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Classes
class Eeprom {
public:
  Eeprom() {}

  byte read(unsigned int uiAddress) {
    while (EECR & (1 << EEPE));
    return EEPROM.read(uiAddress);
  }

  void write(unsigned int uiAddress, byte data) {
    while (EECR & (1 << EEPE));
    EEPROM.write(uiAddress, data);
  }
};

class Button {
public:
  Button(unsigned short pin) {
    pinMode(pin, INPUT_PULLUP);
    _pin = pin;
    _lastState = LOW;
    _lastDebounceTime = 0;
    _debounceDelay = 50; // Adjust this for your button
  }

  bool hasBeenPushed() {
    int reading = digitalRead(_pin);
    if (reading != _lastState) {
      _lastDebounceTime = millis();
    }

    if ((millis() - _lastDebounceTime) > _debounceDelay) {
      if (reading != _buttonState) {
        _buttonState = reading;

        if (_buttonState == HIGH) {
          return true;
        }
      }
    }

    _lastState = reading;
    return false;
  }

private:
  unsigned short _pin;
  int _lastState;
  int _buttonState;
  unsigned long _lastDebounceTime;
  unsigned long _debounceDelay;
};

// Global variables
unsigned short tokens[tokenCount]; // Array to store tokens
unsigned int currentAddress = 0;   // Current EEPROM address to read
unsigned long lastUpdateTime = 0;  // Store the last time the EEPROM was updated
unsigned long lastButtonPressTime = 0; // Store the time of the last button press
const unsigned long updateInterval = 10000; // 10 seconds
const unsigned long displayDuration = 3000; // 3 seconds
bool displayToken = false; // Flag to control token display

void setup() {
  // Initialize EEPROM and load tokens
  Eeprom eeprom;
  randomSeed(analogRead(0)); // Initialize random number generator
  for (int i = 0; i < tokenCount; i++) {
    unsigned short token = random(10000, USHRT_MAX_LIMIT);
    byte highByte = highByte(token);
    byte lowByte = lowByte(token);
    eeprom.write(i * 2, highByte); // Store high byte
    eeprom.write(i * 2 + 1, lowByte); // Store low byte
    tokens[i] = token;
  }

  pinMode(buttonPin, INPUT_PULLUP); // Use internal pull-up resistor for the button
  lcd.begin(16, 2); // Initialize the LCD for 16x2 display
  lcd.noDisplay();  // Turn off the display initially
}

void loop() {
  unsigned long currentTime = millis();

  // Check if it's time to update the displayed token
  if (currentTime - lastUpdateTime >= updateInterval) {
    lastUpdateTime = currentTime;
    displayToken = true;
  }

  // Check if the button has been pressed
  Button button(buttonPin);
  if (button.hasBeenPushed() && (currentTime - lastButtonPressTime >= displayDuration)) {
    displayToken = true;
    lastButtonPressTime = currentTime;
  }

  // Display the token if needed
  if (displayToken) {
    displayTokenOnLCD(tokens[currentAddress]);

    // Reset the flag and increment the current address
    displayToken = false;
    currentAddress = (currentAddress + 1) % tokenCount;
  }
}

void displayTokenOnLCD(unsigned short token) {
  lcd.clear();
  lcd.display(); // Turn on the display
  lcd.setCursor(0, 0);
  lcd.print("Hardware Token");
  lcd.setCursor(0, 1);
  lcd.print(token);
  delay(displayDuration); // Display for 3 seconds
  lcd.noDisplay(); // Turn off the display
}