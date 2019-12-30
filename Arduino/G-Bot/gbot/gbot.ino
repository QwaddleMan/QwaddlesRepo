int right = 2;
int left = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(right, OUTPUT);
  pinMode(left, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(left, HIGH);
  digitalWrite(right, HIGH);
}
