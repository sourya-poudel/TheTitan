int motorInput1 = 6; // Pin connected to IN3 on L298N for the motor

int motorInput2 = 7; // Pin connected to IN4 on L298N for the motor

// int ch5 = 9; // Input from FS-IA6B channel 5


double ch1 = 2;

int a = 4; int b = 5;

double ch2 = 3;

int c = 6; int d = 7;


void setup() {

  // Initialize Serial communication

  Serial.begin(9600);


  // Motor control pin modes

  pinMode(motorInput1, OUTPUT);

  pinMode(motorInput2, OUTPUT);


  // FS-IA6B channel input

  // pinMode(ch5, INPUT);


  // Additional control pin modes

  pinMode(2, INPUT);

  pinMode(4, OUTPUT); pinMode(5, OUTPUT);

  pinMode(3, INPUT);

  pinMode(6, OUTPUT); pinMode(7, OUTPUT);

}


void loop() {

  // Read pulse from channel 5

  // int ch5State = pulseIn(ch5, HIGH);


  // Control motor based on ch5 state

  // if (ch5State > 1500) { // Assuming switch on corresponds to HIGH pulse width

  // digitalWrite(motorInput1, HIGH);

  // digitalWrite(motorInput2, LOW); // Adjust based on motor direction control

  // } else {

  // digitalWrite(motorInput1, LOW);

  // digitalWrite(motorInput2, LOW);

  // }


  // Read pulses from channels 1 and 2

  ch1 = pulseIn(2, HIGH);

  ch2 = pulseIn(3, HIGH);


  // Control outputs based on ch1 and ch2 states
if ((ch1 == 0) && (ch2 == 0)) {

    digitalWrite(a, LOW); digitalWrite(b, LOW);

    digitalWrite(c, LOW); digitalWrite(d, LOW);

  } else if ((ch1 > 1530) && (ch2 > 1530)) {

    digitalWrite(a, HIGH); digitalWrite(b, LOW);

    digitalWrite(c, LOW); digitalWrite(d, HIGH);

  } else if ((ch1 > 1530) && (ch2 < 1460)) {

    digitalWrite(a, HIGH); digitalWrite(b, LOW);

    digitalWrite(c, HIGH); digitalWrite(d, LOW);

  } else if ((ch1 < 1460) && (ch2 > 1530)) {

    digitalWrite(a, LOW); digitalWrite(b, HIGH);

    digitalWrite(c, LOW); digitalWrite(d, HIGH);

 } else if ((ch1 < 1460) && (ch2 < 1460)) {

    digitalWrite(a, LOW); digitalWrite(b, HIGH);

    digitalWrite(c, HIGH); digitalWrite(d, LOW);

  } else {

    digitalWrite(a, LOW); digitalWrite(b, LOW);

    digitalWrite(c, LOW); digitalWrite(d,LOW);

}

}