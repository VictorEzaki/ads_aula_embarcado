const int FOTORESISTOR = A0;
const int PIEZZO = A1;

const int LIMITE_LUZ = 50; 

void setup() {
  pinMode(FOTORESISTOR, OUTPUT);
  pinMode(PIEZZO, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int leituraLDR = analogRead(FOTORESISTOR);
  
  Serial.print("Leitura do LDR: ");
  Serial.println(leituraLDR);

  if (leituraLDR < LIMITE_LUZ) {
    tone(PIEZZO, 1000);
    delay(150);
    noTone(PIEZZO);
    delay(100);
  } else {
    noTone(PIEZZO);
  }

  delay(50);
}