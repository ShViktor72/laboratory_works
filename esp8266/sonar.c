#include <NewPing.h>

#define TRIGGER_PIN D2
#define ECHO_PIN D3
#define MAX_DISTANCE 200 // Максимальное расстояние для измерения (в сантиметрах)

#define GREEN_LED D4
#define YELLOW_LED D5
#define RED_LED D6

// создадим объект sonar типа NewPing. NewPing - это класс из библиотеки NewPing, для работы с ультразвуковыми датчиками расстояния.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(115200);
  
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
}

void loop() {
  delay(50); // Пауза между измерениями
  
  // Метод ping_cm() из библиотеки NewPing выполняет измерение расстояния в сантиметрах от датчика до объекта
  unsigned int distance = sonar.ping_cm(); // Измеряем расстояние в сантиметрах
  
  if (distance > 100) { // Расстояние больше 1 метра
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);
  } else if (distance > 50 && distance <= 100) { // Расстояние от 0.5 метра до 1 метра
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(RED_LED, LOW);
  } else { // Расстояние меньше 0.5 метра
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, HIGH);
  }
  
  //  вывода текста на последовательный порт (UART)
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}