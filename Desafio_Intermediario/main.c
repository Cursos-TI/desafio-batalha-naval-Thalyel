#include <stdio.h>


// Função para inicializar o tabuleiro com zeros
void iniciar_Tabuleiro (int tabuleiro[10][10]){
   for (int i = 0; i < 10; i++)
   {
      for (int j = 0; j < 10; j++)
      {
         tabuleiro[i][j] = 0;
      }  
   }
}

// Função para validar o posicionamento de um navio
int validar_Navio(int tabuleiro[10][10], int linha, int coluna, int tamanho, int horizontal) {
   if (linha < 0 || linha >= 10 || coluna < 0 || coluna >= 10) {
      return 0; // Fora dos limites
   }

   if (horizontal == 1) { // Horizontal

      if (coluna + tamanho > 10) {
      return 0;
      }
      for (int j = coluna; j < coluna + tamanho; j++) 
      {
         if (tabuleiro[linha][j] != 0) return 0;
      }
      
      } else if (horizontal == 0) // Vertical
      {
      if (linha + tamanho > 10) {
         return 0;
      }
      for (int i = linha; i < linha + tamanho; i++) 
      {
         if (tabuleiro[i][coluna] != 0) return 0;
      }

      } else if (horizontal == 3) // Diagonal ascendente
      { 
      if (linha + tamanho > 10 || coluna + tamanho > 10) {
         return 0;
      }
      for (int k = 0; k < tamanho; k++) {
         if (tabuleiro[linha + k][coluna + k] != 0) {
            return 0;
      }
      }

      } else if (horizontal == 2) { // Diagonal descendente
      if (linha + tamanho > 10 || coluna - tamanho + 1 < 0) {
         return 0;
      }
      for (int n = 0; n < tamanho; n++) {
         if (tabuleiro[linha + n][coluna - n] != 0) return 0;
      }

      } else {
         return 0; // Tipo inválido
      }
   return 1; // Posicionamento válido
}

// Função para posicionar um navio no tabuleiro
void posicionar_Navio(int tabuleiro[10][10], int linha, int coluna, int tamanho, int horizontal) {
   if (horizontal == 1) { // Horizontal
      for (int j = coluna; j < coluna + tamanho; j++) {
         tabuleiro[linha][j] = 3;
      }
   } 
   
   else if (horizontal == 0) { // Vertical
      for (int i = linha; i < linha + tamanho; i++) {
         tabuleiro[i][coluna] = 3;
      }
   } 
   
   else if (horizontal == 3) { // Diagonal ascendente
      for (int k = 0; k < tamanho; k++) {
         tabuleiro[linha + k][coluna + k] = 3;
      }
   } 
   
   else if (horizontal == 2) { // Diagonal descendente
      for (int n = 0; n < tamanho; n++) {
         tabuleiro[linha + n][coluna - n] = 3;
      }
   }
}


// Função para exibir o tabuleiro
void exibir_Tabuleiro (int tabuleiro[10][10]){
   printf("\n ");
   for (int j = 0; j < 10; j++)
   {
      printf("1 ");
   }
   printf("\n");

   for (int i = 0; i < 10; i++)
   {
      printf("1 ");
      for (int j = 0; j < 10; j++)
      {
         printf("%d ", tabuleiro[i][j]);
      }
      printf("\n");
   }

}

int main(){

   int tabuleiro[10][10];
   printf("\n*** Jogo de Batalha Naval ***\n");
 
   // Inicializar o tabuleiro
   iniciar_Tabuleiro(tabuleiro);

   // Definindo coordenadas iniciais dos navios
   int navio_Linha1 = 1, navio_Coluna1 = 7; // Navio horizontal
   int navio_Linha2 = 6, navio_Coluna2 = 0; // Navio vertical
   int navio_Linha3 = 1, navio_Coluna3 = 1; // Navio diagonal1
   int navio_Linha4 = 7, navio_Coluna4 = 7; // Navio diagonal2

   // Validar e posicionar o primeiro navio (horizontal)
   if(validar_Navio(tabuleiro, navio_Linha1, navio_Coluna1, 3, 1)){
      posicionar_Navio(tabuleiro, navio_Linha1, navio_Coluna1, 3, 1);
   } else {
      printf("Erro: Posicionamento inválido para o navio horizontal!\n");
      return 1;
   }

   // Validar e posicionar o segundo navio (vertical)
   if (validar_Navio(tabuleiro, navio_Linha2, navio_Coluna2, 3, 0)) {
      posicionar_Navio(tabuleiro, navio_Linha2, navio_Coluna2, 3, 0);
   } else {
      printf("Erro: Posicionamento inválido para o navio vertical!\n");
      return 1;
   }

   if (validar_Navio(tabuleiro, navio_Linha3, navio_Coluna3, 3, 3)) {
      posicionar_Navio(tabuleiro, navio_Linha3, navio_Coluna3, 3, 3);
   } else {
      printf("Erro: Posicionamento inválido para o navio diagonal 1!\n");
      return 1;
   }


   if (validar_Navio(tabuleiro, navio_Linha4, navio_Coluna4, 3, 2)) {
      posicionar_Navio(tabuleiro, navio_Linha4, navio_Coluna4, 3, 2);
   } else {
      printf("Erro: Posicionamento inválido para o navio diagonal 2!\n");
      return 1;
   }


   // Exibir o tabuleiro
   printf("Tabuleiro com navios posicionados:\n");
   exibir_Tabuleiro(tabuleiro);
  
   return 0;



}