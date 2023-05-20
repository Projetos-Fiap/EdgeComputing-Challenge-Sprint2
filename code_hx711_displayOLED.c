// EDGE COMPUTING - SPRINT 2 - GRUPO 2 (André, Alessandra, Bryan, Vitor Maia e Lucas Feijó)

// Incluir libraries do projeto
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <HX711.h>
#include <LiquidCrystal_I2C.h>

// Definições display OLED
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 32 
#define OLED_RESET     -1 
#define SCREEN_ADDRESS 0x3C 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

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
lcd.init();
lcd.backlight();
  
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
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Peso: ");
    lcd.print(min(valor_pot, 1000));
    lcd.print("g");
    valor_anterior = valor_pot;

    if (valor_pot >= 1000) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("LIMITE DE PESO");
      lcd.setCursor(0, 1);
      lcd.print("ATINGIDO");

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

  // Lógica do botão
  if (buttonState != lastButtonState && buttonState == LOW) {
    action = (action + 1) % numActions;  // Incrementa a ação do botão
  }
  //lcd.setCursor(0, 0);
  //lcd.print("                ");  // Limpa completamente a linha

  lcd.setCursor(0, 0);
  // Exibe o texto do botão de acordo com a ação atual
  switch (action) {
    case 0:
      lcd.print("Tipo: Aluminio     ");
      break;
    case 1:
      lcd.print("Tipo: Plastico     ");
      break;
    case 2:
      lcd.print("Tipo: Vidro         ");
      break;
    // Adicione mais cases para ações adicionais, se necessário

    default:
      break;
  }

  lastButtonState = buttonState;  // Armazena o estado atual do botão
}

