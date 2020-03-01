/*
  Copyright (C) 2020 Sarath Kumar
 
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
  LiquidCrystal_I2C Library supported for PCF8574 Backpacks - https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library
*/

//Comment Wire.h Header for ESP Boards
//#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <BigNumbers.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
BigNumbers bigNum(&lcd); // construct BigNumbers object, passing to it the name of our LCD object

void setup()
{
  //Wire.begin(); //Uncomment for ESP Boards
  lcd.begin(); // setup LCD rows and columns
  bigNum.begin(); // set up BigNumbers
  lcd.clear(); // clear display
}

void loop()
{
  int currentTime = millis() / 100; // assigns the current time since boot in tenths of a second to currentTime
  byte lastDigit = currentTime % 10;
  currentTime = currentTime /= 10;
  bigNum.displayLargeInt(currentTime, 0, 4, false);
  // print out the decimal point and the digit after it
  lcd.setCursor(12, 1);
  lcd.print(".");
  lcd.print(lastDigit);
}
