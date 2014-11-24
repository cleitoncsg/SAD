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

void montaEquacaoMinimosQuadrados();
void detectaCategoria(int ano);
void detectaInicio(int ano);
void exibeResultados();

void menuRegioes(){
	printf("1) Regiao Norte\n");
	printf("2) Regiao Nortedeste\n");
	printf("3) Regiao Sudeste\n");
	printf("4) Regiao Sul\n");
	printf("5) Regiao Centro-oeste\n");
}

int main(){

   FILE* arquivo;
   int ano, regiao;

   arquivo = fopen("entrada.txt", "rt");

   if(arquivo == NULL){
   	 printf("Arquivo de entrada nulo\n");
   }
   
   fscanf(arquivo, "%d", &ano);
   fscanf(arquivo, "%d", &regiao);

   detectaInicio(ano);
   montaEquacaoMinimosQuadrados();
   
   return 0;
}


void montaEquacaoMinimosQuadrados(){
	
    FILE *arquivo;
    double soma_x = 0, soma_y = 0;
    double numerador, denominador;
    int i;
    
    arquivo = fopen("dados.txt","rt");
    
    for(i = 1; i < LACOS; i++){
          fscanf(arquivo, "%lf",&x[i]);
          fscanf(arquivo, "%lf",&y[i]);
    
           soma_x = soma_x + x[i];
           soma_y = soma_y + y[i];
          
    }
    
    for(i = 1; i < LACOS; i++){
          numerador = x[i]*(y[i] - soma_x/LACOS);
          denominador = y[i]*(x[i] - soma_y/LACOS);
          
    }
    
    b = numerador/denominador;
    a = soma_y/LACOS - (b*soma_x/LACOS);
    
    /*printf("\t\t_-___-__-__-__-__-__-__-__-__-_-__-_-__-_-__-_\n");
    printf("\t\t\tEquacao de pertinencia\n");
    printf(" \t\t\tY = %lf X + (%lf)\n", a, b);
    printf("\t\t_-___-__-__-__-__-__-__-__-__-_-__-_-__-_-__-_\n");
    */
}

void detectaInicio(int ano){
	if(ano == 2000){
		inicio = 0;
	}
	else if(ano == 2001){
		inicio = 3;
	}
	else if(ano == 2002){
		inicio = 6;
	}
	else if(ano == 2002){
		inicio = 9;
	}
	else if(ano == 2003){
		inicio = 12;
	}
	else if(ano == 2004){
		inicio = 15;
	}
	else if(ano == 2005){
		inicio = 18;
	}
	else if(ano == 2006){
		inicio = 21;
	}
	else if(ano == 2007){
		inicio = 24;
	}
	else if(ano == 2008){
		inicio = 27;
	}
	else if(ano == 2009){
		inicio = 30;
	}
	else if(ano == 2010){
		inicio = 33;
	}
	else if(ano == 2011){
		inicio = 36;
	}
	else if(ano == 2012){
		inicio = 39;
	}
	else if(ano == 2013){
		inicio = 42;
	}
	else if(ano == 2014){
		inicio = 45;
	}
	else{
		printf("Ano invalido!\n");
	}
}