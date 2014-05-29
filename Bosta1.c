void procura_lista_spot (List_head lista, cliente chave, List_head *ant, List_head *actual) {
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
 while ((*actual) != NULL && (*actual)->dados.D.mes < chave.D.mes && (*actual)->dados.D.dia < chave.D.dia && (*actual)->dados.D.horas < chave.D.horas ) {
  *ant = *actual;
  *actual = (*actual)->next;
}
while ((*actual) != NULL && (*actual)->dados.D.mes < chave.D.mes && (*actual)->dados.D.dia < chave.D.dia && (*actual)->dados.D.horas < chave.D.horas ) {
  *ant = *actual;
  *actual = (*actual)->next;
}
 if ((*actual) != NULL && (*actual)->dados.D.dia != chave.D.dia && (*actual)->dados.D.mes != chave.D.mes && (*actual)->dados.D.horas != chave.D.horas && (*actual)->dados.D.min != chave.D.min)
  *actual = NULL; /* Se elemento não encontrado*/
}
