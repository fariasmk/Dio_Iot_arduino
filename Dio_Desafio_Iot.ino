int celsius = 0;
int sensor = 0;

const int VENTILADOR = 11;
const int BUZINA = 12;
const int LED = 13;

const int TEMPERATURE_THRESHOLD_1 = 30;
const int TEMPERATURE_THRESHOLD_2 = 50;

void setup() {
  Serial.begin(9600);
  pinMode(VENTILADOR, OUTPUT);
  pinMode(BUZINA, OUTPUT);
  pinMode(LED, OUTPUT);
}

void readTemperature() {
  sensor = analogRead(A0);
  celsius = map(((sensor - 20) * 3.04), 0, 1023, -40, 125);
}

void controlVentilador() {
  digitalWrite(VENTILADOR, celsius >= TEMPERATURE_THRESHOLD_1 ? HIGH : LOW);
}

void controlBuzinaAndLED() {
  if (celsius > TEMPERATURE_THRESHOLD_2) {
    digitalWrite(BUZINA, HIGH);
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(BUZINA, LOW);
    digitalWrite(LED, LOW);
  }
}

void printTemperature() {
  Serial.print("Medida do sensor = ");
  Serial.println(sensor);
  Serial.print("Temperatura = ");
  Serial.print(celsius);
  Serial.println("ºC, ");
  Serial.println("   ");
}

void loop() {
  readTemperature();
  controlVentilador();
  controlBuzinaAndLED();
  printTemperature();
  
  delay(500);
}
