#include <math.h>

float R0;
float sensor_volt = 0;
float RS_gas = 0;
float RS_air; //  Get the value of RS via in a clear air
float ratio = 0.0;
float sensorValue = 0;

void setup() {
    Serial.begin(9600);
    R0 = 0.07; //calibrate();
    Serial.print("R0 = ");
    Serial.println(R0);
    delay(1000);
}

void loop() {
 
    //Heather 5v 60 s
    Serial.println("60 second heating pause...");
    analogWrite(A1, 1023);
    delay(60000);
    Serial.println("Heating done, resuming measurements...");
    //Heather 1.4 V 90 s
    analogWrite(A1, (1023/5)*1.4 );
    for(int i = 0; i<900; i++){
        sensorValue = analogRead(A0);
        int sensor_volt = sensorValue/1024*5.0;
        //RS_gas = (5.0-sensor_volt)/sensor_volt;
        //ratio = RS_gas/R0; //Replace R0 with the value found using the calibration code
        double ppm = 3.027*exp(1.0698*(sensor_volt));
        Serial.print("ppm: ");
        Serial.println(ppm);
        //Serial.println(ppm);
        delay(2000);
    }
    Serial.println("60 second heating pause...");

}

float calibrate() {
    /*--- Get a average data by testing 100 times ---*/
    //Heather 5v 60 s
    analogWrite(A1, 1023);
    delay(60000);

    //Heather 1.4 V 90 s
    analogWrite(A1, (1023/5)*1.4 );
    for(int i = 0; i<100; i++){
        sensorValue = sensorValue + analogRead(A0);
        delay(900);
    }

    sensorValue = sensorValue/100.0;
    /*-----------------------------------------------*/

    sensor_volt = sensorValue/1024*5.0;
    RS_air = (5.0-sensor_volt)/sensor_volt;
    R0 = RS_air/(26+(1/3));

    return R0;
}
