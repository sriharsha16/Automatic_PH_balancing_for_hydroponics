#define SensorPin 0          //pH meter Analog output to Arduino Analog Input 0
unsigned long int PhValueraw;  //Store the average value of the sensor feedback

float pHValue,voltage,disp,H;
const int volume=0.1;
float  DiffpH ;
  

void setup()
{
  pinMode(13,OUTPUT);  
  Serial.begin(9600);  
  Serial.println("Ready");    //Test the serial monitor
  Serial.println("Automatic pH Regulator");

}

void loop()

  { 
     float An=6.023*(10^23);
  float base=6.023*(10^16);
  float acid= 6.023*(10^16);
  // PhValueraw =analogRead(SensorPin);
    // voltage = PhValueraw*6/1023;
     // pHValue = 3.5*voltage;
     pHValue=4.68;
    delay(5000);
 
 Serial.println(PhValueraw);
 Serial.println(voltage);
 Serial.println(pHValue);
 
 if (pHValue==7) {
  Serial.println("The Water is Neutral");
 }
 if  (pHValue>7)
 {
   Serial.println("The Water is Basic");
   Serial.println("Adding acid to water");
   DiffpH=pow(10, -pHValue);
   H = DiffpH*volume*An;
   disp= H/acid ;
   Serial.println("Amount of base to be dosed" );
   Serial.println(disp);
   Serial.println("ml");
 }
 if 
  (pHValue<7)
  {
    Serial.println("The Water is Acidic");
    Serial.println("Adding base to water");
     DiffpH= pow(10,-pHValue);
   H = DiffpH*volume*An;
   disp= H/base ;
   Serial.println("Amount of base to be dosed" );
   Serial.println(disp);
   Serial.println("ml");
    
 }
 
 
}

