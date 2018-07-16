int ledPin1 = 11;
int ledPin2 = 12;

void leds_setup(int ledPin1, int ledPin2)
{
  //Setup pin modes to ve output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  while (Serial.available()) {}
  leds_setup(ledPin1, ledPin2);
}

void loop()
{
  static uint32_t cnt = 0;
  Serial.print("loop() cnt:");
  Serial.println(cnt); 
  blink_led(ledPin1, 500);
  blink_led(ledPin2, 500);
  cnt++;
}

void blink_led(int led, uint32_t duration_ms)
{
    digitalWrite(led, HIGH);
    delay(duration_ms);
    digitalWrite(led, LOW);
}

