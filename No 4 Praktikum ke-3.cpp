// Nama				: Rizka Nurul Septiana Hakim	//
// NIM				: 20051397025					//
// Kelas			: 2020A MI						//
// Mata Kuliah		: Praktikum III Struktur Data	//

#include <iostream>
#include <malloc.h>

using namespace std;

struct node {
	int info;
	struct node *link;
}*front = NULL, *rear = NULL;

void insert ();
int del ();
void display();

void insert (int num){
	struct node *temp;
	temp = (struct node*) malloc (sizeof(struct node));
	
	if (temp==NULL){
		cout << "Ruang antrian penuh";
		return;
	}
	
	temp -> info = num;
	temp -> link = NULL;
	
	if (front == NULL){
		front = temp;
	}else {
		rear -> link = temp;
	}
	rear = temp; 
}

int del (){
	int num;
	struct node *temp;
	
	if(front == NULL){
		cout << "Ruang antrian kosong" << endl;
		return 0;
	}
	temp = front;
	num = temp->info;
	front = front->link;
	free (temp);
	return num;
}


void display (){
	struct node *p;
	
//	if (front == NULL){
//		cout << "Ruang antrian kosong";
//		return;
//	}

	p = front;
	cout << "\nQueue Elements: ";
	while (p != NULL){
		cout << " " << p->info;
		p = p->link;
	}
}

int main (){
	int pil;
	int num;
	
	do {
	cout << endl;
		cout << "\t\t       PROGRAM PARKIR DENGAN LINKED LIST  \t" << endl;
		cout << "\t\t==============================================" << endl;
		cout << "\t\t                  PILIHAN                      \t" << endl;
		cout << "\t\t==============================================" << endl;
		cout << "\t\t1. -.Insert.- (Memasukkan nomor plat mobil)" << endl;
		cout << "\t\t2. -.Delete.- (Mengeluarkan nomor plat mobil)" << endl;
		cout << "\t\t3. Exit" << endl;
		
		cout << "\t\tMasukkan Pilihan (1/2/3) : ";
		cin >> pil;

		switch (pil){
		case 1 :
		{
			cout << "\nMasukkan Nomor Plat: ";
			cin >> num;
			insert(num);
			display();
			break;
		}
		case 2 :
		{
			cout << endl;
			del();
			display();
			break;
		}
		}
	}
	while (pil != 3);	
}
