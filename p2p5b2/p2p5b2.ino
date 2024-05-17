int buzzer = 9;

const int LA = 440;
const int FA = 349;
const int DO = 523;
const int MI = 659;
const int SOL_ = 415;
const int SOL = 392;

int melodia[] = {
  LA, LA, LA,
  FA, DO, LA,
  FA, DO, LA,
  MI, MI, MI,
  FA, DO, SOL_, SOL,
  LA, FA, DO, LA
};

void setup() {
  pinMode(9, OUTPUT);
}

void loop() {
  for (int i=0; i<sizeof(melodia)/sizeof(int); i++) {
    tone(9, melodia[i], 500);
    delay(550);
    noTone(9);
  }
  delay(5000); // espera 5 segundos antes de repetir
}
