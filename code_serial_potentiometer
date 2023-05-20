// SPRINT 02: EDGE COMPUTING
// -------------------------

// Adicionamos as bibliotecas que serão utilizadas
#include <Wire.h>
#include <LiquidCrystal.h>

// LCD 
const int RS = 9, EN = 8, DB4 = 5, DB5 = 4, DB6 = 3, DB7 = 2;
LiquidCrystal lcd(RS, EN, DB4, DB5, DB6, DB7);

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
lcd.begin(16,2);
  
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
