#define led1 23
#define led2 22
#define botao1 19
#define botao2 18

bool estadobot1 = false;
bool ultimoestbot1 = true;

bool estadoled1 = false;

bool estadobot2 = false;
bool ultimoestbot2 = true;

bool estadoled2 = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
    estadobot1 = digitalRead(botao1);
    estadobot2 = digitalRead(botao2);
    
    Serial.print("Botão 1: ");
    Serial.print(estadobot1 ? "Solto" : "Pressionado");
    Serial.print("Botão 2: ");
    Serial.print(estadobot2 ? "Solto" : "Pressionado");

    if(estadobot1 == LOW && ultimoestbot1 == true){
        estadoled1 = !estadoled1;
        digitalWrite(led1, estadoled1);
        delay(200);
    }

    if(estadobot2 == LOW && ultimoestbot2 == true){
        estadoled2 = !estadoled2;
        digitalWrite(led2, estadoled2);
        delay(200);
    }
    delay(10);
}
