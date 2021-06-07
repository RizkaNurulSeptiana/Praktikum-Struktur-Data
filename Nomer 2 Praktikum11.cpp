/* Praktikum 11 No.02 */
/* Rizka Nurul Septiana Hakim 20051397025 MI 2020 A */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10
int Data[MAX];
int inisialisasi(), SequentialSearch(int), BinarySearch(int);
void Tukar(int *, int *), QuickSort(int, int);
int main()
{
 int Kunci, pil, ketemu;
 while(pil!=3){
 puts("1. Sequential Search");
 puts("2. Binary Search (Data akan diurutkan dahulu)");
 puts("3. Exit");
 printf("Pilihan : ");
 scanf("%d", &pil);
 inisialisasi();
 if(pil==1){
 printf("\nKunci : ");
 scanf("%d", &Kunci);
 ketemu = SequentialSearch(Kunci);
 }
 if(pil==2){
 QuickSort(0, MAX-1);
 printf("\nDATA YANG TERURUT : ");
 for (int i = 0; i < MAX; i++)
/*Bandingkan kinerja pencarian dengan sequential search dan binary search berdasarkan*/
 printf("%d ", Data[i]);
 printf("\nKunci : ");
 scanf("%d", &Kunci);
 ketemu = BinarySearch(Kunci);
 }
 if(ketemu>=0)
 printf("\nData ditemukan pada posisi %d", ketemu);
 else
 printf("Data tidak ditemukan");
 printf("\n");
 };
}
int inisialisasi(){
 int i;
 srand(0);
 printf("\nDATA : ");
 for (i = 0; i < MAX; i++)
 {
 Data[i] = rand()/1000+1;
 printf("%d ", Data[i]);
 }
}
void Tukar (int *a, int *b)
{
int temp;
temp = *a;
*a = *b;
*b = temp;
}
void QuickSort(int L, int R)
{
 int i, j, x;
 x = Data[(L+R)/2];
 i = L;
 j = R;
 while (i <= j){
 while(Data[i] < x)
 i++;
 while(Data[j] > x)
 j--;
 if(i <= j){
 Tukar(&Data[i], &Data[j]);
 i++;
 j--;
 }
 }
 if(L < j)
 QuickSort(L, j);
 if(i < R)
 QuickSort(i, R);
}
int BinarySearch(int x)
{
 int i, L = 0, R = MAX-1, m;
 bool ketemu = false;
 while((L <= R) && (!ketemu))
 printf("\nDATA YANG DICEK : ");
 for(i=L;i<=R;i++)
 printf("%d ", Data[i]);
 m = (L + R) / 2;
 printf("\nDATA TENGAH : %d\n", Data[m]);
 puts("Apakah data kunci sesuai dengan data tengah ? ");
 if(Data[m] == x){
 puts("Benar");
 ketemu = true;
 }
 else if (x < Data[m]){
 R = m - 1;
 printf("Salah, Array data yang dicek menjadi index %d sampai %d\n", L, R);
 }
 else{
 L = m + 1;
 printf("Salah, Array data yang dicek menjadi index %d sampai %d\n", L, R);
 }
 }
 { 
 if(ketemu)
 return m;
 else
 return -1;
 }
int SequentialSearch(int x)
{
 int i = 0;
 bool ketemu = false;
 while ((!ketemu) && (i < MAX)){
 printf("Pengecekan data pada array posisi %d...\n", i);
 if(Data[i] == x)
 ketemu = true;
 else{
 i++;
 puts("\nData tidak sesuai\n");
 }
 }
 if(ketemu)
 return i;
 else
 return -1;
}
