#include <stdio.h>

int main(){

   //Definindo as variaveis de acordo com seu tipo
   char estado[10];
   char codigo[5];
   char nome_cidade[40];
   int populacao;
   float area_km;
   float pib;
   int pontos_turisticos;
   

   //Perguntas para a carta 1 --->
   
   printf("CARTA 1\n");
   //Criando uma pergunta (entrada de uma informação) direcionada a variavel estado
   printf("Forneça uma inicial para o seu ESTADO entre A até H\n");
  
   //Criando um caminho para a resposta da pergunta, onde vou guardar a resposta da pergunta dentro da variavel estado, é necessário colocar & (& = endereço) para o computador entender onde é para guardar a resposta (utilizo %s de string para representar que é uma letra/palavra)
   scanf(" %c", estado);

   //Criando uma pergunta (entrada de uma informação) direcionada a variavel codigo
   printf("Forneça um código para seu ESTADO de 01 até 04\n");

   //Criando um caminho ... linha 17 (utilizo %s de string = letras/palavras)
   scanf(" %s", codigo);

   //Criando uma pergunta (entrada de uma informação) direcionada a variavel nome_cidade
   printf("Forneça um nome para a cidade de seu ESTADO\n");

   //Criando um caminho ... linha 17 (utilizo %s de string = letra/palavra)
   scanf(" %[^\n]", nome_cidade); // Permite espaços (ex: rio de janeiro)

   //Criando uma pergunta (entrada de uma informação) direcionada a variavel populacao
   printf("Forneça a população da cidade de %s\n", nome_cidade);

   //Criando um caminho ... linha 17 (utilizo %d de decimal = numero inteiro)
   scanf(" %d", &populacao);

   //Criando uma pergunta (entrada de uma informação) direcionada a variavel area_km
   printf("Forneça um tamanho em km² para de %s\n", nome_cidade);

   //Criando um caminho ... linha 17 (utilizo %f de float = numero quebrado)
   scanf(" %f", &area_km);

   //Criando uma pergunta (entrada de uma informação) direcionada a variavel pib
   printf("Forneça um PIB para %s\n", nome_cidade);

   //Criando um caminho ... linha 17 (utilizo %f de float = numero quebrado)
   scanf(" %f", &pib);

   //Criando uma pergunta (entrada de uma informação) direcionada a variavel pontos_turisticos
   printf("Forneça quantos pontos turísticos existem em %s\n", nome_cidade);

   //Criando um caminho ... linha 17 (utilizo %d de decimal = numero inteiro)
   scanf(" %d", &pontos_turisticos);


   //Perguntas para a carta 2 --->

   //Definindo as variaveis de acordo com seu tipo
   char estado2[10];
   char codigo2[5];
   char nome_cidade2[40];
   int populacao2;
   float area_km2;
   float pib2;
   int pontos_turisticos2;

 
   printf("\nCARTA 2\n");
   printf("Forneça uma inicial para o seu SEGUNDO estado entre A até H (Não pode repetir a letra do estado anterior)\n");
   scanf(" %s", estado2);
 
   printf("Forneça um código para seu ESTADO de 01 até 04\n");
   scanf(" %s", codigo2);
 
   printf("Forneça um nome para a cidade de seu ESTADO\n");
   scanf(" %[^\n]", nome_cidade2);
 
   printf("Forneça a população da cidade de %s\n", nome_cidade2);
   scanf(" %d", &populacao2);
 
   printf("Forneça um tamanho em km² para de %s\n", nome_cidade2);
   scanf(" %f", &area_km2);
 
   printf("Forneça um PIB para %s\n", nome_cidade2);
   scanf(" %f", &pib2);
 
   printf("Forneça quantos pontos turísticos existem em %s\n", nome_cidade2);
   scanf(" %d", &pontos_turisticos2);
 

   //Definindo as váriaveis de cálculo (primeiro é necessário ter os dados para após isso realizar os calculos, por isso elas são criadas após as perguntas/entrada de dados)
   float densidade_popu = populacao / area_km;
   float pib_capital = (pib * 1000000000.0) / populacao;
   float densidade_popu2 = populacao2 / area_km2;
   float pib_capital2 = (pib2 * 1000000000.0) / populacao2;


   //Resultados CARTA 1-->
   printf("\nCarta 1 \n");
   printf("Estado: %s\n", estado);
   printf("Código: %s-%s\n", estado, codigo);
   printf("Nome da Cidade: %s\n", nome_cidade);
   printf("População: %d\n", populacao);
   printf("Área: %.2f km²\n", area_km);
   printf("PIB: %.2f bilhões de reais\n", pib);
   printf("Quantidade de Pontos Turísticos: %d\n", pontos_turisticos);
   printf("Densidade Populacional: %.2f hab/km²\n", densidade_popu);
   printf("PIB per Capita: %.2f reais\n", pib_capital);

   //Resultados CARTA 2-->
   printf("\nCarta 2 \n");
   printf("Estado: %s\n", estado2);
   printf("Código: %s-%s\n", estado2, codigo2);
   printf("Nome da Cidade: %s\n", nome_cidade2);
   printf("População: %d\n", populacao2);
   printf("Área: %.2f km²\n", area_km2);
   printf("PIB: %.2f bilhões de reais\n", pib2);
   printf("Quantidade de Pontos Turísticos: %d\n", pontos_turisticos2);
   printf("Densidade Populacional: %.2f hab/km²\n", densidade_popu2);
   printf("PIB per Capita: %.2f reais\n", pib_capital2);

   return 0;
}