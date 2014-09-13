#define trigPinL 13
#define echoPinL 12
#define trigPinC 9
#define echoPinC 8


void setup() {
  Serial.begin (9600);
  pinMode(trigPinL, OUTPUT);
  pinMode(echoPinL, INPUT);
  pinMode(trigPinC, OUTPUT);
  pinMode(echoPinC, INPUT);
}

void loop() {
  long durationL, distanceL;
  long durationC, center;
  digitalWrite(trigPinL, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPinL, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPinL, LOW);
  durationL = pulseIn(echoPinL, HIGH);
  distanceL = (durationL/2) / 29.1;
  
  digitalWrite(trigPinC, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPinC, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPinC, LOW);
  durationC= pulseIn(echoPinC, HIGH);
  center = (durationC/2) / 29.1;
  
  if (center > 200)
  {
    Serial.println("speed_high");
  if (distanceL > 20 && distanceL < 30)
  {

    Serial.println("speed");
  }
  else if (distanceL < 19 )
  {

    Serial.println("left");
  }
  else if (distanceL >31)
  {

    Serial.println("right");
  }
  }
  
    if (center < 180)
     {
    Serial.println("speed_low");
  if (distanceL > 20 && distanceL < 30)
  {

    Serial.println("speed");
  }
  else if (distanceL < 19 )
  {

    Serial.println("left");
  }
  else if (distanceL >31)
  {

    Serial.println("right");
  }
  }
  delay(50);

}
