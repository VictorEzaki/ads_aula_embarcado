int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;
int pinButton = 10;

int numeroAtual = 0;
bool pausado = false;
int ultimoEstadoBotao = LOW;

unsigned long tempoAnterior = 0;
const long intervalo = 300; 

void setup() {
  Serial.begin(9600);
  pinMode(pinButton, INPUT);
  randomSeed(analogRead(A5));
  
  
  for (int x = 2; x <= 8; x++) {
    pinMode(x, OUTPUT);
    digitalWrite(x, LOW);
  }
}

void loop() {
  int estadoBotao = digitalRead(pinButton);

  
  if (estadoBotao == HIGH && ultimoEstadoBotao == LOW) {
    pausado = !pausado; 
    delay(50);          
  }
  ultimoEstadoBotao = estadoBotao;

  
  if (!pausado) {
    unsigned long tempoAtual = millis();
    if (tempoAtual - tempoAnterior >= intervalo) {
      tempoAnterior = tempoAtual;
      numeroAtual = random(0, 10);
    }
  }

  
  mostrarNumero(numeroAtual);
}

void mostrarNumero(int num) {
  switch (num) {
    case 0: zero(); break;
    case 1: um(); break;
    case 2: dois(); break;
    case 3: tres(); break;
    case 4: quatro(); break;
    case 5: cinco(); break;
    case 6: seis(); break;
    case 7: sete(); break;
    case 8: oito(); break;
    case 9: nove(); break;
  }
}

void zero() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
}

void um() {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

void dois() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
}

void tres() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
}

void quatro() {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void cinco() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void seis() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void sete() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

void oito() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void nove() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}