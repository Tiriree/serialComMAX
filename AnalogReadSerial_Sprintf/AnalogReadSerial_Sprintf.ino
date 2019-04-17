//AnalogReadSerial modified by Tiri Kananuruk//

int sensorPin = A0; // select the input pin for the potentiometer
int sensorValue = 0 ; // variable to store the value coming from the sensor
int sensorPins[] = {A2, A3, A4, A7, A9, A12}; // don't forget to change this
 
void setup() {
  
  Serial.begin(9600);
}


void loop() {
   sensorValue = analogRead(sensorPin);
  int values[6]; //Tiri don't forget to change this
  for (int i = 0; i < 6; i++) {  //and this.. don't forget to change this number
    values[i] = analogRead(sensorPins[i]);
  }
  char payload[512];
  sprintf(payload, "%d %d %d %d %d %d", values[0] , values[1], values[2], values[3], values[4], values[5] );

//  sendOSC(payload);
  Serial.println(payload);
  Serial.println("");
  delay(100);        // delay in between reads for stability
}
