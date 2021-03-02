// Nama            : Rizka Nurul Septiana Hakim //
// Kelas           : 2020A MI					//
// Mata Kuliah     : Praktikum II Struktur Data	//

#include <iostream>
using namespace std;
int main(){
  char huruf[1000], hasil[1000];
  int i, jumlaharray, jumlah = 0;
  printf("Masukkan sebuah array: ");
  fgets(huruf, sizeof(huruf), stdin);
  while (huruf[jumlah] != '\0'){
    jumlah++;
  }
  jumlaharray = jumlah - 1;
  for (i = 0; i < jumlah; i++){
    hasil[i] = huruf[jumlaharray];
    jumlaharray--;
  }
  hasil[i] = '\0';
  printf("Hasil reverse array: %s \n", hasil);
  return 0;
}

