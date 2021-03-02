// Nama            : Rizka Nurul Septiana Hakim //
// Kelas           : 2020A MI					//
// Mata Kuliah     : Praktikum II Struktur Data	//

#include <iostream>
#include <conio.h>
using namespace std;

int main()

{

struct{

int real;

int imajiner;

}bil1;

struct{

int real;

int imajiner;

}bil2;

struct{

int real;

int imajiner;

}hasil;

awal:

char pilihan;

cout<<"\t\t+———————————+\n";

cout<<"\t\t|     PROGRAM BILANGAN KOMPLEK    |\n";

cout<<"\t\t+———————————+\n";

cout<<"\t\t1.masukan bilangan pertama\n";

cout<<"\t\t  real     = ";

cin>>bil1.real;

cout<<"\t\t  imajiner = ";

cin>>bil1.imajiner;

cout<<"\t\t2.masukan bilangan kedua\n";

cout<<"\t\t  real     = ";

cin>>bil2.real;

cout<<"\t\t  imajiner = ";

cin>>bil2.imajiner;

cout<<"\n\t\tpilih operasi\n";

cout<<"\t\t1.penjumlahan\n";

cout<<"\t\t2.pengurangan\n";

cout<<"\t\t3.perkalian";

isi:

pilihan=getch();

if(pilihan=='1')

{

hasil.real=bil1.real+bil2.real;

hasil.imajiner=bil1.imajiner+bil2.imajiner;

}

else if(pilihan=='2')

{

hasil.real=bil1.real-bil2.real;

hasil.imajiner=bil1.imajiner-bil2.imajiner;

}

else if(pilihan=='3')

{

hasil.real=(bil1.real*bil2.real)+(-(bil1.imajiner*bil2.imajiner));

hasil.imajiner=(bil1.real*bil2.imajiner)+(bil1.imajiner*bil2.real);

}

else

{

cout<<"\n\t\tmasukan salah";

goto isi;

}

cout<<"\n\t\thasil perhitungan\n\n";

cout<<"\t\t("<<bil1.real;

if(bil1.imajiner>=0)

cout<<"+";

cout<<bil1.imajiner<<"i)";

if(pilihan=='1')

cout<<" + ";

else if(pilihan=='2')

cout<<" – ";

else

cout<<" * ";

cout<<"("<<bil2.real;

if(bil2.imajiner>=0)

cout<<"+";

cout<<bil2.imajiner<<"i) = ";

cout<<"("<<hasil.real;

if(hasil.imajiner>=0)

cout<<"+";

cout<<hasil.imajiner<<"i) "<<endl<<endl;

cout<<"\t\tulang program y/t :";

end:

pilihan=getch();

if(pilihan=='y')

{

system("cls");

goto awal;

}

else if(pilihan=='t')

return 0;

else

{

cout<<"\n\t\tmasukan salah";

goto end;

}

}

