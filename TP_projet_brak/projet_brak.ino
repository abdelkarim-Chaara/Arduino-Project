#include <DHT.h>
#include <Servo.h> 
//Constants
#define DHTPIN 5     // what pin we're connected to
#define DHTTYPE DHT11   // DHT11

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor for normal 16mhz Arduino

//Variables
float hum;  //Stores humidity value
float temp; //Stores temperature value
int DC=8;


Servo monservo;  // crée l’objet pour contrôler le servomoteur 


void setup() 
{
  //Initialize serial port
  Serial.begin(9600);
  pinMode(DC,OUTPUT);
  Serial.println("DHT11 sensor testing");
  
  //Initialize the DHT sensor
  dht.begin();  


    monservo.attach(2);  // utilise la broche 9 pour le contrôle du servomoteur
}

void loop() 
{ 

for (int pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    monservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
 
  }

  Serial.println("Open GATE");
  for (int pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    monservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
      Serial.println("Closed GATE");
  
    //Read data and store it to variables hum and temp
    hum = dht.readHumidity();
    temp= dht.readTemperature();

    Serial.print("Celsius = ");
    Serial.print(temp);
    //Print degree symbol
    Serial.println("C");

    if(temp >= 20){
    digitalWrite(DC,HIGH);
  } else {
 
    digitalWrite(DC,LOW);

  
  }
    delay(2000);
    
}
