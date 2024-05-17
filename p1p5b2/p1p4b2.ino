// Definición de los pines del display de 7 segmentos
int pines[7] = {2, 3, 4, 5, 6, 7, 8};

// Función para convertir kilogramos a libras
float KgALb(float kg) {
  return kg * 2.20462;
}

// Función para convertir amperios a microamperios
float AAMicroA(float amperios) {
  return amperios * 1000000;
}

// Función para configurar los pines de salida
void configurarPines() {
  for (int i = 0; i < 7; i++) {
    pinMode(pines[i], OUTPUT);
  }
}

// Función para mostrar un número en el display de 7 segmentos
void mostrarNumero(int numero) {
  // Matriz de segmentos para los números 1, 3, 5, 7, 9
  int segmentos[5][7] = {
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 0, 1, 1}  // 9
  };

  // Mostrar el número en el display
  for (int i = 0; i < 7; i++) {
    digitalWrite(pines[i], segmentos[numero][i]);
  }
}

void setup() {
  Serial.begin(9600);
  // Configurar los pines de salida
  configurarPines();

  // Ejemplo de uso de las funciones de conversión
  float kg = 5.0;
  float lb = KgALb(kg);
  Serial.print(kg);
  Serial.print(" kilogramos son ");
  Serial.print(lb);
  Serial.println(" libras");

  float amperios = 3.0;
  float microAmperios = AAMicroA(amperios);
  Serial.print(amperios);
  Serial.print(" amperios son ");
  Serial.print(microAmperios);
  Serial.println(" microamperios");
}

void loop() {
  // Mostrar la secuencia de números 1, 3, 5, 7, 9
  for (int i = 0; i < 5; i++) {
    mostrarNumero(i);
    delay(1000);
  }
}
