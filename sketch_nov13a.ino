#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

#define redLED 9
#define greenLED 10
#define blueLED 11

int redFrequency, greenFrequency, blueFrequency;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

  // Set frequency scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  Serial.begin(9600);
  Serial.println("RGB Color Detection Started");
}

void loop() {
  // Measure RED
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  redFrequency = pulseIn(sensorOut, LOW);

  // Measure GREEN
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  greenFrequency = pulseIn(sensorOut, LOW);

  // Measure BLUE
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  blueFrequency = pulseIn(sensorOut, LOW);

  Serial.print("R:");
  Serial.print(redFrequency);
  Serial.print("  G:");
  Serial.print(greenFrequency);
  Serial.print("  B:");
  Serial.println(blueFrequency);

  // Detect color
  if (redFrequency < greenFrequency && redFrequency < blueFrequency) {
    Serial.println("Detected: RED");
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, LOW);
  } 
  else if (greenFrequency < redFrequency && greenFrequency < blueFrequency) {
    Serial.println("Detected: GREEN");
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(blueLED, LOW);
  } 
  else if (blueFrequency < redFrequency && blueFrequency < greenFrequency) {
    Serial.println("Detected: BLUE");
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, HIGH);
  } 
  else {
    Serial.println("No clear color");
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, LOW);
  }

  delay(500);
}