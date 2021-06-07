#include <stdio.h>
#include <stdlib.h>
void array(int [],int,int);
int main(){
 int a[]={0,1,2,3,4,5,6,7,8};
 int x, i=8;
 printf("RIZKA NURUL SEPTIANA HAKIM\n");
 printf("20051397025\n");
 printf("MI_A_2020\n");
 printf("Input x : ");scanf("%d", &x);
 array(a,x,i);
}
void array(int a[],int x,int i){
 if(i<0){
 puts("x bukan merupakan anggota array a");
 return;
 }
 if(x==a[i]){
 puts("x merupakan anggota array a");
 return;
 }
 array(a,x,i-1);
}
