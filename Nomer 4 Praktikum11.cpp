/* Praktikum 11 No.04 */
/* Rizka Nurul Septiana Hakim 20051397025 MI 2020 A */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
struct pegawai{
 int nip;
 char nama[MAX];
 char alamat[MAX];
 char golongan;
}data[MAX];
int jumlah=0;
int cari(){
 int pil1, pil2, kunciNIP, ketemu;
 char kunciNAMA[MAX];
 puts("\nPilih data kunci yang dicari");
 puts("1. Berdasarkan NIP");
 puts("2. Berdasarkan Nama");
 puts("3. Berdasarkan Nama dan NIP");
 printf("Pilihan : ");
 scanf("%d", &pil1);
 if(pil1==1 || pil1==3){
 printf("Data kunci NIP\t:");
 scanf("%d", &kunciNIP);
 fflush(stdin);
 }
 if(pil1==2 || pil1==3){
 fflush(stdin);
if(pil1==2 || pil1==3){
 fflush(stdin);
 printf("Data kunci nama\t:");
 fgets(kunciNAMA, sizeof kunciNAMA, stdin);
 }
 puts("\nPilih metode pencarian data kunci");
 puts("1. Sequential Search");
 puts("2. Binary Search (Data akan diurutkan dahulu)");
 printf("Pilihan : ");
 scanf("%d", &pil2);
 if(pil2==1){
 ketemu=sequenSearch(kunciNIP, kunciNAMA, pil1);}
 else{
 fflush(stdin);
 QuickSort(0, jumlah-1, pil1);
 puts("\nDATA YANG TERURUT : ");
 tampil();
 ketemu = BinarySearch(kunciNIP, kunciNAMA, pil1);
 }
 if(ketemu>=0){
 printf("\nData ditemukan : \n");
 printf("Posisi : %d\n", ketemu);
 printf("NIP : %d\n", data[ketemu].nip);
 printf("Nama : %s", data[ketemu].nama);
 printf("Alamat : %s", data[ketemu].alamat);
 printf("Gol.Darah : %c\n\n", data[ketemu].golongan);
 }
 return ketemu;
}
void input(){
 int pil, i, ketemu;
 struct pegawai temp;
 printf("Masukkan NIP : ");
 int pil, i, ketemu;
 struct pegawai temp;
 printf("Masukkan NIP : ");
 scanf("%d", &temp.nip);
 fflush(stdin);
 printf("Masukkan Nama : ");
 fgets(temp.nama, sizeof temp.nama, stdin);
 printf("Masukkan Alamat : ");
 fgets(temp.alamat, sizeof temp.alamat, stdin);
 printf("Masukkan Gol.Darah : ");
 scanf("%c", &temp.golongan);
 if(jumlah==0){
 data[jumlah]=temp;
 jumlah++;
 }
 else{
 puts("\n1. Sisip sebelum data kunci");
 puts("2. Sisip setelah data kunci");
 printf("pilihan : ");
 scanf("%d", &pil);
 ketemu=cari();
 if(ketemu>=0){
 if(pil==1){
 for(i=jumlah;i>ketemu;i--)
 data[i]=data[i-1];
 data[ketemu]=temp;
 }
 else{
 for(i=jumlah;i>ketemu+1;i--)
 data[i]=data[i-1];
 data[ketemu+1]=temp;
 }
 data[ketemu+1]=temp;
 }
 jumlah++;
 tampil();
 }
 else{
 puts("DATA TIDAK DITEMUKAN!!!\n");
 }
 }
}
void hapus(){
 int ketemu, i;
 ketemu=cari();
 for(i=jumlah;i>=ketemu;i--)
 data[i]=data[i+1];
 jumlah--;
}
void Tukar(struct pegawai *a,struct pegawai *b)
{
struct pegawai temp;
temp = *a;
*a = *b;
*b = temp;
}
void QuickSort(int L, int R, int pil)
{
 int i, j;
 struct pegawai x;
 x = data[(L+R)/2];
 i = L;
 j = R;
 while (i <= j){
 if(pil==1 || 3){
 while(data[i].nip < x.nip)
 i++;
 while(data[j].nip > x.nip)
 j--;
 }
 if(pil==2){
 while(strcmpi(data[i].nama, x.nama)<0)
 i++;
 while(strcmpi(data[j].nama, x.nama)>0)
 j--;
 }
 if(i <= j){
 Tukar(&data[i], &data[j]);
 i++;
 j--;
 }
 }
 if(L < j)
 QuickSort(L, j, pil);
 if(i < R)
 QuickSort(i, R, pil);
}
