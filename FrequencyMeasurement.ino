// To measure the frequency of the input voltage and current.

//Initialize this for attachment of lcd display with arduino board
#include <LiquidCrystal.h>

// use only if you have attached a lcd display with arduino
#define REGISTER_SELECT 12
#define ENABLE 11
#define DATA_1 2
#define DATA_2 3
#define DATA_3 4
#define DATA_4 5

LiquidCrystal lcd (12, 11, 5, 4, 3, 2) ;

int analoginputa = A3 ;    //square wave input for arduino.

int high_time ;
int low_time ;
float time_period ;
float frequency ;

void setup ()
{
  Serial.begin (9600) ; 
  Serial.println ("Program Started") ;
  pinMode (analoginputa, INPUT) ;
  lcd.begin (16,2) ;		//size of your lcd display used.
  
  lcd.print ("Welcome to Frequency Meter") ;
  delay (2000) ;
  analogReference(EXTERNAL) ;
  pinMode (output , OUTPUT) ;
}

void loop ()
{
  lcd.clear () ;
  lcd.setCursor (0, 0) ;

//For first phase input at A0

  Serial.begin (9600) ;
  high_time = pulseIn (analoginputa, HIGH) ;
  low_time = pulseIn (analoginputa, LOW) ;

  time_period = high_time + low_time ;
  time_period = time_period / 1000 ;
  frequency = 1000 / time_period ;
  lcd.setCursor (0,0) ;
  lcd.print ("Frequency at First Phase") ;
  delay (100) ;
  lcd.scrollDisplayLeft();
  delay (100) ;
  lcd.setCursor (0,1) ;
  lcd.print (frequency) ;
  lcd.print (" Hz.") ;
  Serial.print ("Frequency is = ") ;
  Serial.println (frequency) ;
  delay (2000);
  
}

