/******************************************************************************

Trabalho final - Laboratório de informática

Aluno 1: Leandro Henrique Oliveira Neves
Aluno 2: Matheus Kodi Yamamura

*******************************************************************************/
//Adição de cabeçalho
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
//Declaração de funções
void TempoCerto(float a);
void QuadroTempo(void);
void MediaTempo(void);
void MediaVolta(void);
void VoltasLideradas(void);
void Abandonaram(void);
void Grid(void);
void ClassificVolta(void);
void Scounting(void);
void Velocidade(void);
//Declaração de variáveis/Matrize(s) globais
float TempVoltas[12][8] = {{68.925, 70.874, 67.130, 67.281, 67.982, 68.295, 67.388, 68.770}, //Tempos de voltas do 1º Competidor
                           {70.341, 67.839, 70.221, 67.934, 60.697, 68.889, 69.958, 67.258}, 	
                           {69.311, 67.655, 68.724, 67.305, 70.378, 70.987, 67.665, 67.339},
                           {67.409, 67.034, 69.749, 70.456, 70.099, 69.509, 67.808, 70.602},
                           {68.026, 67.142, 67.324, 68.964, 68.711, 69.323, 70.645, 67.360},
                           {70.597, 68.220, 70.798, 67.950, 67.120, 69.417, 68.582, 68.681},
                           {67.392, 68.193, 88.349, 00.000, 00.000, 00.000, 00.000, 00.000},
                           {69.421, 70.841, 70.560, 70.639, 69.508, 68.713, 68.955, 69.986},
                           {69.520, 70.538, 67.913, 68.992, 69.605, 68.902, 67.001, 67.548},
                           {68.299, 70.251, 69.648, 68.938, 70.866, 70.069, 70.871, 69.699},
                           {70.680, 67.475, 69.113, 69.974, 68.862, 74.761, 00.000, 00.000},
                           {69.680, 70.189, 70.029, 70.536, 89.198, 69.941, 70.340, 67.211}}; //Tempos de voltas do 12º Competidor
char Pilotos[12][50]   = {{"Max Verstappen"}, {"Daniel Ricciardo"}, {"Lando Norris"}, {"Sebastian Vettel"},
                          {"Nicholas Latifi"}, {"Pierre Gasly"}, {"Sergio Perez"}, {"Fernando Alonso"},
                          {"Charles Leclerc"}, {"Lance Stroll"}, {"Kevin Magnussen"}, {"Yuki Tsunoda"}};
