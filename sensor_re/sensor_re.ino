const int LED_VERMELHO = 9;
const int LED_AZUL = 10;
const int LED_VERDE = 11;
const int PORTA_PIEZO = A0;

const int TRIG = 3;
const int ECHO = 2;

const int distancia_obstaculo = 5;
const int distancia_amarelo = 20;
const int distancia_verde = 30;

void setup() {
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(PORTA_PIEZO, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.begin(9600);
}

void loop() {
  int distancia = sensor_morcego(TRIG, ECHO);

  // Ignora leitura 0 (sem eco / fora de alcance)
  if (distancia <= 0 || distancia > distancia_verde) {
    desligar();
    noTone(PORTA_PIEZO);
  } 
  else if (distancia <= distancia_obstaculo) {
    Serial.print("Perigo: ");
    Serial.print(distancia);
    Serial.println("cm");
    vermelho();
    tone(PORTA_PIEZO, 1200);
  } 
  else if (distancia <= distancia_amarelo) {
    Serial.print("Atencao: ");
    Serial.print(distancia);
    Serial.println("cm");
    amarelo();
    // Beep intermitente mais rápido
    tone(PORTA_PIEZO, 800);
    delay(100);
    noTone(PORTA_PIEZO);
    delay(300);
  } 
  else if (distancia <= distancia_verde) {
    Serial.print("Livre: ");
    Serial.print(distancia);
    Serial.println("cm");
    verde();
    tone(PORTA_PIEZO, 800);
    delay(100);
    noTone(PORTA_PIEZO);
    delay(500);
  }

  delay(60); // Intervalo recomendado entre disparos do sensor
}

// Cor Vermelha
void vermelho() {
  digitalWrite(LED_AZUL, LOW);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_VERMELHO, HIGH);
}

// Cor Verde
void verde() {
  digitalWrite(LED_AZUL, LOW);
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(LED_VERDE, HIGH);
}

// Cor Amarela (Vermelho + Verde)
void amarelo() {
  digitalWrite(LED_AZUL, LOW);
  digitalWrite(LED_VERMELHO, HIGH);
  digitalWrite(LED_VERDE, HIGH);
}

// Desligar tudo
void desligar() {
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AZUL, LOW);
}

int sensor_morcego(int pinotrig, int pinoecho) {
  digitalWrite(pinotrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinotrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinotrig, LOW);

  return pulseIn(pinoecho, HIGH) / 58;
} 
