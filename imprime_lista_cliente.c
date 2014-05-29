void imprime_lista_cliente(List_head lista,List_head lista_pre) {
 List_head l = lista->next; /* Salta o header */
 List_head lp = lista_pre->next ;
 char nome_cliente[150] ;
 int cont = 0 , cont_lp = 0 ;
 printf("Insira o seu nome:  \n ");
 fgets(nome_cliente,150, stdin);
 fflush(NULL) ;
 printf("Lista de Reservas em seu nome: \n " ) ;
 //LISTA DE RESERVAS :
 while (l) {
    if (strcasecmp (nome_cliente, l->dados.nome) == 0)
    {
        // printf("Nome:  %s  \n", l->dados.nome);
        printf("Mes : %d \n", l->dados.D.mes);
        printf("Dia :%d \n", l->dados.D.dia);
        printf("Horas: %d \n", l->dados.D.horas);
        printf("Minutos: %d  \n", l->dados.D.min);
        printf("//=================================//  \n ") ;
        cont++ ;
    }
    l=l->next;
 }
 if(cont == 0 )
    printf("Nao tem reservas com este nome. \n") ;
//FIM DE LISTAGEM DE RESERVAS
//LISTAGEM DE PRE RESERVAS:
printf("Lista de pre-reservas em seu nome: \n " );
while (lp) {
    if (strcasecmp (nome_cliente, lp->dados.nome) == 0)
    {
        // printf("Nome:  %s  \n", l->dados.nome);
        printf("Mes : %d \n", lp->dados.D.mes);
        printf("Dia :%d \n", lp->dados.D.dia);
        printf("Horas: %d \n", lp->dados.D.horas);
        printf("Minutos: %d  \n", lp->dados.D.min);
        printf("//=================================//  \n ") ;
        cont_lp++ ;
    }
    lp=lp->next;
 }
 if(cont_lp == 0 )
    printf("Nao tem reservas com este nome. \n") ;
 if(cont_lp != 0 || cont != 0)
    printf("Tem um total de %d reservas e %d pre-reservas em seu nome. \n " , cont, cont_lp) ;
}