float MatrizMedia[12];
//Função principal (main)
int main()
{	
	//Declaração de variáveis
	int ent = 0;
	char Continuar;
    //Entrada de dados
    do{
	    printf("Bem vindo ao Gerenciador de Treino do GP FormulaX!\n");
	    printf("Essas são nossas opções de análise. Digite uma entrada válida para saber uma análise.\n");
	    printf("Qual Tempo gasto por cada piloto, para todas as voltas - [1]\n");
	    printf("Qual média de tempo de cada piloto                     - [2]\n");
	    printf("Qual média de tempo de cada volta                      - [3]\n");
	    printf("Quantas voltas cada piloto liderou                     - [4]\n");
	    printf("Quantos pilotos abandonaram o treino antes do final    - [5]\n");
	    printf("Apresentar o Grid de largada                           - [6]\n");
	    printf("Apresentar a classificação volta a volta               - [7]\n");
	    printf("Analisar o scounting de um piloto específico           - [8]\n");
	    printf("Curiosidade do Treino                                  - [9]\n");
	    scanf("%d", &ent);
	    while (!(ent > 0 && ent < 10)){
	    	printf("Digite uma opção válida entre 1 e 9\n");
	    	scanf("%d", &ent);
		}
		//Processamento e saída de dados
		switch (ent){
			case 1:
				QuadroTempo();
				break;
			case 2:
				MediaTempo();
				break;
			case 3:
				MediaVolta();
				break;
			case 4:
				VoltasLideradas();
				break;
			case 5:
				Abandonaram();
				break;
			case 6:
				Grid();
				break;
			case 7:
				ClassificVolta();
				break;
			case 8:
				Scounting();
				break;
		    case 9:
		        Velocidade();
		        break;
		}
		printf("\n");
		printf("Deseja analisar mais alguma informação? S/N\n");
		scanf(" %c", &Continuar);
		printf("\n");
		system("cls");
		while ((Continuar != 'S' && Continuar != 'N')){
			printf("Digite S para Sim ou N para Não!\n");
			scanf(" %c", &Continuar);
			system("cls");
		}
	} while (Continuar != 'N');
	return 0;
}
//Função que transforma segundos em minutos, segundo e milissegundos de forma tabelada
void TempoCerto(float a){
	float aux = 0,
          aux1 = 0,
          aux2 = 0,
          aux3 = 0;
	aux = a;
    aux1 = trunc(aux/60);
    aux2 = trunc(aux) - aux1*60; 
    aux3 = (aux - (aux1*60 + aux2)) * 1000;
    printf("%.0f:%02.0f:%03.0f ", aux1, aux2, aux3);
}
//Função letra A (Quadro de tempo)
void QuadroTempo(void){
	//Declaração de variáveis
    int i = 0,
        j = 0;
    float aux = 0,
          aux1 = 0,
          aux2 = 0,
          aux3 = 0;
    //Processamento e Saída de dados
    for (i = 0; i < 12; i++){ //Matriz que imprime o piloto e seu tempo em todas as voltas, e usa a função TempoCerto para formatar a saída
        printf("%s\n", Pilotos[i]);
        for (j = 0; j < 8; j++){
            printf("%dª Volta -> ", j+1);
            TempoCerto(TempVoltas[i][j]);
            printf("\n");
        }
        printf("\n");
    }
}
//Função Letra B (Média de tempo de cada piloto)
void MediaTempo(void){
	//Declaração de variáveis
    int i = 0,
        j = 0,
        k = 0;
    float aux = 0;
    //Processamento e Saída de dados
    for (i = 0; i < 12; i++){ //Zera todos os valores do vetor MatrizMedia, para evitar lixo
    	MatrizMedia[i] = 0;
	}
    for (i = 0; i < 12; i++){ //Matriz que imprime o nome do piloto e a seu tempo médio, formatado. Posteriormente, guarda o tempo média na MatrizMedia
        k = 0;
        for (j = 0; j < 8; j++){
            if (TempVoltas[i][j] != 0){
                aux = aux + TempVoltas[i][j];
                k++;
            }
        }
        aux = aux/k;
        printf("A média do piloto %17s foi de ", Pilotos[i]);
       	TempoCerto(aux);
        printf("\n");
        MatrizMedia[i] = aux;
	}
}
//Função Letra C ( para fazer a média de cada volta)
void MediaVolta(void) {
	//Declaração de variáveis
    int i = 0, j = 0, k = 0, volta = 1;
    float media = 0, aux = 0;
    //Processamento e Saída de dados
    for(i = 0; i < 8; i++) { //Matriz que reseta os valores toda vez que muda o "i", e imprime o tempo média de cada volta, imprimindo também qual é a volta
        media = 0, aux = 0, k = 0;
        for(j = 0; j < 12; j++) {
                if(TempVoltas[j][i] != 0) {
                    aux += TempVoltas[j][i];
                    k++;
                }    
        }
        media = aux/k;
        printf("A média da %dº volta..: %.2f\n", volta, media);
        volta += 1;
    }
}
//Função Letra D (Quantas voltas foram lideradas por cada piloto)
void VoltasLideradas (void){
	//Declaração de variáveis
	int i = 0,
		j = 0,
		k = 0,
		P[12],
		aux = 0;
	float MenorTempo = 0;
	for (i = 0; i < 12; i++){ //Laço de repetição que coloca todos os valores do vetor P para 0, evitando valores lixos.
		P[i] = 0;
	}
	for (i = 0; i < 8; i++){ //Matriz que, escolhe o "vencedor" de cada corrida baseando-se no menor tempo do mesmo.
		for (j = 0; j < 12; j++){
			if (j == 0){ //Sendo j = 0, ou seja, o primeiro tempo a ser analisado, esse é armazenado primordialmente.
				MenorTempo = TempVoltas[j][i]; 
				aux = j;
			}
			if (MenorTempo > TempVoltas[j][i] && TempVoltas[j][i] != 0){ //Caso o tempo da volta seja diferente de zero (nulo) e o tempo em si seja menor que o atual.
				MenorTempo = TempVoltas[j][i];
				aux = j; //A aux guarda a posição do j, que corresponde a qual piloto pertence o menor tempo da volta ("i") em questão.
						 //Essa aux, armazenará inteligentemente o valor "i" que corresponde o piloto na matriz Pilotos, sendo assim
						 //É mais facíl trabalhar com quantas voltas o piloto do índice "i" da matriz Pilotos ganhou, uma vez que
						 //O índice é o mesmo para a matriz P, e para a matriz Piloto.
			}
		}
		P[aux]++;		//Vetor que armazena quantas vezes um piloto terminou em primeiro.
	}
	for (i = 0; i < 12; i++){
		if (P[i] != 0){
			printf("O piloto %17s liderou - %d corridas! \n", Pilotos[i],  P[i]);
		}
		if (i == 11){
			printf("Os demais pilotos não lideraram nenhuma corrida!\n");
		}
	}
}
//Função Letra E (para ver quem abandonou o treino antes da final)
void Abandonaram(void) {
	//Declaração de variáveis
    int i = 0, j = 0, aux = 0;
    for(i = 0; i < 12; i++) { //Matriz que, sempre zera a variável aux. Caso essa aux seja maior que zero, significa que em algum momento o piloto fez um tempo nulo.
        aux = 0;
        for(j = 0; j < 8; j++) {
            if(TempVoltas[i][j] == 0) //Caso um piloto tenha feito um tempo nulo, ele abandonou o treino antes do final.
                aux++;
        }
        if(aux != 0){
            printf("Piloto %17s abandonou o treino antes do final...\n", Pilotos[i]);
        }
    }
}
//Função Letra F (Apresentar o grid de classificação)
void Grid(void) {
    //Variaveis
    int i = 0,
        j = 0;
    float gridPilotos[12], dif[12], aux = 0;
    //Um segundo matriz de pilotos para poder ser modificado sem inteferir o principal.
    char piloto[12][50]   = {{"Max Verstappen"}, {"Daniel Ricciardo"}, {"Lando Norris"}, {"Sebastian Vettel"},
                            {"Nicholas Latifi"}, {"Pierre Gasly"}, {"Sergio Perez"}, {"Fernando Alonso"},
                            {"Charles Leclerc"}, {"Lance Stroll"}, {"Kevin Magnussen"}, {"Yuki Tsunoda"}};
    char piloaux[50];
    //Estrutura de repetição para pegar os menores tempos de cada piloto
    for(i = 0; i < 12; i++) {
        aux = 0;
        for(j = 0; j < 8; j++) {
            if(TempVoltas[i][j] != 0) {
                if(j == 0){
                    aux = TempVoltas[i][j];
                    gridPilotos[i] = aux;
                }
                if(aux > TempVoltas[i][j]) {
                    aux = TempVoltas[i][j];
                    gridPilotos[i] = aux;
                }
            }
        }
    }
    aux = 0;
    //Estrutura de Repetição para ordenar de forma crescente o grid de cada piloto
    for(i = 0; i < 12; i++) {
        for(j = i + 1; j < 12; j++) {
            if(gridPilotos[i] > gridPilotos[j]) {
                strcpy(piloaux,piloto[i]);
                strcpy(piloto[i], piloto[j]);
                strcpy(piloto[j], piloaux);
                aux = gridPilotos[i];
                gridPilotos[i] = gridPilotos[j];
                gridPilotos[j] = aux;
            }
        }
    }
    //Estrutura de Repetição para fazer a diferença do 1º com os demais
    for(i = 0; i < 12; i++) {
        j = 0;
        dif[i] = gridPilotos[i] - gridPilotos[j];
    }
    //Saída de dados
    printf("                GRID DE LARGADA\n");
    printf("           PILOTO       TEMPO     GRID\n");
    for(i = 0; i < 12; i++)
        printf("%20s    %.3f   +%.3f\n", piloto[i], gridPilotos[i], dif[i]);
}
//Função Letra G (Apresentar a classificação volta a volta)
void ClassificVolta(void){
	//Declaração de variáveis
	int i = 0,
		k = 0,
		j = 0;
	float aux = 0,
		  Vet[12];
	char PilotoFuncG[12][50]   = {{"Max Verstappen"}, {"Daniel Ricciardo"}, {"Lando Norris"}, {"Sebastian Vettel"},
                                   {"Nicholas Latifi"}, {"Pierre Gasly"}, {"Sergio Perez"}, {"Fernando Alonso"},
                                   {"Charles Leclerc"}, {"Lance Stroll"}, {"Kevin Magnussen"}, {"Yuki Tsunoda"}};
    char PilotoAux[50];
    //Processamento
	for (i = 0; i < 8; i++){ //For externo, que indica a volta
		char PilotoFuncG[12][50]   = {{"Max Verstappen"}, {"Daniel Ricciardo"}, {"Lando Norris"}, {"Sebastian Vettel"},
                                      {"Nicholas Latifi"}, {"Pierre Gasly"}, {"Sergio Perez"}, {"Fernando Alonso"},
                                      {"Charles Leclerc"}, {"Lance Stroll"}, {"Kevin Magnussen"}, {"Yuki Tsunoda"}};
		for (j = 0; j < 12; j++){ //Laço responsável por jogar os valores da volta ("i"), que estão na matriz, em um vetor.
			Vet[j] = TempVoltas[j][i];
		}
		for (k = 0; k < 12; k++){ //Laço responsável por ordenar, a colocação dos pilotos e ordenar a matriz com seus nomes.
			for (j = k + 1; j < 12; j++){
				if (Vet[k] > Vet[j] && Vet[k] != 0){
					aux = Vet[k];
					Vet[k] = Vet[j];
					Vet[j] = aux;
					strcpy(PilotoAux,PilotoFuncG[k]);
                	strcpy(PilotoFuncG[k], PilotoFuncG[j]);
                	strcpy(PilotoFuncG[j], PilotoAux);
				}
			}
		}
		//Saída de dados
		printf("%d\nª Volta\n", i+1);
		for (j = 0; j < 12; j++){ //Laço responsável por printar a classificação de determinada volta ("i").
			printf("Piloto %17s - Colocação: %d\n", PilotoFuncG[j], j+1);
		}
	}	
}
//Função letra H (Apresentar scounting de determinado piloto)
void Scounting(void){
	//Declaração de variáveis
	int i = 0,
		j = 0,
		ent = 0,
		auxp = 0,
		auxm = 0;
	float melhor = 0,
		  pior = 0,
		  media = 0,
		  VetAux[8];
	char resp;
	//Processamento/Saída de dados
	do { //Continuar/Perguntar se deseja ver o scout novamente
		printf("Você está no scounting. Digite um número para mostrar o scounting do piloto desejado.\n");
		printf("Max Verstappen   - [1]\n");
		printf("Daniel Ricciardo - [2]\n");
		printf("Lando Norris     - [3]\n");
		printf("Sebastian Vettel - [4]\n");
		printf("Nicholas Latifi  - [5]\n");
		printf("Pierre Gasly     - [6]\n");
		printf("Sergio Perez     - [7]\n");
		printf("Fernando Alonso  - [8]\n");
		printf("Charles Leclerc  - [9]\n");
		printf("Lance Stroll     - [10]\n");
		printf("Kevin Magnussen  - [11]\n");
		printf("Yuki Tsunoda     - [12]\n");
		printf("Sair             - [0]\n");
		scanf("%d", &ent);
		if (ent != 0){ //Recebe os valores da matriz em um vetor, do piloto ("i") correspondente
			for (i = 0; i < 8; i++){
				VetAux[i] = TempVoltas[ent-1][i];
			}
			printf("Scounting do piloto %s\n", Pilotos[ent-1]);
			printf("TEMPO DE CADA VOLTA:\n");
			for (i = 0; i < 8; i++){ //Recebe e analise a pior e melhor volta (e as suas posições) e a média das voltas
				printf("Tempo da %dª Volta: %.3f\n", i+1, VetAux[i]);
				if (i == 0){
					pior = VetAux[i];
					melhor = VetAux[i];
				}
				if (melhor > VetAux[i] && VetAux[i] != 0){
					melhor = VetAux[i];
					auxm = i;
				}
				if (VetAux[i] > pior){
					pior = VetAux[i];
					auxp = i;
				}
			media = media + VetAux[i];
			}
			media = media/8;
			printf("Média das voltas: ");
			TempoCerto(media);
			printf("\n");
			printf("Melhor Tempo: ");
			TempoCerto(melhor);
			printf(" - Volta %d", auxm+1);
			printf("\n");
			printf("Pior Tempo: ");
			TempoCerto(pior);
			printf(" - Volta %d", auxp+1);
			printf("\n");
		}
		printf("Deseja ver o scouting de mais pilotos? S/N\n");
		scanf(" %c", &resp);
	} while (resp != 'N');
}

void Velocidade() {
	//Variaveis e Entrada dedados
    int i = 0,
    	j = 0,
    	k = 0;
    float VelocidadeMedia[12],
    	  aux = 0;
    printf("A Velocidade Media do...\n");
    //Processamento de dados
	for (i = 0; i < 12; i++){ //Zera todos os valores do vetor MatrizMedia, para evitar lixo
    	MatrizMedia[i] = 0;
	}
    for (i = 0; i < 12; i++){ //Matriz que imprime o nome do piloto e a seu tempo médio, formatado. Posteriormente, guarda o tempo média na MatrizMedia
    	k = 0;
    	aux = 0;
        for (j = 0; j < 8; j++){
            if (TempVoltas[i][j] != 0){
            	aux = aux + TempVoltas[i][j];
            	k++;
        	}
    	}
    	aux = aux/k;
    	MatrizMedia[i] = aux;
    }
    //Processamento para calcular a velocidade media de cada piloto
    for(i = 0; i < 12; i++) {
        VelocidadeMedia[i] = 4275.00/MatrizMedia[i];
        printf("Piloto %16s...: %3.2f m/s\n", Pilotos[i], VelocidadeMedia[i]);
    }
}
