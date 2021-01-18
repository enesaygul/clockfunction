
#include <LiquidCrystal.h>

// The time model
unsigned int hours = 0;
unsigned int minutes = 0;
unsigned int seconds = 0;


void setup() {
  // Set up the LCD's number of columns and rows: 
  lcd.begin(16,2);

}

void loop() {
  // Increase the time model by one second
  incTime();

  // Print the time on the LCD
  printTime();

}


// Increase the time model by one second
void incTime() {

  while(millis() % 1000 != 0);
  // Increase seconds
  seconds++;

  if (seconds == 60) {
    // Reset seconds
    seconds = 0;

    // Increase minutes
    minutes++;

    if (minutes == 60) {
      // Reset minutes
      minutes = 0;

      // Increase hours
      hours++;
      
      if (hours == 24) {
        // Reset hours
        hours = 0;


      }
    }
  }
}

// Print the time on the LCD
void printTime() {
    
    

  // Set the cursor at the begining of the second row
  lcd.setCursor(0,1);
  char time[17];
  sprintf(time, "%02i:%02i:%02i",hours, minutes, seconds);
  lcd.print(time);
}
