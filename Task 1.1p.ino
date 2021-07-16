const int trigg = 3;
const int echo = 2;
const int led = 8;
const int dist_threshold = 50;

float duration;
float distance;


void setup() {
  Serial.begin(9600);
  pinMode(trigg, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
  
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(trigg, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigg, LOW);
  
  duration = pulseIn(echo, HIGH);
  distance = 0.050* duration;

  if(distance< dist_threshold)
    digitalWrite(led, HIGH);
  else
    digitalWrite(led, LOW);

  if(distance< dist_threshold)
    Serial.print("LED ON ");
  else
    Serial.print("LED OFF ");
    
  Serial.print("Distance: ");
  Serial.println(distance);

  delay(1000);
  // put your main code here, to run repeatedly:

}
