/* Praktikum 12 No.01 */
/* Rizka Nurul Septiana Hakim 20051397025 MI 2020 A */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define N 5
int V[N]={1,2,3,4,5};
int E[N][N]={
 {0,10,0,5,0},
 {0,0,1,2,0},
 {0,0,0,0,4},
 {0,3,9,0,2},
 {7,0,6,0,0}
};
typedef struct edge{
 int VNext;
 int Weight;
 struct edge *next;
}LinkedList;
typedef struct{
int Vertices[N];
int Edges[N];
LinkedList *EFront, *ERear;
}Graph;
void jalur(Graph *G, int i){
 printf("\n%d : ", V[i]);
 while(G->EFront!=NULL){
 printf("--------> %d,%d : ", G->EFront->VNext, G->EFront->Weight);
 G->EFront=G->EFront->next;
 }
}
void dataGraph(Graph *G, int i){
 int j;
 LinkedList *ptr;
 for(j=0;j<N;j++){
 if(E[i][j]>0){
 ptr = (LinkedList *)malloc(sizeof(LinkedList));
 ptr->VNext = V[j];
 ptr->Weight = E[i][j];
 ptr->next = NULL;
 if(G->EFront==NULL)
 G->EFront = G->ERear = ptr;
 else{
 G->ERear->next = ptr;
 G->ERear = ptr;
 }
 }
 }
}
int main()
{
 int i, j;
 Graph G[N];
 for(i=0;i<N;i++){
 for(j=0;j<N;j++){
 if(E[i][j]>0)
 printf("(%d,%d)=%d\n", V[i], V[j], E[i][j]);
 }
 }
 }
 for(i=0;i<N;i++){
 G[i].EFront=NULL;
 dataGraph(&G[i], i);
 jalur(&G[i], i);
 }
 return 0;
}
