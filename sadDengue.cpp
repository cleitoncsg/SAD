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
int regiao;
int baseAno;
int inicio;

void montaEquacaoMinimosQuadrados(int regiao);
void detectaCategoria(int ano);
void exibeResultados();

int main(){

   FILE* arquivo;
   int regiao;

   arquivo = fopen("entrada.txt", "rt");

   if(arquivo == NULL){
   	 printf("Arquivo de entrada nulo\n");
   }

   fscanf(arquivo, "%d", &regiao);

   printf("Regiao %d\n", regiao);

   montaEquacaoMinimosQuadrados(regiao);

   fclose(arquivo);
   
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
