#include <arduino_forRobots.h>

#define mL 9 // Pino_Velocidade do Motor Esquerdo ( 0 a 255)_ Porta IN2 ponte H;
#define mR 11 //Pino_Velocidade do Motor Direito ( 0 a 255) _ Porta IN4 ponte H;
#define dirL 8 //Pino_Direção do Motor Esquerdo: Para frente / Para trás (HIGH ou LOW)_ porta IN1 ponte H;
#define dirR 10 //Pino_Direção do Motor Direito: Para frente / Para trás (HIGH ou LOW)_ porta IN3 ponte H;

// Criando instância da classe L298NM
L298NM robot(mL, dirL, mR, dirR);

void setup() {
    robot.begin(); // Inicializa os pinos
}

void loop() {
    robot.forward(255); delay(2000);

    robot.stop(); delay(1000);

    robot.turnLeft(255); delay(1000);

    robot.stop(); delay(1000);

    robot.turnRight(255); delay(1000);

    robot.stop(); delay(1000);

    robot.backward(255); delay(2000);

    robot.stop(); delay(1000);
}