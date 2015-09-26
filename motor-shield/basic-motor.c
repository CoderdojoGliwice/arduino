// Ustalenie numerów pinów
#define DIRECTION 12
#define SPEED 3
#define BREAK 9
#define CURRENT 0

// Zmienna przechowująca kierunek obrotów
byte dir = LOW;

void setup()
{
  // Ustawienie kierunku wyjść cyfrowych
  pinMode(DIRECTION, OUTPUT);
  pinMode(SPEED, OUTPUT);
  pinMode(BREAK, OUTPUT);

  // Włączenie hamulca
  digitalWrite(BREAK, HIGH);

  // Ustawienie kierunku
  digitalWrite(DIRECTION, dir);
}

void loop()
{
  // Wyłączenie hamulca
  digitalWrite(BREAK, LOW);

  // Przyspieszanie silnika do maksymalnych obrotów
  // w ciągu 10 s
  for (byte speed=0; speed<=255; speed++)
  {
    analogWrite(SPEED, speed);
    delay(40);
  }

  // Hamowanie silnika wsadw ciągu 3 s
  digitalWrite(BREAK, HIGH);
  delay(3000);

  // Ustawienie kierunku na odwrotny
  dir = -dir;
  digitalWrite(DIRECTION, dir);
}

