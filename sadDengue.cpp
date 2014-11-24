//+------------------------------------------------------------------+
//|                                                    Lógica Fuzzy  |
//|                   Copyright © 2014, Gomes, Cleiton da Silva el al|
//|                                   http://www.softwarecsg.com.br  |
//+------------------------------------------------------------------+

#include <stdio.h>
#include <stdlib.h>
#define LACOS 42

double a, b;
double x[LACOS], y[LACOS];

void montaEquacaoMinimosQuadrados(int regiao);
void detectaCategoria(int ano);
void exibeResultados();
float calculaQuantidadeParacetamol(int regiao);

int main(){

   FILE* arquivo, *arquivoSaida;
   int regiao;

   arquivo = fopen("entrada.txt", "rt");

   if(arquivo == NULL){
   	 printf("Arquivo de entrada nulo\n");
   }

   fscanf(arquivo, "%d", &regiao);

   printf("Regiao %d\n", regiao);

   montaEquacaoMinimosQuadrados(regiao);
   printf("Quantidade Paracetamol = %f\n",calculaQuantidadeParacetamol(regiao));

   fclose(arquivo);

   arquivoSaida = fopen("arquivoSaida.txt", "wt");

   fprintf(arquivoSaida, "%f\n",calculaQuantidadeParacetamol(regiao));

   fclose(arquivoSaida);
   
   return 0;
}


void montaEquacaoMinimosQuadrados(int regiao){
	
    FILE *arquivo;
    double soma_x = 0, soma_y = 0;
    double numerador, denominador;
    int i;
    
    arquivo = fopen("dados.txt","rt");
    
    for(i = regiao; i < 42; i = i + regiao){
    	  if(i > 42)
    	  	break;
          fscanf(arquivo, "%lf",&x[i]);
          fscanf(arquivo, "%lf",&y[i]);
    
           soma_x = soma_x + x[i];
           soma_y = soma_y + y[i];
          
    }
    
    for(i = regiao; i < 42; i = i + regiao){

    	  if(i > 42)
    	  	break;
          numerador = x[i]*(y[i] - soma_x/LACOS);
          denominador = y[i]*(x[i] - soma_y/LACOS);
          
    }
    
    b = numerador/denominador;
    a = soma_y/LACOS - (b*soma_x/LACOS);

    if(a < 0)
    	a = a*(-1);
    
    printf("\t\t_-___-__-__-__-__-__-__-__-__-_-__-_-__-_-__-_\n");
    printf("\t\t\tEquacao de pertinencia\n");
    printf(" \t\t\tY = %lf X + (%lf)\n", a, b);
    printf("\t\t_-___-__-__-__-__-__-__-__-__-_-__-_-__-_-__-_\n");
    
}


float calculaQuantidadeParacetamol(int regiao){
	float total;
	float quantidadeFoco = 500;
	float quantidadeConsumoParacetamol = 9.6;

	if(regiao == 1){
		total = (a*145*quantidadeFoco*quantidadeConsumoParacetamol)/1000 + b;
	}
	else if(regiao == 2){
		total = (a*277*quantidadeFoco*quantidadeConsumoParacetamol)/1000 + b;
	}
	else if(regiao == 3){
		total = (a*185*quantidadeFoco*quantidadeConsumoParacetamol)/1000 + b;
	}
	else if(regiao == 4){
		total = (a*87*quantidadeFoco*quantidadeConsumoParacetamol)/1000 + b;
	}
	else if(regiao == 5){
		total = (a*198*quantidadeFoco*quantidadeConsumoParacetamol)/1000 + b;
	}
	else if(regiao == 6){
		total = (a*422*quantidadeFoco*quantidadeConsumoParacetamol)/1000 + b;
	}

	return total;
}
