#include <stdio.h>

int main(){

   // Definindo as variaveis de acordo com seu tipo
   char estado[3], codigo[5], nome_cidade[40];
   unsigned long int populacao;
   float area_km, pib;
   int pontos_turisticos;
   

   // Perguntas para a carta 1 --->
   
   printf("CARTA 1\n");
   // Criando uma pergunta (entrada de uma informação) direcionada a variavel estado
   printf("Forneça uma inicial para o seu ESTADO entre A até H\n");
  
   // Criando um caminho para a resposta da pergunta, onde vou guardar a resposta da pergunta dentro da variavel estado, é necessário colocar & (& = endereço) para o computador entender onde é para guardar a resposta (utilizo %s de string para representar que é uma letra/palavra)
   scanf(" %c", estado);

   // Criando uma pergunta (entrada de uma informação) direcionada a variavel codigo
   printf("Forneça um código para seu ESTADO de 01 até 04\n");

   // Criando um caminho ... linha 17 (utilizo %s de string = letras/palavras)
   scanf(" %s", codigo);

   // Criando uma pergunta (entrada de uma informação) direcionada a variavel nome_cidade
   printf("Forneça um nome para a cidade de seu ESTADO\n");

   // Criando um caminho ... linha 17 (utilizo %39[^\n] , este é um formato para permitir que string possua espaço entre palavras)
   scanf(" %39[^\n]", nome_cidade); // Permite espaços (ex: rio de janeiro)

   // Criando uma pergunta (entrada de uma informação) direcionada a variavel populacao
   printf("Forneça a população da cidade de %s\n", nome_cidade);

   // Criando um caminho ... linha 17 (utilizo %lu para unsigned long int)
   scanf(" %lu", &populacao);

   // Criando uma pergunta (entrada de uma informação) direcionada a variavel area_km
   printf("Forneça um tamanho em km² para de %s\n", nome_cidade);

   // Criando um caminho ... linha 17 (utilizo %f de float = numero quebrado)
   scanf(" %f", &area_km);

   // Criando uma pergunta (entrada de uma informação) direcionada a variavel pib
   printf("Forneça um PIB para %s\n", nome_cidade);

   // Criando um caminho ... linha 17 (utilizo %f de float = numero quebrado)
   scanf(" %f", &pib);

   // Criando uma pergunta (entrada de uma informação) direcionada a variavel pontos_turisticos
   printf("Forneça quantos pontos turísticos existem em %s\n", nome_cidade);

   // Criando um caminho ... linha 17 (utilizo %d de decimal = numero inteiro)
   scanf(" %d", &pontos_turisticos);


   // Perguntas para a carta 2 --->

   // Definindo as variaveis de acordo com seu tipo
   char estado2[3], codigo2[5], nome_cidade2[40];
   unsigned long int populacao2;
   float area_km2, pib2;
   int pontos_turisticos2;

 
   printf("\nCARTA 2\n");
   printf("Forneça uma inicial para o seu SEGUNDO estado entre A até H (Não pode repetir a letra do estado anterior)\n");
   scanf(" %c", estado2);
 
   printf("Forneça um código para seu ESTADO de 01 até 04\n");
   scanf(" %s", codigo2);

   printf("Forneça um nome para a cidade de seu ESTADO\n");
   scanf(" %39[^\n]", nome_cidade2);

   printf("Forneça a população da cidade de %s\n", nome_cidade2);
   scanf(" %lu", &populacao2);

   printf("Forneça um tamanho em km² para de %s\n", nome_cidade2);
   scanf(" %f", &area_km2);

   printf("Forneça um PIB para %s\n", nome_cidade2);
   scanf(" %f", &pib2);

   printf("Forneça quantos pontos turísticos existem em %s\n", nome_cidade2);
   scanf(" %d", &pontos_turisticos2);


   // Definindo as váriaveis de cálculo (primeiro é necessário ter os dados para após isso realizar os calculos, por isso elas são criadas após as perguntas/entrada de dados)
   float densidade_popu = populacao / area_km;
   float pib_capital = (pib * 1000000000.0) / populacao;
   float densidade_popu2 = populacao2 / area_km2;
   float pib_capital2 = (pib2 * 1000000000.0) / populacao2;

   // Resultados CARTA 1-->
   printf("\nCarta 1 \n");
   printf("Estado: %c\n", estado);
   printf("Código: %c-%c\n", estado, codigo);
   printf("Nome da Cidade: %s\n", nome_cidade);
   printf("População: %lu\n", populacao);
   printf("Área: %.2f km²\n", area_km);
   printf("PIB: %.2f bilhões de reais\n", pib);
   printf("Quantidade de Pontos Turísticos: %d\n", pontos_turisticos);
   printf("Densidade Populacional: %.2f hab/km²\n", densidade_popu);
   printf("PIB per Capita: %.2f reais\n", pib_capital);

   // Resultados CARTA 2-->
   printf("\nCarta 2 \n");
   printf("Estado: %c\n", estado2);
   printf("Código: %c-%c\n", estado2, codigo2);
   printf("Nome da Cidade: %s\n", nome_cidade2);
   printf("População: %lu\n", populacao2);
   printf("Área: %.2f km²\n", area_km2);
   printf("PIB: %.2f bilhões de reais\n", pib2);
   printf("Quantidade de Pontos Turísticos: %d\n", pontos_turisticos2);
   printf("Densidade Populacional: %.2f hab/km²\n", densidade_popu2);
   printf("PIB per Capita: %.2f reais\n", pib_capital2);


   // Comparação entre as cartas -->

   int atributo_Escolhido, atributo_Escolhido2;

   // Criando um menu interativo para escolha
   printf("\n*** Selecione o primeiro atributo para comparação ***\n");
   printf("1 - População \n");
   printf("2 - Área \n");
   printf("3 - PIB \n");
   printf("4 - Número de pontos turísticos \n");
   printf("5 - Densidade Populacional \n");
   scanf(" %d", &atributo_Escolhido);

   switch (atributo_Escolhido)
   {
   case 1:
   printf("\n*** Selecione o segundo atributo para comparação ***\n");
   printf("1 - Área \n");
   printf("2 - PIB \n");
   printf("3 - Número de pontos turísticos \n");
   printf("4 - Densidade Populacional \n");
   scanf("%d", &atributo_Escolhido2);

   
      switch (atributo_Escolhido2)
      {
      case 1:
      printf("\n### Comparação de cartas ###\n");
      printf("%s vs %s \n", nome_cidade, nome_cidade2);
      printf("Atributos escolhidos: População e Área\n");
      printf("%s --->\nPopulação: %lu \nÁrea: %.2f\nValor combinado: %.2f\n", nome_cidade, populacao, area_km, (populacao + area_km)); // Valores do atributo da cidade 1
      printf("%s --->\nPopulação: %lu \nÁrea: %.2f\nValor combinado: %.2f\n", nome_cidade2, populacao2, area_km2, (populacao2 + area_km2)); // Valores do atributo da cidade 2

      printf("VENCEDOR: %s\n", ((populacao + area_km) > (populacao2 + area_km2)) ? nome_cidade : nome_cidade2);
   
      if ((populacao + area_km) == (populacao2 + area_km2))
      {
         printf("%s e %s empataram!\n", nome_cidade, nome_cidade2);
      }

         break;
         

      case 2:
      printf("\n### Comparação de cartas ###\n");
      printf("%s vs %s \n", nome_cidade, nome_cidade2);
      printf("Atributos escolhidos: População e PIB\n");
      printf("%s --->\nPopulação: %lu \nPIB: %.2f\nValor combinado: %.2f\n", nome_cidade, populacao, pib, (populacao + pib)); // Valores do atributo da cidade 1
      printf("%s --->\nPopulação: %lu \nPIB: %.2f\nValor combinado: %.2f\n", nome_cidade2, populacao2, pib2, (populacao2 + pib2)); // Valores do atributo da cidade 2
      
      printf("VENCEDOR: %s\n", ((populacao + pib) > (populacao2 + pib2)) ? nome_cidade : nome_cidade2);
   
      if ((populacao + pib) == (populacao2 + pib2))
      {
         printf("%s e %s empataram!\n", nome_cidade, nome_cidade2);
      }

         break;

      case 3:
      printf("\n### Comparação de cartas ###\n");
      printf("%s vs %s \n", nome_cidade, nome_cidade2);
      printf("Atributos escolhidos: População e Pontos Turísticos\n");
      printf("%s --->\nPopulação: %lu \nPontos Turísticos: %d\nValor combinado: %.2f\n", nome_cidade, populacao, pontos_turisticos, (populacao + pontos_turisticos)); // Valores do atributo da cidade 1
      printf("%s --->\nPopulação: %lu \nPontos Turísticos: %d\nValor tcombinado: %.2f\n", nome_cidade2, populacao2, pontos_turisticos2, (populacao2 + pontos_turisticos2)); // Valores do atributo da cidade 2
      
      printf("VENCEDOR: %s\n", ((populacao + pontos_turisticos) > (populacao2 + pontos_turisticos2)) ? nome_cidade : nome_cidade2);
   
      if ((populacao + pontos_turisticos) == (populacao2 + pontos_turisticos2))
      {
         printf("%s e %s empataram!\n", nome_cidade, nome_cidade2);
      }

         break;

      case 4:
      printf("\n### Comparação de cartas ###\n");
      printf("%s vs %s \n", nome_cidade, nome_cidade2);
      printf("Atributos escolhidos: População e Densidade Populacional\n");
      printf("%s --->\nPopulação: %lu \nDensidade Populacional: %.2f\nValor combinado: %.2f\n", nome_cidade, populacao, densidade_popu, (populacao + densidade_popu)); // Valores do atributo da cidade 1
      printf("%s --->\nPopulação: %lu \nDensidade Populacional: %.2f\nValor combinado: %.2f\n", nome_cidade2, populacao2, densidade_popu2, (populacao2 + densidade_popu2)); // Valores do atributo da cidade 2

      printf("VENCEDOR: %s\n", ((populacao + densidade_popu) > (populacao2 + densidade_popu2)) ? nome_cidade : nome_cidade2);
   
      if ((populacao + densidade_popu) == (populacao2 + densidade_popu2))
      {
         printf("%s e %s empataram!\n", nome_cidade, nome_cidade2);
      }

         break;
      default:
      printf("Valor inválido, tente novamente");
      }
      break;

   case 2:
   printf("\n*** Selecione o segundo atributo para comparação ***\n");
   printf("1 - População \n");
   printf("2 - PIB \n");
   printf("3 - Número de pontos turísticos \n");
   printf("4 - Densidade Populacional \n");
   scanf(" %d", &atributo_Escolhido2);

      switch (atributo_Escolhido2)
      {
      case 1:
      printf("\n### Comparação de cartas ###\n");
      printf("%s vs %s \n", nome_cidade, nome_cidade2);
      printf("Atributos escolhidos: Área e População\n");
      printf("%s --->\nÁrea: %.2f \nPopulação: %lu\nValor combinado: %.2f\n", nome_cidade, area_km, populacao, (populacao + area_km)); // Valores do atributo da cidade 1
      printf("%s --->\nÁrea: %.2f \nPopulação: %lu\nValor combinado: %.2f\n", nome_cidade2, area_km2, populacao2, (populacao2 + area_km2)); // Valores do atributo da cidade 2

      printf("VENCEDOR: %s\n", ((populacao + area_km) > (populacao2 + area_km2)) ? nome_cidade : nome_cidade2);
   
      if ((populacao + area_km) == (populacao2 + area_km2))
      {
         printf("%s e %s empataram!\n", nome_cidade, nome_cidade2);
      }

         break;

      case 2:
      printf("\n### Comparação de cartas ###\n");
      printf("%s vs %s \n", nome_cidade, nome_cidade2);
      printf("Atributos escolhidos: Área e PIB\n");
      printf("%s --->\nÁrea: %.2f \nPIB: %.2f\nValor combinado: %.2f\n", nome_cidade, area_km, pib, (area_km + pib)); // Valores do atributo da cidade 1
      printf("%s --->\nÁrea: %.2f \nPIB: %.2f\nValor combinado: %.2f\n", nome_cidade2, area_km2, pib2, (area_km2 + pib2)); // Valores do atributo da cidade 2

      printf("VENCEDOR: %s\n", ((pib + area_km) > (pib2 + area_km2)) ? nome_cidade : nome_cidade2);
   
      if ((pib + area_km) == (pib2 + area_km2))
      {
         printf("%s e %s empataram!\n", nome_cidade, nome_cidade2);
      }

         break;

      case 3:
      printf("\n### Comparação de cartas ###\n");
      printf("%s vs %s \n", nome_cidade, nome_cidade2);
      printf("Atributos escolhidos: Área e Pontos Turísticos\n");
      printf("%s --->\nÁrea: %.2f \nPontos Turísticos: %d\nValor combinado: %.2f\n", nome_cidade, area_km, pontos_turisticos, (area_km + pontos_turisticos)); // Valores do atributo da cidade 1
      printf("%s --->\nÁrea: %.2f \nPontos Turísticos: %d\nValor combinado: %.2f\n", nome_cidade2, area_km2, pontos_turisticos2, (area_km2 + pontos_turisticos2)); // Valores do atributo da cidade 2

      printf("VENCEDOR: %s\n", ((pontos_turisticos + area_km) > (pontos_turisticos2 + area_km2)) ? nome_cidade : nome_cidade2);
   
      if ((pontos_turisticos + area_km) == (pontos_turisticos2 + area_km2))
      {
         printf("%s e %s empataram!\n", nome_cidade, nome_cidade2);
      }

         break;

      case 4:
      printf("\n### Comparação de cartas ###\n");
      printf("%s vs %s \n", nome_cidade, nome_cidade2);
      printf("Atributos escolhidos: Área e Densidade Populacional\n");
      printf("%s --->\nÁrea: %.2f \nDensidade Populacional: %.2f\nValor combinado: %.2f\n", nome_cidade, area_km, densidade_popu, (area_km + densidade_popu)); // Valores do atributo da cidade 1
      printf("%s --->\nÁrea: %.2f \nDensidade Populacional: %.2f\nValor combinado: %.2f\n", nome_cidade2, area_km2, densidade_popu2, (area_km2 + densidade_popu2)); // Valores do atributo da cidade 2
         
      printf("VENCEDOR: %s\n", ((densidade_popu + area_km) > (densidade_popu2 + area_km2)) ? nome_cidade : nome_cidade2);
   
      if ((densidade_popu + area_km) == (densidade_popu2 + area_km2))
      {
         printf("%s e %s empataram!\n", nome_cidade, nome_cidade2);
      }

         break;
      default:
      printf("Valor inválido, tente novamente");
      }
      break;

   case 3:
   printf("\n*** Selecione o segundo atributo para comparação ***\n");
   printf("1 - População \n");
   printf("2 - Área \n");
   printf("3 - Número de pontos turísticos \n");
   printf("4 - Densidade Populacional \n");
   scanf(" %d", &atributo_Escolhido2);

      switch (atributo_Escolhido2)
      {
      case 1:
      printf("\n### Comparação de cartas ###\n");
      printf("%s vs %s \n", nome_cidade, nome_cidade2);
      printf("Atributos escolhidos: PIB e População\n");
      printf("%s --->\nPIB: %.2f \nPopulação: %lu\nValor combinado: %.2f\n", nome_cidade, pib, populacao, (pib + populacao)); // Valores do atributo da cidade 1
      printf("%s --->\nPIB: %.2f \nPopulação: %lu\nValor combinado: %.2f\n", nome_cidade2, pib2, populacao2, (pib2 + populacao2)); // Valores do atributo da cidade 2

      printf("VENCEDOR: %s\n", ((populacao + pib) > (populacao2 + pib2)) ? nome_cidade : nome_cidade2);
   
      if ((populacao + pib) == (populacao2 + pib2))
      {
         printf("%s e %s empataram!\n", nome_cidade, nome_cidade2);
      }

         break;

      case 2:
      printf("\n### Comparação de cartas ###\n");
      printf("%s vs %s \n", nome_cidade, nome_cidade2);
      printf("Atributos escolhidos: PIB e Área\n");
      printf("%s --->\nPIB: %.2f \nÁrea: %.2f\nValor combinado: %.2f\n", nome_cidade, pib, area_km, (pib + area_km)); // Valores do atributo da cidade 1
      printf("%s --->\nPIB: %.2f \nÁrea: %.2f\nValor combinado: %.2f\n", nome_cidade2, pib2, area_km2, (pib2 + area_km2)); // Valores do atributo da cidade 2

      printf("VENCEDOR: %s\n", ((pib + area_km) > (pib2 + area_km2)) ? nome_cidade : nome_cidade2);
   
      if ((pib + area_km) == (pib2 + area_km2))
      {
         printf("%s e %s empataram!\n", nome_cidade, nome_cidade2);
      }

         break;

      case 3:
      printf("\n### Comparação de cartas ###\n");
      printf("%s vs %s \n", nome_cidade, nome_cidade2);
      printf("Atributos escolhidos: PIB e Pontos Turísticos\n");
      printf("%s --->\nPIB: %.2f \nPontos Turísticos: %d\nValor combinado: %.2f\n", nome_cidade, pib, pontos_turisticos, (pib + pontos_turisticos)); // Valores do atributo da cidade 1
      printf("%s --->\nPIB: %.2f \nPontos Turísticos: %d\nValor combinado: %.2f\n", nome_cidade2, pib2, pontos_turisticos2, (pib2 + pontos_turisticos2)); // Valores do atributo da cidade 2
      
      printf("VENCEDOR: %s\n", ((pib + pontos_turisticos) > (pib2 + pontos_turisticos2)) ? nome_cidade : nome_cidade2);
   
      if ((pib + pontos_turisticos) == (pib2 + pontos_turisticos2))
      {
         printf("%s e %s empataram!\n", nome_cidade, nome_cidade2);
      }

         break;

      case 4:
      printf("\n### Comparação de cartas ###\n");
      printf("%s vs %s \n", nome_cidade, nome_cidade2);
      printf("Atributos escolhidos: PIB e Densidade Populacional\n");
      printf("%s --->\nPIB: %.2f \nDensidade Populacional: %.2f\nValor combinado: %.2f\n", nome_cidade, pib, densidade_popu, (pib + densidade_popu)); // Valores do atributo da cidade 1
      printf("%s --->\nPIB: %.2f \nDensidade Populacional: %.2f\nValor combinado: %.2f\n", nome_cidade2, pib2, densidade_popu2, (pib2 + densidade_popu2)); // Valores do atributo da cidade 2
         
      printf("VENCEDOR: %s\n", ((pib + densidade_popu) > (pib2 + densidade_popu2)) ? nome_cidade : nome_cidade2);
   
      if ((pib + densidade_popu) == (pib2 + densidade_popu2))
      {
         printf("%s e %s empataram!\n", nome_cidade, nome_cidade2);
      }

         break;
      default:
      printf("Valor inválido, tente novamente");
      }
      break;

   case 4:
   printf("\n*** Selecione o segundo atributo para comparação ***\n");
   printf("1 - População \n");
   printf("2 - Área \n");
   printf("3 - PIB \n");
   printf("4 - Densidade Populacional \n");
   scanf(" %d", &atributo_Escolhido2);

      switch (atributo_Escolhido2)
      {
      case 1:
      printf("\n### Comparação de cartas ###\n");
      printf("%s vs %s \n", nome_cidade, nome_cidade2);
      printf("Atributos escolhidos: Pontos Turísticos e População\n");
      printf("%s --->\nPontos Turísticos: %d \nPopulação: %lu\nValor combinado: %.2f\n", nome_cidade, pontos_turisticos, populacao, (pontos_turisticos + populacao)); // Valores do atributo da cidade 1
      printf("%s --->\nPontos Turísticos: %d \nPopulação: %lu\nValor combinado: %.2f\n", nome_cidade2, pontos_turisticos2, populacao2, (pontos_turisticos2 + populacao2)); // Valores do atributo da cidade 2

      printf("VENCEDOR: %s\n", ((pontos_turisticos + populacao) > (pontos_turisticos2 + populacao2)) ? nome_cidade : nome_cidade2);
   
      if ((pontos_turisticos + populacao) == (pontos_turisticos2 + populacao2))
      {
         printf("%s e %s empataram!\n", nome_cidade, nome_cidade2);
      }

         break;

      case 2:
      printf("\n### Comparação de cartas ###\n");
      printf("%s vs %s \n", nome_cidade, nome_cidade2);
      printf("Atributos escolhidos: Pontos Turísticos e Área\n");
      printf("%s --->\nPontos Turísticos: %d \nÁrea: %.2f\nValor combinado: %.2f\n", nome_cidade, pontos_turisticos, area_km, (pontos_turisticos + area_km)); // Valores do atributo da cidade 1
      printf("%s --->\nPontos Turísticos: %d \nÁrea: %.2f\nValor combinado: %.2f\n", nome_cidade2, pontos_turisticos2, area_km2, (pontos_turisticos2 + area_km2)); // Valores do atributo da cidade 2

      printf("VENCEDOR: %s\n", ((pontos_turisticos + area_km) > (pontos_turisticos2 + area_km2)) ? nome_cidade : nome_cidade2);
   
      if ((pontos_turisticos + area_km) == (pontos_turisticos2 + area_km2))
      {
         printf("%s e %s empataram!\n", nome_cidade, nome_cidade2);
      }

         break;

      case 3:
      printf("\n### Comparação de cartas ###\n");
      printf("%s vs %s \n", nome_cidade, nome_cidade2);
      printf("Atributos escolhidos: Pontos Turísticos e PIB\n");
      printf("%s --->\nPontos Turísticos: %d \nPIB: %.2f\nValor combinado: %.2f\n", nome_cidade, pontos_turisticos, pib, (pontos_turisticos + pib)); // Valores do atributo da cidade 1
      printf("%s --->\nPontos Turísticos: %d \nPIB: %.2f\nValor combinado: %.2f\n", nome_cidade2, pontos_turisticos2, pib2, (pontos_turisticos2 + pib2)); // Valores do atributo da cidade 2
      
      printf("VENCEDOR: %s\n", ((pontos_turisticos + pib) > (pontos_turisticos2 + pib2)) ? nome_cidade : nome_cidade2);
   
      if ((pontos_turisticos + pib) == (pontos_turisticos2 + pib2))
      {
         printf("%s e %s empataram!\n", nome_cidade, nome_cidade2);
      }

         break;

      case 4:
      printf("\n### Comparação de cartas ###\n");
      printf("%s vs %s \n", nome_cidade, nome_cidade2);
      printf("Atributos escolhidos: Pontos Turísticos e Densidade Populacional\n");
      printf("%s --->\nPontos Turísticos: %d \nDensidade Populacional: %.2f\nValor combinado: %.2f\n", nome_cidade, pontos_turisticos, densidade_popu, (pontos_turisticos + densidade_popu)); // Valores do atributo da cidade 1
      printf("%s --->\nPontos Turísticos: %d \nDensidade Populacional: %.2f\nValor combinado: %.2f\n", nome_cidade2, pontos_turisticos2, densidade_popu2, (pontos_turisticos2 + densidade_popu2)); // Valores do atributo da cidade 2
         
      printf("VENCEDOR: %s\n", ((pontos_turisticos + densidade_popu) > (pontos_turisticos2 + densidade_popu2)) ? nome_cidade : nome_cidade2);
   
      if ((pontos_turisticos + densidade_popu) == (pontos_turisticos2 + densidade_popu2))
      {
         printf("%s e %s empataram!\n", nome_cidade, nome_cidade2);
      }

         break;
      default:
      printf("Valor inválido, tente novamente");
      }
      break;

   case 5:
   printf("\n*** Selecione o segundo atributo para comparação ***\n");
   printf("1 - População \n");
   printf("2 - Área \n");
   printf("3 - PIB \n");
   printf("4 - Número de pontos turísticos \n");
   scanf(" %d", &atributo_Escolhido2);

      switch (atributo_Escolhido2)
      {
      case 1:
      printf("\n### Comparação de cartas ###\n");
      printf("%s vs %s \n", nome_cidade, nome_cidade2);
      printf("Atributos escolhidos: Densidade Populacional e População\n");
      printf("%s --->\nDensidade Populacional: %.2f \nPopulação: %lu\nValor combinado: %.2f\n", nome_cidade, densidade_popu, populacao, (densidade_popu + populacao)); // Valores do atributo da cidade 1
      printf("%s --->\nDensidade Populacional: %.2f \nPopulação: %lu\nValor combinado: %.2f\n", nome_cidade2, densidade_popu2, populacao2, (densidade_popu2 + populacao2)); // Valores do atributo da cidade 2

      printf("VENCEDOR: %s\n", ((densidade_popu + populacao) > (densidade_popu2 + populacao2)) ? nome_cidade : nome_cidade2);
   
      if ((densidade_popu + populacao) == (densidade_popu2 + populacao2))
      {
         printf("%s e %s empataram!\n", nome_cidade, nome_cidade2);
      }

         break;

      case 2:
      printf("\n### Comparação de cartas ###\n");
      printf("%s vs %s \n", nome_cidade, nome_cidade2);
      printf("Atributos escolhidos: Densidade Populacional e Área\n");
      printf("%s --->\nDensidade Populacional: %.2f \nÁrea: %.2f\nValor combinado: %.2f\n", nome_cidade, densidade_popu, area_km, (densidade_popu + area_km)); // Valores do atributo da cidade 1
      printf("%s --->\nDensidade Populacional: %.2f \nÁrea: %.2f\nValor combinado: %.2f\n", nome_cidade2, densidade_popu2, area_km2, (densidade_popu2 + area_km2)); // Valores do atributo da cidade 2

      printf("VENCEDOR: %s\n", ((densidade_popu + area_km) > (densidade_popu2 + area_km2)) ? nome_cidade : nome_cidade2);
   
      if ((densidade_popu + area_km) == (densidade_popu2 + area_km2))
      {
         printf("%s e %s empataram!\n", nome_cidade, nome_cidade2);
      }

         break;

      case 3:
      printf("\n### Comparação de cartas ###\n");
      printf("%s vs %s \n", nome_cidade, nome_cidade2);
      printf("Atributos escolhidos: Densidade Populacional e PIB\n");
      printf("%s --->\nDensidade Populacional: %.2f \nPIB: %.2f\nValor combinado: %.2f\n", nome_cidade, densidade_popu, pib, (densidade_popu + pib)); // Valores do atributo da cidade 1
      printf("%s --->\nDensidade Populacional: %.2f \nPIB: %.2f\nValor combinado: %.2f\n", nome_cidade2, densidade_popu2, pib2, (densidade_popu2 + pib2)); // Valores do atributo da cidade 2
      
      printf("VENCEDOR: %s\n", ((densidade_popu + pib) > (densidade_popu2 + pib2)) ? nome_cidade : nome_cidade2);
   
      if ((densidade_popu + pib) == (densidade_popu2 + pib2))
      {
         printf("%s e %s empataram!\n", nome_cidade, nome_cidade2);
      }

         break;

      case 4:
      printf("\n### Comparação de cartas ###\n");
      printf("%s vs %s \n", nome_cidade, nome_cidade2);
      printf("Atributos escolhidos: Densidade Populacional e Pontos Turísticos\n");
      printf("%s --->\nDensidade Populacional: %.2f \nPontos Turísticos: %d\nValor combinado: %.2f\n", nome_cidade, densidade_popu, pontos_turisticos, (densidade_popu + pontos_turisticos)); // Valores do atributo da cidade 1
      printf("%s --->\nDensidade Populacional: %.2f \nPontos Turísticos: %d\nValor combinado: %.2f\n", nome_cidade2, densidade_popu2, pontos_turisticos2, (densidade_popu2 + pontos_turisticos2)); // Valores do atributo da cidade 2
         
      printf("VENCEDOR: %s\n", ((densidade_popu + pontos_turisticos) > (densidade_popu2 + pontos_turisticos2)) ? nome_cidade : nome_cidade2);
   
      if ((densidade_popu + pontos_turisticos) == (densidade_popu2 + pontos_turisticos2))
      {
         printf("%s e %s empataram!\n", nome_cidade, nome_cidade2);
      }

         break;
      default:
      printf("Valor inválido, tente novamente");
      }
      break;

   default:
      printf("Valor inválido, tente novamente");
   }





   return 0;
}