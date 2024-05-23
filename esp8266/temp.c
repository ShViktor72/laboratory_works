#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

// Определение пинов
#define DHTPIN D4       // Пин, к которому подключен датчик
#define DHTTYPE DHT11   // DHT 11 (можно заменить на DHT22)
#define BLUE_LED_PIN D5 // Пин для синего светодиода
#define RED_LED_PIN D6  // Пин для красного светодиода

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();

  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);

  // Начальное состояние светодиодов
  digitalWrite(BLUE_LED_PIN, LOW);
  digitalWrite(RED_LED_PIN, LOW);
}

void loop() {
  // Чтение температуры
  float temperature = dht.readTemperature();

  // Проверка, удалось ли прочитать значение
  if (isnan(temperature)) {
    Serial.println("Ошибка чтения с датчика!");
    return;
  }

  Serial.print("Температура: ");
  Serial.print(temperature);
  Serial.println(" *C");

  // Управление светодиодами
  if (temperature < 20.0) {
    digitalWrite(BLUE_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);
  } else {
    digitalWrite(BLUE_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, HIGH);
  }

  // Задержка между измерениями
  delay(2000);
}
