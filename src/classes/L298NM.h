#ifndef L298NM_h
#define L298NM_h

#include <Arduino.h>

class L298NM {
public:
    // Construtor: inicializa os pinos para os dois motores
    L298NM(uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4);

    // Inicializa os pinos
    void begin();

    void forward(uint8_t speed);

    void backward(uint8_t speed);

    void turnLeft(uint8_t speed);

    void turnRight(uint8_t speed);

    void stop();

    // Define a velocidade de cada motor individualmente
    void setMotorSpeed(uint8_t speedRight, uint8_t speedLeft);

private:
    // Pinos do motor direito
    uint8_t _in1; // Pino de direção do motor direito
    uint8_t _in2; // Pino velocidade do motor direito

    // Pinos do motor esquerdo
    uint8_t _in3; // Pino de direção do motor esquerdo
    uint8_t _in4; // Pino velocidade do motor esquerdo

    // Funções internas para controle de motores
    void setMotorRight(uint8_t speed, bool direction);
    void setMotorLeft(uint8_t speed, bool direction);
};

#endif
