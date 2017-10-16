#define LED 13

void setup() {
  Serial.begin(115200);
  Serial.println("O3 testing");
}

void loop() {
  int O3 = analogRead(A0);
  Serial.print("O3: ");  Serial.print(O3);   Serial.println(" ppm");
  
  analogWrite(LED, O3);
  delay(500);
}
