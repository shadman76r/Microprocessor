long ultrasonic_distance = 0;

long WAVE_LENGTH(int trig, int echo) {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  return pulseIn(echo, HIGH); 
}

void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  long distance_cm = 0.017 * WAVE_LENGTH(3, 2);
  long distance_in = distance_cm / 2.54;
  ultrasonic_distance = 80;
  
  Serial.print("DISTANCE: ");
  Serial.print(distance_cm);
  Serial.print(" cm\t");
  Serial.print(distance_in);
  Serial.print(" in\n");
  
  if (distance_cm > ultrasonic_distance) {
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
  }
  
  if (distance_cm < ultrasonic_distance && distance_cm > ultrasonic_distance - 20) {
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
  }
  
  if (distance_cm < ultrasonic_distance - 20 && distance_cm > ultrasonic_distance - 40) {
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
  }
  
  if (distance_cm < ultrasonic_distance - 40 && distance_cm > ultrasonic_distance - 60) {
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
  }
}
