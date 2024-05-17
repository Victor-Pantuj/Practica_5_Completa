// Definición de los pines
int pines[7] = {2, 3, 4, 5, 6, 7, 8}; // Pines del display de 7 segmentos
int Buzzer = 9; // Pin del buzzer
int Rele = 10; // Pin del módulo de relés

// Función para configurar los pines de salida
void configurarPines() {
  for (int i = 0; i < 7; i++) {
    pinMode(pines[i], OUTPUT);
  }
  pinMode(Buzzer, OUTPUT);
  pinMode(Rele, OUTPUT);
}

// Función para mostrar un número en el display de 7 segmentos
void mostrarNumero(int numero) {
  // Matriz de segmentos para los números del 0 al 9
  int segmentos[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}  // 9
  };

  // Mostrar el número en el display
  for (int i = 0; i < 7; i++) {
    digitalWrite(pines[i], segmentos[numero][i]);
  }
}

// Función para emitir un pitido
void emitirPitido() {
  tone(Buzzer, 250, 2000);
}

// Función para activar el módulo de relés
void activarRele() {
  digitalWrite(Rele, HIGH);
}

void setup() {
  // Configurar los pines de salida
  configurarPines();

  // Contador de 9 a 0
  for (int i = 9; i >= 0; i--) {
    mostrarNumero(i);
    delay(1000);
  }

  // Emitir un pitido
  emitirPitido();

  // Activar el módulo de relés
  activarRele();
}

void loop() {
  // No hacer nada en el loop
}