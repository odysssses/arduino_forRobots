#include "ultrassom.h"

ultrassom::ultrassom(int trig, int echo) {
    _trig = trig; // Pinos
    _echo = echo;
    _distMargin = 15; // Padrão, pode ser alterado

    pinMode(_trig, OUTPUT);
    pinMode(_echo, INPUT);
}

long ultrassom::getDistance() {
    digitalWrite(_trig, LOW); //Envia uma onda de ultrassom
    delayMicroseconds(2);
    digitalWrite(_trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trig, LOW);
    long duration = pulseIn(_echo, HIGH); //Recebe de volta a onda calculando a duração que demorou para voltar
    long distance = _microsecsToCentimeters(duration); //Transfere a duração para distância
    return distance;
}

void ultrassom::setMargin(long distMargin) {
    _distMargin = distMargin;
}

bool ultrassom::checkObstacle() {
    long dist = getDistance();
    return (dist <= _distMargin);
}

long ultrassom::_microsecsToCentimeters(long microsecs) {
    return microsecs / 29 / 2; //Dado a duração recebida do echo, retorna o valor em centimetros
}
