#include <SoftwareSerial.h>
#define txPin 2
SoftwareSerial LCD = SoftwareSerial(0, txPin);

const int LCDdelay=5; // initialzie a constant variable which cannot be altered

void lcdPosition(int row, int col) { // creates the function for positioning the text in a fixed place
LCD.write(0xFE); 
LCD.write((col + row*64 + 128)); 
delay(LCDdelay);
}

void deleteLCD(){ // creates the function for clearing the LCD screen
LCD.write(0xFE); 
LCD.write(0x01); 
delay(LCDdelay);
}

int potent = 2; 
int val = 0; // initialize variable which will hold potentiometer value
int redPin = 11;
int greenPin = 10;
int bluePin = 9;

void changeColor(int red, int green, int blue) // initialize function which will hold color codes
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
{
pinMode(txPin, OUTPUT);
LCD.begin(9600); // initializes connection with the LCD
deleteLCD();
lcdPosition(0,0);
}
}

void loop()
{
  
val = analogRead(potent);    // read the value from the potentiometer

  changeColor(0, 0, 255); 
  deleteLCD();
lcdPosition(0,0);
LCD.print(val);
LCD.print("ohms");
   delay(val);
  
  changeColor(0, 255, 0);
  deleteLCD();
lcdPosition(0,0);
  LCD.print(val);
    LCD.print("ohms");
   delay(val);

  changeColor(255, 0, 0);
  deleteLCD();
lcdPosition(0,0);
  LCD.print(val);
    LCD.print("ohms");
 delay(val);

  changeColor(0, 255, 255); 
  deleteLCD();
lcdPosition(0,0);
  LCD.print(val);
    LCD.print("ohms");
   delay(val);
  
  changeColor(80, 0, 80); 
lcdPosition(0,0);
  LCD.print(val);
    LCD.print("ohms");
   delay(val);
  
  changeColor(255, 255, 0);
  deleteLCD();
lcdPosition(0,0);
  LCD.print(val);
LCD.print("ohms");
   delay(val);
}
