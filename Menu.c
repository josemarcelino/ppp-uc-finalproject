#include <stdio.h>
#include <stdlib.h>
#include<string.h>
//===========================================//
/*
data : dia, mes , ano
horario : horas , min ;
slot: data , horario
cliente nome, id ;
reserva slot, cliente ;
*/
//=====================Definiçao de variaveis======================//
typedef struct{
    int horas ;
    int min ;
}horario ;
typedef struct{
    int ano ;
    int mes ;
    int dia ;
}data ;
typedef struct{
    char nome[150] ;
    long int id ;
}cliente ;
typedef struct{
    data D ;
    horario H ;
}slot ;
typedef struct{
    slot S ;
    cliente C ;
}reserva ;
//======================Func_def=============//

//===========================================//
void menu_main(void){
    int option ;
    do{
		printf("Deseja: \n") ;
		printf("\t1-Reservar \n") ;
		printf("\t2-Pre-Reservar \n") ;
        printf("\t3-Cancelar reserva \n") ;
        printf("\t4-Cancelar pre-reserva \n") ;
        printf("\t5-Listar por data \n") ;
        printf("\t6-Lista por Cliente \n") ;
        printf("\t7-Sair") ;

        scanf("%d",&option) ;
        switch(option) {
            case 1: printf("Escolheu Reservar \n " )  ; break ;
            case 2: printf("Escolheu Pre-reservar \n ")  ; break ;
            case 3: printf("Escolheu Cancelar reserva \n ") ; break ;
            case 4: printf("Escolheu Cancelar pre-reserva \n ") ; break ;
            case 5: printf("Escolheu Listar por data \n ") ; break ;
            case 6: printf("Escolheu Listar por Cliente \n ") ; break ;
            case 7: printf("Escolheu Sair \n") ;
        }
    }while(option!=7) ;
}
//===========================================//




void main() {
menu_main() ;
}
