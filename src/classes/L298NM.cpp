#include "L298NM.h"

L298NM::L298NM(uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4) {
    _in1 = in1;
    _in2 = in2;
    _in3 = in3;
    _in4 = in4;
}

void L298NM::begin() {
    pinMode(_in1, OUTPUT);
    pinMode(_in2, OUTPUT);
    pinMode(_in3, OUTPUT);
    pinMode(_in4, OUTPUT);
    stop(); // Garante que os motores estejam parados ao iniciar
}

void L298NM::forward(uint8_t speed) {
    setMotorRight(speed, false);  // Motor direito para frente
    setMotorLeft(speed, false);   // Motor esquerdo para frente
}

void L298NM::backward(uint8_t speed) {
    setMotorRight(255-speed, true); // Motor direito para trás
    setMotorLeft(255-speed, true);  // Motor esquerdo para trás
}

void L298NM::turnLeft(uint8_t speed) {
    setMotorRight(speed, false);  // Motor direito para frente
    setMotorLeft(255-speed, true);  // Motor esquerdo para trás
}

void L298NM::turnRight(uint8_t speed) {
    setMotorRight(255-speed, true); // Motor direito para trás
    setMotorLeft(speed, false);   // Motor esquerdo para frente
}

void L298NM::stop() {
    analogWrite(_in2, 0);
    analogWrite(_in4, 0);
    digitalWrite(_in1, LOW);
    digitalWrite(_in3, LOW);
}

void L298NM::setMotorSpeed(uint8_t speedRight, uint8_t speedLeft) {
    analogWrite(_in2, speedRight);
    analogWrite(_in4, speedLeft);
}

void L298NM::setMotorRight(uint8_t speed, bool direction) {
    analogWrite(_in1, speed);
    digitalWrite(_in2, direction ? HIGH : LOW);
}

void L298NM::setMotorLeft(uint8_t speed, bool direction) {
    analogWrite(_in3, speed);
    digitalWrite(_in4, direction ? HIGH : LOW);
}
