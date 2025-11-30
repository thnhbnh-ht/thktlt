#include<stdio.h>
int fibo(int n, int m){
    int f1=1,f2=1,fi;
    for (int i=2;i<n;i++){
        fi=f1+f2;
        f1=f2;
        f2=fi;
    }
    return fi%m;
}
int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    if ( n==1 || n==2 ) printf("1");
    else printf("%d", fibo(n,m));
}