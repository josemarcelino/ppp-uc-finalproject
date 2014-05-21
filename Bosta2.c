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
/*typedef struct{
    int horas ;
    int min ;
}horario ;
*/
typedef struct{
    int ano ;
    int mes ;
    int dia ;
    int horas ;
    int min ;
}data ;
typedef struct{
    char nome[150] ;
    long int id ;
    data D ;
    int tipo_reserva ; // 1 para manutencao e 2 para lavagem
}cliente ;
/*typedef struct{
    data D ;
    horario H ;
}slot ;
typedef struct{
    slot S ;
    cliente C ;
}reserva ; */
typedef struct lnode *List_head;
typedef struct lnode {
cliente dados ;
List_head next;
} no_lista;

//======================Func_def=============//

//===========================================//
//==============Funcoes de Listas============//
//===========================================//
List_head cria_lista (void)
{
List_head aux;
aux = (List_head) malloc (sizeof (no_lista));
if (aux != NULL) {
aux->next = NULL;
}
return aux;
}
//==========================================//
void imprime_lista (List_head lista)
{
List_head l = lista->next; /* Salta o header */
while (l)
{
printf("Nome:  %s  \n", l->dados.nome);
printf("Mes : %d \n", l->dados.D.mes);
printf("Dia :%d \n", l->dados.D.dia);
printf("Horas: %d \n", l->dados.D.horas);
printf("Minutos: %d  \n", l->dados.D.min);
printf("//=================================//  \n ") ;
l=l->next;
}
}
//==========================================//
int procura_lista_data(List_head l,cliente chave,int *indice)  //1 se encontra e 0 se nao encontra
{
    List_head lista = l ;
    lista = lista->next ;
    while(lista) {
    if(lista->dados.D.mes == chave.D.mes)
        if(lista->dados.D.dia == chave.D.dia)
            if(lista->dados.D.horas == chave.D.horas)
               // if(lista->dados.D.min == chave.D.min)
                    return(1) ;
    lista = lista->next ;
    indice++ ;
    }
    return(0) ;
}
//=======================================//
void procura_lista (List_head lista, cliente chave, List_head *ant, List_head *actual)
{
*ant = lista; *actual = lista->next;
while ((*actual) != NULL && (*actual)->dados.D.mes < chave.D.mes)
{
*ant = *actual;
*actual = (*actual)->next;
}
while ((*actual) != NULL && (*actual)->dados.D.mes < chave.D.mes && (*actual)->dados.D.dia < chave.D.dia )
{
*ant = *actual;
*actual = (*actual)->next;
}
     if ((*actual) != NULL && (*actual)->dados.D.dia != chave.D.dia && (*actual)->dados.D.mes != chave.D.mes && (*actual)->dados.D.ano != chave.D.ano)
*actual = NULL; /* Se elemento não encontrado*/
}
//======================================//
void insere_lista (List_head lista, cliente data_1)
{
List_head no;
List_head ant, inutil;
no = (List_head) malloc (sizeof (no_lista));
if (no != NULL) {
//no->dados.D.ano = data_1.D.ano ;
no->dados.D.mes = data_1.D.mes ;
no->dados.D.dia = data_1.D.dia ;
no->dados.D.horas = data_1.D.horas ;
no->dados.D.min = data_1.D.min ;
no->dados.tipo_reserva = data_1.tipo_reserva ;
strcpy(no->dados.nome,data_1.nome) ;
procura_lista (lista, data_1, &ant, &inutil);
no->next = ant->next;
ant->next = no;
}
}
//======================================//
void elimina_lista (List_head lista, cliente dados1)
{
List_head ant1;
List_head actual1;
procura_lista (lista, dados1, &ant1, &actual1);
if (actual1 != NULL) {
ant1->next = actual1->next;
free (actual1);
}
}
//==================================================//
void copia_no(List_head lista,List_head lista_pre) {

}
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
            case 5: printf("Escolheu Listar por data \n ") ; break ;
            case 6: printf("Escolheu Listar por Cliente \n ") ; break ;
            case 7: printf("Escolheu Sair \n") ;
        }
    }while(option!=7) ;
}
//===========================================//
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
    scanf("%d", &dados_cliente.D.min) ;
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
void main() {
List_head lista_reservas ;
List_head lista_pre_reservas ;
lista_reservas = cria_lista() ;
lista_pre_reservas = cria_lista() ;
menu_main(lista_reservas, lista_pre_reservas) ;
}
