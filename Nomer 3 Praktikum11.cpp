/* Praktikum 11 No.03 */
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
void input(), hapus(), tampil();
int sequen(int, char []);
int main()
{
 int pilihan;
 while(pilihan!=4){
 puts("1. Input");
 puts("2. Hapus");
 puts("3. Tampil");
 puts("4. Keluar");
 printf("pilihan yang diinginkan : ");
 scanf("%d", &pilihan);
 printf("\n");
 switch(pilihan){
 case 1 : input();
 break;
 case 2 : hapus();
 break;
 case 3 : tampil();
 break;
 }
 printf("\n");
 }
 return 0;
}
void input(){
 int pil, nip, ketemu, i;
 char nama[MAX];
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
 printf("DATA KUNCI NIP\t: ");
 scanf("%d", &nip);
 printf("pilihan : ");
 scanf("%d", &pil);
 printf("DATA KUNCI NIP\t: ");
 scanf("%d", &nip);
 fflush(stdin);
 printf("DATA KUNCI NAMA\t: ");
 fgets(nama, sizeof nama, stdin);
 ketemu=sequen(nip, nama);
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
 jumlah++;
 }
 else{
 puts("\nDATA TIDAK DITEMUKAN!!\n");
 }
 }
 {
void input()
 int pil, nip, ketemu, i;
 char nama[MAX];
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
}
 else{
 puts("\n1. Sisip sebelum data kunci");
 puts("2. Sisip setelah data kunci");
 printf("pilihan : ");
 scanf("%d", &pil);
 printf("DATA KUNCI NIP\t: ");
 scanf("%d", &nip);
 fflush(stdin);
 printf("DATA KUNCI NAMA\t: ");
 fgets(nama, sizeof nama, stdin);
 ketemu=sequen(nip, nama);
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
 jumlah++;
 }
 else{
 puts("\nDATA TIDAK DITEMUKAN!!\n");
 }
 }
}
void hapus(){
 int nip, ketemu, i;
 char nama[MAX];
 printf("DATA KUNCI NIP\t: ");
 scanf("%d", &nip);
 fflush(stdin);
 printf("DATA KUNCI NAMA\t: ");
 fgets(nama, sizeof nama, stdin);
 ketemu=sequen(nip, nama);
 for(i=jumlah;i>=ketemu;i--)
 data[i]=data[i+1];
 jumlah--;
}
int sequen(int x, char y[]){
 int ketemu=0, i=0;
 while(!ketemu && i<jumlah){
 if(data[i].nip==x && !strcmpi(data[i].nama, y))
 ketemu=1;
 else
 i++;
 }
 if(ketemu)
 return i;
 else{
 return -1;
 }
}
void tampil(){
 for(int i=0; i<jumlah;i++){
 printf("NIP : %d\n", data[i].nip);
 printf("Nama : %s", data[i].nama);
 printf("Alamat : %s", data[i].alamat);
 printf("Gol.Darah : %c\n\n", data[i].golongan);
 }
}
