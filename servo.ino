#include <Arduino.h>

const int servoPin = 8;  // Пин для подключения сервопривода
const int minAngle = 0;  // Минимальный угол
const int maxAngle = 180; // Максимальный угол

void setup() {
  pinMode(servoPin, OUTPUT); // Устанавливаем пин как выход
}

void loop() {
  // Поворачиваем сервопривод от 0 до 180 градусов
  for (int pos = minAngle; pos <= maxAngle; pos++) {
    int pulseWidth = map(pos, 0, 180, 500, 2400); // Картируем угол в ширину импульса
    digitalWrite(servoPin, HIGH); // Включаем сигнал
    delayMicroseconds(pulseWidth); // Задержка в зависимости от ширины импульса
    digitalWrite(servoPin, LOW); // Выключаем сигнал
    delay(20); // Задержка для стабильности
  }
  delay(1000); // Ждем 1 секунду

  // Поворачиваем сервопривод обратно от 180 до 0 градусов
  for (int pos = maxAngle; pos >= minAngle; pos--) {
    int pulseWidth = map(pos, 0, 180, 500, 2400); // Картируем угол в ширину импульса
    digitalWrite(servoPin, HIGH); // Включаем сигнал
    delayMicroseconds(pulseWidth); // Задержка в зависимости от ширины импульса
    digitalWrite(servoPin, LOW); // Выключаем сигнал
    delay(20); // Задержка для стабильности
  }
  delay(1000); // Ждем 1 секунду
}
