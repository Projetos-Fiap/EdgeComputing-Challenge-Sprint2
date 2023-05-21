// Incluir libraries do projeto
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Definições display OLED
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 32 
#define OLED_RESET -1 
#define SCREEN_ADDRESS 0x3C 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Variáveis para o potenciômetro
int valor_pot = 0; 
int valor_anterior = -1;

// Variáveis para o LED e Buzzer
const int ledPin = 13;
const int buzzerPin = 12;

// Variável para controle do tempo de acionamento do buzzer
unsigned long buzzerStartTime = 0;

// Variáveis para o botão, com ciclo de 3 ações
int buttonPin = 11;
int buttonState = HIGH;
int lastButtonState = HIGH;
int numActions = 3;
int action = numActions - 1;

void setup() {
  // Inicialização do Display LCD  
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2);
  
  // Definição dos pinos
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  // Comunicação serial
  Serial.begin(9600);    
}

void loop() {
  valor_pot = analogRead(A0);
  buttonState = digitalRead(buttonPin); 

  if (valor_pot != valor_anterior) {
    valor_anterior = valor_pot;

    if (valor_pot >= 1000) {
      display.clearDisplay();
      display.setCursor(0, 0);
      display.print("LIMITE");
      display.setCursor(0, 16);
      display.print("ATINGIDO");
      display.display();

      while (valor_pot >= 1000) {
        digitalWrite(ledPin, HIGH);
        tone(buzzerPin, 1000);
        delay(2000);
        noTone(buzzerPin);
        delay(1000);
        valor_pot = analogRead(A0);
      }
    } else {
      digitalWrite(ledPin, LOW);
      noTone(buzzerPin);
    }
  }

  // Exibição do peso
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print(min(valor_pot, 1000));
  display.print("g");

  // Lógica do botão
  if (buttonState != lastButtonState && buttonState == LOW) {
    action = (action + 1) % numActions;  // Incrementa a ação do botão
  }
  
  display.setCursor(0, 16);
  // Exibe o texto do botão de acordo com a ação atual
  switch (action) {
    case 0:
      display.print("Aluminio");
      break;
    case 1:
      display.print("Plastico");
      break;
    case 2:
      display.print("Vidro");
      break;
    // Adicione mais cases para ações adicionais, se necessário

    default:
      break;
  }

  display.display();
  lastButtonState = buttonState;  // Armazena o estado atual do botão
}
