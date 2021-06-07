/* Praktikum 11 No.01 */
/* Rizka Nurul Septiana Hakim 20051397025 MI 2020 A */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 20
int Data[MAX];
int perbandingan;
int inisialisasi(), SequentialSearch(int), BinarySearch(int);
void Tukar(int *, int *), QuickSort(int, int);
int main()
{
 int Kunci, pilihan, ketemu, pil;
 while(pil!=3){
 puts("1. Sequential Search");
 puts("2. Binary Search (Data akan diurutkan dahulu)");
 puts("3. Exit");
 printf("Pilihan : ");
 scanf("%d", &pilihan);
 inisialisasi();
 if(pilihan==1){
 printf("\nKunci : ");
 scanf("%d", &Kunci);
 ketemu = SequentialSearch(Kunci);
 }
 if(pilihan==2){
 QuickSort(0, MAX-1);
 puts("\nData yang terurut : ");
 printf("DATA : ");
 for (int i = 0; i < MAX; i++)
 printf("%d ", Data[i]);
 printf("\nKunci : ");
 scanf("%d", &Kunci);
 ketemu = BinarySearch(Kunci);
 }
