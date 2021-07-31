const int pir1 = 7; //input
2 const int pir2 = 4; //input
3
4 const int led1 = 12; //output
5 const int led2 = 13; //output
6
7 const int timerled = 8;//output
8
9 volatile byte PIR_sensor1, PIR_sensor2 = 0; // volatile tells the compiler that the
,→ value can change.
10 //here value changes when motion is detected and the led lights up.
11
12 void setup()
13 {
14 Serial.begin(9600);
15 pinMode(pir1, INPUT);
16 pinMode(pir2, INPUT);
17
18
19 pinMode(timerled, OUTPUT);
20
21 PCICR |= 0b00000100; // turn on port d. PIR sensors connected between 0-7 pins
22
23 PCMSK2 |= 0b10010000; // turn on digital pin 7 and 4
24
25 noInterrupts();
26
27 TCCR1A = 0;
28 TCCR1B = 0;
29 TCNT1 = 0;
30
31 OCR1A = 12499; // timer compare
32
33 TCCR1B |= (1<<CS12)| (1<<CS10);
34
35 TIMSK1 |= (1<<OCIE1A);
36
37 TCCR1B |= (1<< WGM12);
38
39 interrupts();
40
41
42 }
43
44 void loop()
45 {
46 digitalWrite(led1, PIR_sensor1);
47 digitalWrite(led2, PIR_sensor2);
48 }
49
50 ISR(PCINT2_vect) // for port d pin change interrupts
51 {
52 PIR_sensor1 = PIND & B10000000;
Page 3 of 4
File 3 of 3 source code of your new program
53 PIR_sensor2 = PIND & B00010000;
54
55 Serial.println("Pin change interrupts");
56 }
57
58
59 ISR(TIMER1_COMPA_vect)
60 {
61 digitalWrite(timerled, digitalRead(timerled)^1);
62 Serial.println("Timer led ");
63 }
