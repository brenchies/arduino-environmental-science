// Test code for Grove - Moisture Sensor 
int sensorPin = A0; // select the input pin for the potentiometer
int sensorValue = 0; // variable to store the value coming from the sensor7

void setup() {
    // declare the ledPin as an OUTPUT:
    Serial.begin(9600);
}
void loop() {
    // read the value from the sensor:
    sensorValue = analogRead(sensorPin);
    Serial.print("Raw value : ");
    Serial.println(sensorValue);
    if (sensorValue > 723)
    {
      Serial.println("Dry");
    }
    else if (sensorValue > 323)
    {
      Serial.println("Humid");
    }
    else if (sensorValue > 73)
    {
      Serial.println("Wet");
    }
    else
    {
      Serial.println("Very wet");
    }
      //sensorValue = map(sensorValue,1023,143,0,100);
    //Serial.print("Moisture : ");
    //Serial.print(sensorValue);
    //Serial.println("%");
    delay(2000);
}
