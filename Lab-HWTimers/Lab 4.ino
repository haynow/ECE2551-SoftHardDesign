#include <avr/io.h>
#include <avr/interrupt.h>

// Define enum for pin modes
typedef enum { M_INPUT, M_OUTPUT, M_INPUT_PULLUP } Mode;

// Function to set pin mode (INPUT, OUTPUT, INPUT_PULLUP)
void myPinMode(uint8_t pin, Mode mode) {
  volatile uint8_t* ddr;
  uint8_t port_num;

  // Determine the port and DDR based on the pin number
  if (pin >= 2 && pin <= 7) {
    ddr = &DDRD;
    port_num = 2; // PORTD
  } else if (pin >= 8 && pin <= 13) {
    ddr = &DDRB;
    port_num = 1; // PORTB
  } else if (pin >= A0 && pin <= A5) {
    // Analog pins A0-A5 are on PORTC
    ddr = &DDRC;
    port_num = 3; // PORTC
  } else {
    // Invalid pin number
    return;
  }

  // Set or clear the corresponding bit in DDR
  if (mode == M_OUTPUT) {
    *ddr |= (1 << (pin % 8)); // Set as OUTPUT
  } else {
    *ddr &= ~(1 << (pin % 8)); // Set as INPUT
    if (mode == M_INPUT_PULLUP) {
      // Enable internal pull-up resistor
      switch (port_num) {
        case 1: // PORTB
          PORTB |= (1 << (pin % 8));
          break;
        case 2: // PORTD
          PORTD |= (1 << (pin % 8));
          break;
        case 3: // PORTC
          PORTC |= (1 << (pin % 8));
          break;
        default:
          break;
      }
    }
  }
}

// Function to write digital values (HIGH or LOW)
void myDigitalWrite(uint8_t pin, bool turnOn) {
  uint8_t port_num;

  // Determine the port based on the pin number
  if (pin >= 2 && pin <= 7) {
    port_num = 2; // PORTD
  } else if (pin >= 8 && pin <= 13) {
    port_num = 1; // PORTB
  } else if (pin >= A0 && pin <= A5) {
    // Analog pins A0-A5 are on PORTC
    port_num = 3; // PORTC
  } else {
    // Invalid pin number
    return;
  }

  // Set or clear the corresponding bit in PORT
  switch (port_num) {
    case 1: // PORTB
      if (turnOn) {
        PORTB |= (1 << (pin % 8)); // Set HIGH
      } else {
        PORTB &= ~(1 << (pin % 8)); // Set LOW
      }
      break;
    case 2: // PORTD
      if (turnOn) {
        PORTD |= (1 << (pin % 8)); // Set HIGH
      } else {
        PORTD &= ~(1 << (pin % 8)); // Set LOW
      }
      break;
    case 3: // PORTC
      if (turnOn) {
        PORTC |= (1 << (pin % 8)); // Set HIGH
      } else {
        PORTC &= ~(1 << (pin % 8)); // Set LOW
      }
      break;
    default:
      break;
  }
}

// Function to implement a one millisecond delay
void delay_one_ms() {
  // Choose a prescaler for a 1ms delay (e.g., prescaler = 64)
  TCCR0B = (1 << CS01) | (1 << CS00);

  // Disable global interrupts and save SREG
  cli();
  uint8_t savedSREG = SREG;

  // Set initial value in TCNT0
  TCNT0 = 0;

  // Set Timer0 to Normal Mode
  TCCR0A = 0;

  // Wait until the overflow flag TOV0 is set
  while (!(TIFR0 & (1 << TOV0))) {
    // Wait
  }

  // Stop the clock
  TCCR0B = 0;

  // Clear the TOV0 flag by setting it
  TIFR0 |= (1 << TOV0);

  // Restore interrupts
  SREG = savedSREG;
}

// Function to create a delay for an arbitrary amount of milliseconds
void delay_generic(unsigned long ms) {
  for (unsigned long i = 0; i < ms; i++) {
    delay_one_ms();
  }
}

int main(void) {
  myPinMode(13, M_OUTPUT); // Set pin 13 as OUTPUT
  while (1) {
    myDigitalWrite(13, HIGH); // Turn on LED on pin 13
    delay_generic(1000);      // Delay for 1 second
    myDigitalWrite(13, LOW);  // Turn off LED on pin 13
    delay_generic(1000);      // Delay for 1 second
  }
  return 0;
}
