int sensorValue[5];
int ledPin=12;
int ledPin2=13;
int lightPin=0;
int ledPin3=11;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
}

void loop() {
  int digValue2= digitalRead(2);
//  int digValue3= digitalRead(3);
//  int digValue4= digitalRead(4);
  Serial.println(analogRead(lightPin));
  delay(10); //short delay for faster response to light.

  for (int i=0;i<5;i++){
  sensorValue[i] = analogRead(i);
  Serial.print(sensorValue[i]); 
  Serial.print(",");
  }
  sensorValue[5] = analogRead(5);
  Serial.print(sensorValue[5]);
  Serial.print(",");
  Serial.print(digValue2);
//  Serial.print(",");
//  Serial.println(digValue3);
  
  if (Serial.available() > 0) {
  //char incoming = Serial.read();

  String incoming = Serial.readStringUntil('\n');
  Serial.println(incoming);
  if (incoming=="on"){
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  digitalWrite(11,HIGH);
  }
  if (incoming=="off"){
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  digitalWrite(11,LOW);

  }
  }
}
