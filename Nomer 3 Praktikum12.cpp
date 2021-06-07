/* Praktikum 12 No.03 */
/* Rizka Nurul Septiana Hakim 20051397025 MI 2020 A */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#define MAX 50
bool V[MAX]={false};
int E[MAX][MAX];
int N = 0;
typedef struct edge{
 int VNext;
 int Weight;
 struct edge *next;
}LinkedList;
typedef struct{
int Vertices[MAX];
LinkedList *EFront, *ERear;
}Graph;
void jalur(Graph *G, int i){
 if(V[i]){
 printf("\n%d : ", i+1);
 while(G->EFront!=NULL){
 printf("--------> %d,%d : ", G->EFront->VNext, G->EFront->Weight);
 G->EFront=G->EFront->next;
 }
 }
}
void dataGraph(Graph *G, int i){
 int j;
 LinkedList *temp;
 for(j=0;j<MAX;j++){
 if(E[i][j]>0){
 temp = (LinkedList *)malloc(sizeof(LinkedList));
 temp->VNext = j+1;
 temp->Weight = E[i][j];
 temp->next = NULL;
 if(G->EFront==NULL)
 G->EFront = G->ERear = temp;
 else{
 G->ERear->next = temp;
 G->ERear = temp;
 }
 }
 }
}
int main()
{
 int i, j, pilihan, titik, asal, tujuan, bobot, noV=0;
 bool kosong=true;
 Graph G[MAX];
 do{
 puts("MENU");
 puts("1. Masukkan titik");
 puts("2. Hubungkan titik");
 puts("3. List Adjacency");
 puts("4. Matrix Adjacency");
 puts("5. Exit");
 printf("Silahkan pilih opsi (1-5) : ");
 puts("3. List Adjacency");
 puts("4. Matrix Adjacency");
 puts("5. Exit");
 printf("Silahkan pilih opsi (1-5) : ");
 scanf("%d", &pilihan);
 printf("\n");
 if(pilihan==1){
 printf("Masukkan titik (1-50) : ");scanf("%d", &titik);
 V[titik-1]=true;
 noV++;
 printf("Daftar titik yang telah diinputkan : ");
 for(int i=0;i<MAX;i++){
 if(V[i]==true)
 printf("%d ", i+1);
 }
 }
 if(pilihan==2){
 if(noV<2){
 printf("Titik tidak bisa dihubungkan. Input dua titik dahulu\n");
 continue;
 }
 printf("Daftar titik yang telah diinputkan : ");
 for(int i=0;i<MAX;i++){
 if(V[i]==true)
 printf("%d ", i+1);
 }
 printf("\nTitik asal : ");
 scanf("%d", &asal);
 printf("Titik tujuan : ");
 scanf("%d", &tujuan);
 printf("Bobot : ");
 scanf("%d", &bobot);
 if(V[asal-1]==false)
 puts("Titik asal salah, pastikan titik sudah diinputkan");
 if(V[tujuan-1]==false)
 puts("Titik tujuan salah, pastikan titik sudah diinputkan");
 if(V[asal-1]&&V[tujuan-1]){
 E[asal-1][tujuan-1]=bobot;
 kosong=false;
 }
 }
 if(pilihan==4){
 if(kosong){
 puts("Setidaknya hubungkan titik sekali saja terlebih dahulu\n");
 continue;
 }
 for(i=0;i<MAX;i++){
 for(j=0;j<MAX;j++){
 if(E[i][j]>0)
 printf("(%d,%d)=%d\n", i+1, j+1, E[i][j]);
 }
 }
 }
 if(pilihan==3){
 if(kosong){
 puts("Setidaknya hubungkan titik sekali saja terlebih dahulu\n");
 continue;
 }
 for(i=0;i<MAX;i++){
 G[i].EFront=NULL;
 dataGraph(&G[i], i);
 jalur(&G[i], i);
 }
 dataGraph(&G[i], i);
 jalur(&G[i], i);
 }
 }
 if(pilihan==5)
 break;
 printf("\n\n");
 }while(1);
 return 0;
}
