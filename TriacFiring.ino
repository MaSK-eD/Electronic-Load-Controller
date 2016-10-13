#define triac 11
volatile int firing = 5 ;
float sensorV = 0 ;
float actualV = 0 ;
float sensorI = 0 ;
float actualI = 0 ;
float power = 0 ;

void zero_cross_int ()
{
  delayMicroseconds (firing) ;
  digitalWrite (triac, HIGH) ;
  delayMicroseconds (10) ;
  digitalWrite (triac, LOW) ;
}

viod loop ()
{
   //SENSE VOLTAGE
   sensorV = analogRead (A0) ;
   sensorV = sensorV * (5.0 / 1023.0) ;
   actualV = 3.577762 * sensorV * (220 / 12) ;
   sensorI = analogRead (A1) ;
   sensorI = sensorI * (5.0 / 1023.0) ;
   actualI = sensorI * 0.34023333 ;
   power = actualI * actualV ;
   Serial.print ("Power: ") ;
   Serial.println (power) ;
   int diff = 200 - power ;
   Serial.print ("Diff: ") ;
   Serial.println (diff) ;

   if (diff > 200 || diff < -200)	//these value can be based on your measurement
   {
      Serial.println ("System Out of control!") ;
   }
   else if (abs (diff) < 10)
   {
      Serial.println ("System Stable!") ;
   }
   else if (diff > 10)
   {
      firing = map (diff, 0, 200, 9000, 10) ;	//mapping the difference value to setup a firing angle 
   }
   else if (diff < -10)
   {
      firing = 9000 ;
   }
   else
   {
   }
}
   }
   
   
}

