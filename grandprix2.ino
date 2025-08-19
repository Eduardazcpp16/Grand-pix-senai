// Definindo os pinos conectados ao connsil de 14 pinos
int letras[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, A0, A1, A2}; 
// Letras: G R A N D P R I X S E N A I

// Quantidade de letras (14 LEDs)
int qtdLetras = 14;

void setup() {
  // Configura todos os pinos como saída e os inicializa em LOW (apagados)
  for (int i = 0; i < qtdLetras; i++) {
    pinMode(letras[i], OUTPUT);     // Define o pino como saída
    digitalWrite(letras[i], LOW);   // Inicializa apagado
  }
}

void loop() {
  // Acende todos os LEDs ao mesmo tempo
  acenderTodos();
  
  // Espera 1 segundo (1000ms) para leitura
  delay(1000);
  
  // Acende as letras uma de cada vez em sequência
  acenderSequencia();

  // Pisca todos os LEDs ao mesmo tempo
  piscarTudo(3, 300); // Pisca todos 3 vezes com 300ms de intervalo
}

// Função para acender todos os LEDs ao mesmo tempo
void acenderTodos() {
  for (int i = 0; i < qtdLetras; i++) {
    digitalWrite(letras[i], HIGH);  // Acende o LED
  }
}

// Função para acender as letras uma de cada vez em sequência
void acenderSequencia() {
  for (int i = 0; i < qtdLetras; i++) {
    digitalWrite(letras[i], HIGH);  // Acende o LED correspondente
    delay(300);                     // Espera 300ms
    digitalWrite(letras[i], LOW);   // Apaga o LED
  }
}

// Função para piscar todos os LEDs simultaneamente
void piscarTudo(int vezes, int tempo) {
  for (int i = 0; i < vezes; i++) {
    // Acende todos os LEDs
    for (int j = 0; j < qtdLetras; j++) {
      digitalWrite(letras[j], HIGH);
    }
    delay(tempo); // Espera o tempo determinado
    
    // Apaga todos os LEDs
    for (int j = 0; j < qtdLetras; j++) {
      digitalWrite(letras[j], LOW);
    }
    delay(tempo); // Espera o tempo determinado
  }
}