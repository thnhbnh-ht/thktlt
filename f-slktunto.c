#include<stdio.h>
void snt (long long n){
  long long d2=0,d3=0,d5=0,d7=0;
  while (n>0){
    long long t=n%10;
    if (t==2) d2++;
    if (t==3) d3++;
    if (t==5) d5++;
    if (t==7) d7++;
    n/=10;
  }
  printf ("%lld\n%lld\n%lld\n%lld",d2,d3,d5,d7);
}
int main(){
  long long n;
  scanf("%lld",&n);
  snt(n);
} 