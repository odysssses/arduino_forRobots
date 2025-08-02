##Essa biblioteca é um projeto de integração automática da ponte H L298N, sensores infravermelho como TCRT5000 e sensor ultrassônico HC-SR04, além de uma extensão para guardar valores maiores com EEPROM

# Instalação
* Primeiramente, baixe o arquivo .zip do github
* Depois, extraia  o arquivo e remova o "-master"
* Em seguida, coloque a pasta extraída no diretório "libraries"
* Enfim, no topo do seu código, copie essa linha `#include <arduino_forRobots.h>`

#Introdução
A biblioteca possui três módulos, um é o chamado L298NM, que controla a ponte H, seus métodos são descritos abaixo. O segundo é chamado de autocalibralib e controla múltiplos sensores estilo TCRT5000. O último é simplesmente "ultrassom", que faz o esperado, opera HC-SR04. Todos os métodos são descritos abaixo.

#L298BNM

## Construtor
Cria uma instância como um objeto no C++ da ponte L298N com os pinos, pedindo o IN1, IN2, IN3 e IN4.

`L298NM [nome](IN1, IN2, IN3, IN4)`
## begin
Inicializa os pinos dados no construtor

`[nome].begin()`
## forward
Faz o robô andar para frente

`[nome].forward(velocidade)`

Dica: Para fazer o robô por determinado tempo, use a função builtin `delay(tempo)` após essa função. Isso vale para todas as próximas funções
## backward
Faz o robô andar para trás

`[nome].backward(velocidade)`
## turnLeft
Faz o robô virar para a esquerda

`[nome].turnLeft(velocidade)`
## turnRight
Faz o robô virar para a direita

`[nome].turnRight(velocidade)`
## stop
Faz o robô parar

`[nome].stop`
 
#autocalibralib

## Construtor
Define um sensor e um LED (opcional), para calibração e inicia os pinos.

`LineSensor [nome]([pino do sensor], [pino do LED])`
## calibrate
calibra o sensor, lendo o sensor em certo momento e interpretando o valor lido como valor limiar (_threshold), para identificar se os valores lidos posteriormente representam a cor preta ou branca. Indicado por LED.

`[nome].calibrate()`
## isBlack
lê o sensor e baseia-se no valor _threshold (margem, ou valor limiar) definido com `setThreshold()` para deduzir se o valor lido representa ou não a cor preta. Retorna 1 (preto) ou 0 (branco). 

`[var] = [nome].isBlack()`
## read
Apenas lê o sensor e retorna o valor bruto.

`[var] = [nome].read()`
### setThreshold
Define o _threshold (margem ou valor limiar) para deduzir se o valor lido representa ou não a cor preta de maneira manual.

`[nome].setThreshold([valor])`
## getThreshold
Retorna o valor _threshold

`[var] = [nome].getThreshold()`
## blinkLED
Usada internamente, pisca o LED posto no construtor um número [times] de vezes

`[nome].blinkLED([times])`

## EXEMPLOS

### Exemplo 1

calibra o sensor e guarda o valor limiar na placa, então começa a ler valores e deduzir se são pretos ou não, baseado em tal valor

### Exemplo 2

Utiliza do valor armazenado na placa para deduzir a cor da linha

### Exemplo 3

Assume um valor limiar e o usa para deduzir a cor da linha

#ultrassom

# FUNÇÕES 

## Construtor
Define uma instância de sensor ultrassom como objeto, pedindo apenas os pinos trig e echo do sensor

`ultrassom [nome]([trig], [echo])`
## getDistance
Retorna a distância de um objeto lido pelo sensor em centímetros

`long [val] = [nome].getDistance()`
## setMargin
Redefine a margem para a próxima função

`[nome].setMargin([margem])`
## checkObstacle
Retorna se há ou não um obstáculo à frente do sensor, baseando-se na margem estabelecida na última função

`bool [val] = [nome].checkObstacle()`
## EXEMPLO
Testa todas as funções da biblioteca definindo um sensor com os pinos padrão 3 e 5 (podem ser alterados no código). Mostra no console a distância em centímetros e se há ou não um obstáculo perto 

#EEPROM2byte

##rode EEPROM2byte [nome] no início do código para inicializar o serviço

##writeEEPROM
Toma como argumento primeiramente o endereço na memória do EEPROM a ser utilizado (também usa o próximo, por exemplo, se for dado 1, usará também o 2, então tente espaçar seus endereços por um, de 2 em 2) e secundariamente o valor a ser armazenado, que é no máximo ~65000

`[nome].writeEEPROM([endereço], [valor])`
##readEEPROM
Toma como argumento um só endereço, que é o que foi dado no writeEEPROM, mas lê dois (esse e o próximo).

`[nome].readEEPROM([endereço])`
