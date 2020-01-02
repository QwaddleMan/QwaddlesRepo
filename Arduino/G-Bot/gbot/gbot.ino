int right = 2;
int left = 3;

void setup() {
  pinMode(right, OUTPUT);
  pinMode(left, OUTPUT);
}

void loop() {
  digitalWrite(left, HIGH);
  digitalWrite(right, HIGH);
}
