
int sensorPin = A0; //    
int ledPin1 = 11;  
int ledPin2 = 12;
int ledPin3 = 13;
int sensorValue = 0;  
#define MIN_VAL 80
#define MAX_VAL 700
int treshhold_bins[] = {MAX_VAL/3, MAX_VAL*2/3, MAX_VAL};

void leds_setup()
{
  //Setup pin modes to ve output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}


void setup() 
{
  Serial.begin(115200);
  while (Serial.available()) {}
  // declare the ledPin as an OUTPUT:
  leds_setup();
}

void loop() 
{
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  
  if(sensorValue < treshhold_bins[2]) 
  {  digitalWrite(ledPin1, HIGH); }
  else 
  {  digitalWrite(ledPin1, LOW); }

  if(sensorValue < treshhold_bins[1]) {
    digitalWrite(ledPin2, HIGH); }
  else { 
    digitalWrite(ledPin2, LOW); }

  if(sensorValue < treshhold_bins[0]) {
    digitalWrite(ledPin3, HIGH); }
  else { 
    digitalWrite(ledPin3, LOW); }
  
  delay(500);
    
}
