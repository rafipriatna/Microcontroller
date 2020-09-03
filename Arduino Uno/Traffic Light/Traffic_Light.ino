void setup() {
  // put your setup code here, to run once:
  // PIN
  pinMode(2, OUTPUT); // Merah
  pinMode(3, OUTPUT); // Kuning
  pinMode(4, OUTPUT); // Hijau
}

void loop() {
  // put your main code here, to run repeatedly:
  // Lampu merah 10 detik
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  delay(10000); // 10 Detik

  // Lampu kuning 2 detik
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  delay(2000); // 2 Detik

  // Lampu hijau 5 detik
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  delay(5000); // 5 Detik
  
  // Lampu kuning 1 detik
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  delay(1000); // 1 Detik
}
