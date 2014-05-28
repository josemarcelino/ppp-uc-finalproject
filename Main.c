#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "Lista.c"


void Faz_Reserva(List_head lista, List_head lista_pre) {
    int option ;
    cliente dados_cliente ;
    printf("Insira o nome: \n ") ;
    fgets(dados_cliente.nome,150, stdin);
    //gets(dados_cliente.nome) ;
   // getchar() ;
    fflush(NULL) ;
    printf("Insira agora o horario pretendido: \n " ) ;
    printf("Dia: ") ;
    scanf("%d", &dados_cliente.D.dia) ;
    printf("Mes: ") ;
    scanf("%d", &dados_cliente.D.mes) ;
    printf("Hora: ") ;
    scanf("%d", &dados_cliente.D.horas) ;
    printf("Minuto (tenha em atençao ás meias horas: ") ;
    scanf("%d", &dados_cliente.D.min) ,
    do{
		printf("Deseja reservar: \n") ;
		printf("\t1-Lavagem \n") ;
		printf("\t2-Manutencao \n") ;
		printf("\t3-Sair") ;
		scanf("%d",&option) ;
        if(option==1) {
                dados_cliente.tipo_reserva = 2 ;
         //       printf(" Sera que a lista existe?  %d", procura_lista_data(lista,dados_cliente,0)) ; //teste
                if(procura_lista_data(lista, dados_cliente,0)== 0) {
                    insere_lista(lista,dados_cliente) ;
                    imprime_lista(lista) ;
                    }
                else {
                    printf("A hora escolhida nao esta disponivel. Podera fazer um pre reserva atraves do Menu se desejar.") ;
                }
                return ;
        }
        else {
            dados_cliente.tipo_reserva = 1 ;
            //elimina_lista(lista,dados_cliente);
           // printf(" Sera que a lista existe?  %d", procura_lista_data(lista,dados_cliente,0)) ; //teste
            if(procura_lista_data(lista, dados_cliente,0)== 0) {
                insere_lista(lista,dados_cliente) ;
                imprime_lista(lista) ;
                }
                else {
                    printf("A hora escolhida nao esta disponivel. Podera fazer um pre reserva atraves do Menu se desejar.") ;
                }

            return ;
            }
    }while(option != 3) ;
    return ;
}
//========================================================//
void elimina_reserva(List_head lista) {
    cliente dados_cliente ;
    int escolha ;
    printf("Insira os dados da sua reserva: \n " ) ;
    printf("Insira o nome: \n ") ;
    fgets(dados_cliente.nome,150, stdin);
    //gets(dados_cliente.nome) ;
   // getchar() ;
    fflush(NULL) ;
    printf("Dia: ") ;
    scanf("%d", &dados_cliente.D.dia) ;
    printf("Mes: ") ;
    scanf("%d", &dados_cliente.D.mes) ;
    printf("Hora: ") ;
    scanf("%d", &dados_cliente.D.horas) ;
    if( procura_lista_data(lista,dados_cliente,0)   == 1 ) {
        printf("Tem a certeza que quer cancelar a reserva? ( 1 - Sim , 0 - Nao ) \n")  ;
        scanf("%d", &escolha) ;
        if(escolha==1) {
            elimina_lista(lista,dados_cliente) ;
            printf("Reserva cancelada. \n") ;
        }
        else
            printf("A sua reserva nao foi cancelada \n") ;
    }
    else printf(" A sua reserva nao existe. \n")  ;
    return;
    }
//===========================================================//

    void menu_main(List_head lista,List_head lista_pre){
    int option ;
    do{
		printf("Deseja: \n") ;
		printf("\t1-Reservar \n") ;
		printf("\t2-Pre-Reservar \n") ;
        printf("\t3-Cancelar reserva \n") ;
        printf("\t4-Cancelar pre-reserva \n") ;
        printf("\t5-Listar por data \n") ;
        printf("\t6-Lista por Cliente \n") ;
        printf("\t7-Sair \n") ;

        scanf("%d",&option) ;
        getchar() ;
        switch(option) {
            case 1: printf("Escolheu Reservar \n " )  ; Faz_Reserva(lista,lista_pre); break ;
            case 2: printf("Escolheu Pre-reservar \n ")  ;  break ;
            case 3: printf("Escolheu Cancelar reserva \n ") ; elimina_reserva(lista) ;break ;
            case 4: printf("Escolheu Cancelar pre-reserva \n ") ; elimina_reserva(lista_pre) ; break ;
            case 5: printf("Escolheu Listar por data \n ") ; imprime_lista(lista); break ;
            case 6: printf("Escolheu Listar por Cliente \n ") ; break ;
            case 7: printf("Escolheu Sair \n") ;
        }
    }while(option!=7) ;
}


void main() {
List_head lista_reservas ;
List_head lista_pre_reservas ;
lista_reservas = cria_lista() ;
lista_pre_reservas = cria_lista() ;
menu_main(lista_reservas, lista_pre_reservas) ;
}
