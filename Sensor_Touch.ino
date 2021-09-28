
const int TOUCH_SENSOR_PIN  = 4; // Arduino pin connected to the OUTPUT pin of touch sensor
const int LED_PIN           = 2;
int Value = 0;
int Light_ON= 0;
int Touched = 0;
// Arduino pin connected to LED's pin

void setup() {
  Serial.begin(9600);               // initialize serial
  pinMode(TOUCH_SENSOR_PIN, INPUT); // set arduino pin to input mode
  pinMode(LED_PIN, OUTPUT);         // set arduino pin to output mode
}

void loop() {
  int touchState = digitalRead(TOUCH_SENSOR_PIN); // read new state

  if (touchState == HIGH && Light_ON == LOW ) {
    Touched = 1-Touched;
    delay(1000) ;
  }
  Light_ON = Value ;

  if (Touched == HIGH) {
    Serial.println("The sensor is being touched");;
    digitalWrite(LED_PIN, LOW); // turn on
  }
  else
  if (Touched == LOW) {
    Serial.println("The sensor is untouched");
    digitalWrite(LED_PIN, HIGH);  // turn off
  }
}
