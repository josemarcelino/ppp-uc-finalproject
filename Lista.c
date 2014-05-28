#include "Cliente.c"

typedef struct lnode *List_head;

typedef struct lnode {
 cliente dados ;
 List_head next;
} no_lista;


List_head cria_lista (void){
 List_head aux;

 aux = (List_head) malloc (sizeof (no_lista));
 if (aux != NULL) {
  aux->next = NULL;
 }
return aux;
}
//==========================================//
void imprime_lista (List_head lista) {
 List_head l = lista->next; /* Salta o header */
 while (l) {
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
int procura_lista_data(List_head l,cliente chave,int *indice) {  //1 se encontra e 0 se nao encontra
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
void procura_lista (List_head lista, cliente chave, List_head *ant, List_head *actual) {
 *ant = lista;
 *actual = lista->next;
 while ((*actual) != NULL && (*actual)->dados.D.mes < chave.D.mes) {
  *ant = *actual;
  *actual = (*actual)->next;
 }
 while ((*actual) != NULL && (*actual)->dados.D.mes < chave.D.mes && (*actual)->dados.D.dia < chave.D.dia ) {
  *ant = *actual;
  *actual = (*actual)->next;
}
 if ((*actual) != NULL && (*actual)->dados.D.dia != chave.D.dia && (*actual)->dados.D.mes != chave.D.mes && (*actual)->dados.D.ano != chave.D.ano)
  *actual = NULL; /* Se elemento não encontrado*/
}
//======================================//
void insere_lista (List_head lista, cliente data_1) {
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
void elimina_lista (List_head lista, cliente dados1) {
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
