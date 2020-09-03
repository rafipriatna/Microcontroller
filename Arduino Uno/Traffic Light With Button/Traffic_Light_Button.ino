void setup() {
  // put your setup code here, to run once:
  // PIN
  pinMode(2, OUTPUT); // Merah
  pinMode(3, OUTPUT); // Kuning
  pinMode(4, OUTPUT); // Hijau

  pinMode(5, INPUT); // Tombol
}

void cekTombol(){
  int tombol;
  tombol = digitalRead(5); // Baca input tombol di pin 5
  if (tombol == HIGH){
    digitalWrite(2, HIGH);
    digitalWrite(4, LOW);

    for (int i = 0; i <= 20; i++){
      digitalWrite(3, HIGH);
      delay(500);
      digitalWrite(3, LOW);
      delay(500);
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (uint32_t tStart = millis(); (millis()-tStart) < 5000;){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    cekTombol();
  }

  for (uint32_t tStart = millis(); (millis()-tStart) < 2000;){
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    cekTombol();
  }

  for (uint32_t tStart = millis(); (millis()-tStart) < 3000;){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    cekTombol();
  }
  
}
