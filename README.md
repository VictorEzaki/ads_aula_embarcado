**Alunos:** Felipe e Victor

# Giroflex
 
Este projeto utiliza uma placa **arduino uno** para criar um giroflex
 
---
 
## Componentes Utilizados
 
* 1x Placa **arduino uno**
* 1x LED Vermelho
* 1x LED Azul
* 1x Buzzer 
* Resistores 
* Cabos de conexão
* Protoboard
 
---
 
## Esquema de Conexão (Pinout)
 
| Componente | Pino na BlackBoard | Tipo de Pino |
| :--- | :--- | :--- |
| **LED Azul** | Porta 5 | Digital (Saída) |
| **LED Vermelho** | Porta 6 | Digital (Saída) |
| **Buzzer** | Porta A0 | Analógico / Digital (Saída) |
 
---
 
## Como o Código Funciona
 
O código está dividido em duas partes principais:
 
1. **`setup()`**:
   * Configura as portas dos LEDs (`LED_AZUL` e `LED_VERMELHO`) e do buzzer (`PORTA_PIEZO`) como saídas (`OUTPUT`).
 
2. **`loop()`**:
   * **Fase 1**: chama método azul.
   * **Fase 2**: aplica um delay de 250 ms.
   * **Fase 3**: chama método vermelho.
   * **Fase 4**: aplica um delay de 250 ms.
   * O ciclo se repete de forma contínua.
  
3. **`azul()`**:
   * Desliga o led vermelho e liga o azul com `tone(PORTA_PIEZO, 1200);`
  
4. **`vermelho()`**:
   * Desliga o led azul e liga o vermelho com `tone(PORTA_PIEZO, 1400);`
 
---
 
## Como Executar o Projeto
 
1. Conecte a sua **Arduino uno** ao computador utilizando um cabo USB compatível.
2. Abra a **Arduino IDE**.
3. Monte o circuito na protoboard seguindo a tabela de conexões acima.
4. Copie o código fonte deste repositório e cole na Arduino IDE.
5. Selecione a placa correta em **Ferramentas > Placa** (como a BlackBoard é compatível com o Arduino Uno, selecione **Arduino Uno**) e escolha a porta COM correspondente em **Ferramentas > Porta**.
6. Clique no botão **Carregar** (seta para a direita) para enviar o código para a placa.

---

# Sensor de Ré

Este projeto implementa um assistente de estacionamento (sensor de ré) utilizando um sensor ultrassônico, LEDs de sinalização e um buzzer com avisos sonoros progressivos.

---

## Componentes Utilizados

* 1x Placa **Arduino Uno**
* 1x Sensor Ultrassônico HC-SR04
* 1x LED RGB (ou 3 LEDs individuais: Vermelho, Verde e Azul)
* 1x Buzzer Piezoelétrico
* Resistores para os LEDs
* Cabos de conexão
* Protoboard

---

## Esquema de Conexão (Pinout)

| Componente | Pino no Arduino | Tipo de Pino |
| :--- | :--- | :--- |
| **Sensor Ultrassônico (TRIG)** | Porta 3 | Digital (Saída) |
| **Sensor Ultrassônico (ECHO)** | Porta 2 | Digital (Entrada) |
| **LED Vermelho** | Porta 9 | Digital (Saída) |
| **LED Azul** | Porta 10 | Digital (Saída) |
| **LED Verde** | Porta 11 | Digital (Saída) |
| **Buzzer Piezo** | Porta A0 | Analógico / Digital (Saída) |

---

## Como o Código Funciona

1. **`setup()`**:
   * Configura os pinos dos LEDs, Buzzer e TRIG como `OUTPUT`, e o ECHO como `INPUT`.
   * Inicializa a comunicação Serial a 9600 bps.

2. **`sensor_morcego()`**:
   * Dispara um pulso ultrassônico no pino TRIG por 10 microssegundos.
   * Mede o tempo de retorno no pino ECHO com `pulseIn()` e divide por 58 para obter a distância em centímetros.

3. **`loop()`**:
   * Obtém a distância calculada e atua conforme a proximidade:
     * **Sem obstáculo / Fora de alcance (> 30 cm ou <= 0 cm)**: Apaga os LEDs e desativa o som.
     * **Livre (entre 21 cm e 30 cm)**: Liga o LED Verde e emite bips espaçados no buzzer (100 ms bip, 500 ms pausa).
     * **Atenção (entre 6 cm e 20 cm)**: Liga os LEDs Vermelho e Verde (formando luz Amarela) com bips mais rápidos (100 ms bip, 300 ms pausa).
     * **Perigo (<= 5 cm)**: Liga o LED Vermelho e aciona tom contínuo de 1200 Hz no buzzer.

---

## Como Executar o Projeto

