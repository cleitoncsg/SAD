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

void montaEquacaoMinimosQuadrados();
void detectaCategoria(int ano);
void exibeResultados();

void menuRegioes(){
	printf("1) Regiao Norte\n");
	printf("2) Regiao Nortedeste\n");
	printf("3) Regiao Sudeste\n");
	printf("4) Regiao Sul\n");
	printf("5) Regiao Centro-oeste\n");
}

int main(){
   int ano;
   printf("Digite o ano de pesquisa\n");
   scanf("%d",&ano); 
   
   printf("Digite o numero da regiao\n");
   menuRegioes();
   scanf("%d",&regiao);
   
   montaEquacaoMinimosQuadrados();
   
   detectaCategoria(ano);
   
   system("pause");
   
   return 0;
}


void detectaCategoria(int ano){
	
	if(ano == 1998){
		baseAno = 19;
	}
	else if(ano == 1999){
		baseAno = 25;
	}
	else if(ano == 2000){
		baseAno = 31;
	}
	else if(ano == 2001){
		baseAno = 37;
	}
	else if(ano == 2002){
		baseAno = 43;
	}
	else if(ano == 2003){
		baseAno = 49;
	}
	else if(ano == 2004){
		baseAno = 55;
	}
	else if(ano == 2005){
		baseAno = 61;
	}
	else if(ano == 2006){
		baseAno = 67;
	}
	else if(ano == 2007){
		baseAno = 73;
	}
	else if(ano == 2008){
		baseAno = 79;
	}
	
	printf("Foco de dengue nessa regiao:\n");
	exibeResultados();
}

void exibeResultados(){
	if(x[baseAno+regiao] < a/2 ){
		printf("\t\tBAIXO");
	}
	else if(x[baseAno+regiao] > a && x[79+regiao] < a*2 ){
		printf("\t\tMEDIO");
	}
	else if(x[baseAno+regiao] > a*2 ){
		printf("\t\tALTO");
	}
	
}

void montaEquacaoMinimosQuadrados(){
	
	system("color F2");
    FILE *arquivo;
    double soma_x = 0, soma_y = 0;
    double numerador, denominador;
    int i;
    
    arquivo = fopen("dados.txt","rt");
    
    for(i = 1; i < LACOS; i++){
          fscanf(arquivo, "%lf",&x[i]);
          fscanf(arquivo, "%lf",&y[i]);
          
          //printf("%lf\n\n",x[i]);
    
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
