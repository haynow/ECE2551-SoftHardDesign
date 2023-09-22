#include <limits.h>
#include <LiquidCrystal.h>
#include <avr/eeprom.h>

unsigned short save;
unsigned short currentNum;
unsigned long lastTime = 3000;
unsigned short systemTime = 0;

int buttonState;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int buttonPin = 7;
unsigned short randNumber[10] = {};


//--------------------------------------------------------------------------
class Eeprom {
  public:
    Eeprom(){}
    
    byte read(unsigned int uiAddress) {
    
    // Wait for completion of previous write
    while(EECR & (1<<EEPE))
    ;
    // Set up address register
    EEAR = uiAddress;
    
    // Start eeprom read by writing EERE 
    
    EECR |= (1<<EERE);
    // Return data from Data Register 
    
    return EEDR;
    }
           
    void write(unsigned int uiAddress, unsigned char ucData) {
    
     // Wait for completion of previous write 
     while (EECR & (1<<EEPE));
     
    //Set up address and Data Registers
    EEAR = uiAddress;    
    
    EEDR = ucData;
    
    // Write logical one to EEMPE
    EECR |= (1<<EEMPE);
    
    // Start eeprom write by setting EEPE 
    EECR |= (1<<EEPE);
    }
    };
Eeprom eeprom1;

//--------------------------------------------------------------------------

class Button {
  public:
    Button(unsigned short buttonPin) {
      this ->buttonPin = buttonPin;
      lastReading = LOW;
       pinMode (buttonPin, INPUT);
    }
    
      bool hasBeenPushed() {
        byte newReading = digitalRead (buttonPin);
        
        if (newReading != lastReading ){
          lastDebounceTime = millis();
        }
        if (millis() -lastDebounceTime > debounceDelay){
          state = newReading;
          return state;
        }
        lastReading = newReading;

   }

private:
    unsigned short buttonPin =7;
    unsigned long debounceDelay =50;
    unsigned long lastDebounceTime =0;
    unsigned short state; 
    unsigned short lastReading;
};

//--------------------------------------------------------------------------
   
#define buttonPin 7   
Button btn (buttonPin);


const unsigned short EEPROM_START_ADDRESS = 0;
const unsigned short MAX = USHRT_MAX;
const unsigned short MIN = 10000;

//--------------------------------------------------------------------------

void setup() {
  save = 0; // Initialize save to 0
  lcd.begin(16, 2);
  lcd.setCursor(0,0); 

if (eeprom1.read(0x20) == 21)
  {
    //do nothing
  }else
  {
    generateRandom();
    eeprom1.write(0x20,0);
  }
  pinMode(buttonPin, INPUT);
  
}

//--------------------------------------------------------------------------

byte high;
byte low;
void generateRandom(){
  randomSeed(analogRead(0));
  int i = 0;
 for (int i= 0; i < 10; i++)
 {
  randNumber[i] = random(MIN, MAX); 
  high = highByte(randNumber[i]);
  low = lowByte(randNumber[i]);
  eeprom1.write(2 * i, high);
  eeprom1.write((2 * i) + 1,low);
 }
  
}

//--------------------------------------------------------------------------

unsigned short recoverShort (int ind)
{
  save = ind;
  unsigned short store;
  high = eeprom1.read(2 * ind);
  low = eeprom1.read((2 * ind) + 1);

  store = (high << 8) |low;
  return store;
  
}

//--------------------------------------------------------------------------

void loop() {
  if (btn.hasBeenPushed())
  {
        currentNum = recoverShort(save);
        lcd.setCursor(0,0);
        lcd.print ("Hardware Token:");
        lcd.setCursor (0,1);
        lcd.print(currentNum);
        lcd.display();
        lastTime = millis();
  }
  
  if (millis() - lastTime > 3000)
    {
    
    lcd.noDisplay();
    
    }
    if (millis() - systemTime > 10000)
    {
        save = (save + 1) % 10;
        systemTime = millis();
    }
  
}