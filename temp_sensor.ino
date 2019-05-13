const int tempPin = 0; 
const int ledPin = 13;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float voltage, degC, degF;
  voltage = getVoltage(tempPin);
  degC = (voltage -0.5) * 100.0;
  degF = (9.0/5.0)* degC + 32.0;
  if(degF > 45.0){
    digitalWrite(ledPin, HIGH);
  }
  else{
    digitalWrite(ledPin, LOW);
  }
  Serial.print("Voltage :");
  Serial.print(voltage);
  Serial.print("Temperature in C: ");
  Serial.print(degC);
  Serial.print("Temperature in F: ");
  Serial.println(degF);
  Serial.println((analogRead(1)/2));
  delay(1000);
}

float getVoltage(int pin){  
  return(analogRead(pin)*0.004882814);
}
