const int coinPin = 2;    // GPIO pin connected to coin acceptor
const int billPin = 3;    // GPIO pin connected to bill acceptor
int total = 0;

String a;
int command = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(coinPin, INPUT_PULLUP);
  pinMode(billPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() 
{
  int val = digitalRead(coinPin);
  if (val == 1) {
    total ++;
    Serial.println(total);
  }

  //
  int val1 = digitalRead(billPin);
  if (val1 == 0) {
    total = total + 10;
    Serial.println(total);
  }

  delay(70);

  //
  while (Serial.available()) {
    a = Serial.readString();

    command = a.toInt();

    // clear ok
    if (command == 1) {
      total = 0;
      Serial.println("0");
    }
  }
}