1. Conecte a sua **Arduino Uno** ao computador via cabo USB.
2. Abra a **Arduino IDE**.
3. Monte o circuito na protoboard de acordo com a tabela de conexões.
4. Abra o arquivo `sensor_re/sensor_re.ino`.
5. Selecione a placa **Arduino Uno** e a porta correta em **Ferramentas**.
6. Clique em **Carregar**. Aproxime objetos do sensor ultrassônico e acompanhe os alertas visuais, sonoros e as mensagens na Serial.

---

# Varredura com Servo Motor

Este projeto realiza a movimentação angular contínua de vai-e-vem com um servo motor, permitindo calibrar a amplitude e a velocidade do movimento através de dois potenciômetros.

---

## Componentes Utilizados

* 1x Placa **Arduino Uno**
* 1x Servo Motor (ex: SG90)
* 2x Potenciômetros lineares de 10kΩ
* Cabos de conexão
* Protoboard

---

## Esquema de Conexão (Pinout)

| Componente | Pino no Arduino | Tipo de Pino |
| :--- | :--- | :--- |
| **Sinal do Servo Motor** | Porta 9 | Digital PWM (Saída) |
| **Potenciômetro de Velocidade** | Porta A0 | Analógico (Entrada) |
| **Potenciômetro de Ângulo (Amplitude)** | Porta A1 | Analógico (Entrada) |

---

## Como o Código Funciona

1. **`setup()`**:
   * Associa o servo motor ao pino 9 utilizando `servo_motor.attach(9)`.
   * Define a posição inicial em 90 graus.

2. **`loop()`**:
   * Lê o potenciômetro de ângulo em A1 e calcula a amplitude dinâmica do movimento mapeando a leitura para limites simétricos (`limiteSuperior` entre 95° e 170°, e `limiteInferior = 180 - limiteSuperior`).
   * Lê o potenciômetro de velocidade em A0 e mapeia a leitura para o tempo de delay entre cada passo (2 a 40 ms).
   * Incrementa ou decrementa a posição atual (`posAtual += direcao`).
   * Ao atingir os limites superior ou inferior, inverte a variável `direcao` (1 ou -1).
   * Atualiza a posição do servo motor com `servo_motor.write(posAtual)` e aguarda o tempo definido pela velocidade.

---

## Como Executar o Projeto

1. Conecte a sua **Arduino Uno** ao computador via cabo USB.
2. Abra a **Arduino IDE**.
3. Certifique-se de que a biblioteca padrão `Servo` está disponível na IDE.
4. Monte o circuito na protoboard conforme a tabela de pinos (atenção à alimentação positiva e negativa do servo e dos potenciômetros).
5. Abra o arquivo `servo_motor/servo_motor.ino`.
6. Selecione a placa **Arduino Uno** e a porta correta em **Ferramentas**.
7. Clique em **Carregar** e gire os potenciômetros para ajustar velocidade e amplitude da varredura.

---

# Alarme com LDR, Laser e Buzzer

Este projeto implementa um sistema de alarme detector de corte de feixe de luz usando um sensor LDR e um buzzer piezoelétrico.

---

## Componentes Utilizados

* 1x Placa **Arduino Uno**
* 1x Sensor LDR (Fotoresistor)
* 1x Módulo Laser (ou fonte de luz direcionada)
* 1x Buzzer Piezoelétrico
* 1x Resistor de 10kΩ (divisor de tensão com o LDR)
* Cabos de conexão
* Protoboard

---

## Esquema de Conexão (Pinout)

| Componente | Pino no Arduino | Tipo de Pino |
| :--- | :--- | :--- |
| **LDR (Divisor de Tensão)** | Porta A0 | Analógico (Entrada) |
| **Buzzer Piezo** | Porta A1 | Analógico / Digital (Saída) |

---

## Como o Código Funciona

1. **`setup()`**:
   * Define os pinos `FOTORESISTOR` e `PIEZZO` como saídas (`OUTPUT`).
   * Inicializa a comunicação Serial a 9600 bps.

2. **`loop()`**:
   * Lê o valor analógico do LDR via `analogRead(FOTORESISTOR)` e imprime na Serial.
   * Compara o valor lido com o limiar `LIMITE_LUZ` (50):
     * Se a leitura for menor que 50 (feixe de luz interrompido), aciona o buzzer com frequência de 1000 Hz de forma intermitente (150 ms ligado, 100 ms desligado).
     * Se a leitura for igual ou superior ao limite, desliga o buzzer (`noTone(PIEZZO)`).
   * Aguarda 50 ms antes da próxima iteração.

---

## Como Executar o Projeto

1. Conecte a sua **Arduino Uno** ao computador via cabo USB.
2. Abra a **Arduino IDE**.
3. Monte o circuito na protoboard conforme o esquema de conexão, alinhando o laser ao LDR.
4. Abra o arquivo `ldr_laser_piezzo/ldr_laser_piezzo.ino`.
5. Selecione a placa **Arduino Uno** e a porta correta em **Ferramentas**.
6. Clique em **Carregar**. Abra o Monitor Serial (9600 baud) para acompanhar os valores de luz lidos.

---