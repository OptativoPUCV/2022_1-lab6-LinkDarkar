#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n)
{
  //int *fila = (int *) calloc (10 , sizeof(int));
  //int *col = (int *) calloc (10 , sizeof(int));
  //int *subm = (int *) calloc (10 , sizeof(int));
  int nro = 0;
  for (int f = 0 ; f <= 8 ; f++)
  {
    int *fila = (int *) calloc (10 , sizeof(int));
    for (int k = 0 ; k <= 8 ; k++)
    {
      nro = n->sudo[f][k];
      if (fila[nro] == 0 && nro != 0)
      {
        fila[nro] = 1;
      }

      if (fila[nro] == 1)
      {
        printf("el numero que se repite es %i en la fila %i %i", nro , f , k);
        return 0;
      }
    }
  }

  for (int k = 0 ; k <= 8 ; k++)
  {
    int *col = (int *) calloc (10 , sizeof(int));
    for (int f = 0 ; f <= 8 ; f++)
    {
      nro = n->sudo[f][k];
      if (col[nro] == 0 && nro != 0)
      {
        col[nro] = 1;
      }

      if (col[nro] == 1)
      {
        return 0;
      }
    }
  }

  return 1;
}


List* get_adj_nodes(Node* n)
{
  List* list=createList();
  for (int f = 0 ; f <= 8 ; f++)
  {
    for (int k = 0 ; k <= 8 ; k++)
    {
      if (n->sudo[f][k] == 0)
      {
        for (int cont = 1 ; cont <= 9 ; cont++)
        {
          Node *adj_n = (Node *) malloc(sizeof(Node));
          adj_n = copy(n);
          adj_n->sudo[f][k] = cont;
          printf("el adj_n en la pos %i %i es = a %i\n", f , k , cont);
          pushBack(list , adj_n);
        }
        return list;  //si solo se pide el primer nodo vacio hay que dejar esto
                      //pero si pide todos los nodos vacios hay que quitarlo y ya esta
      }
    }
  }

  return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/