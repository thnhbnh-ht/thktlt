#include<stdio.h>
int cnt(int n){
    int d=0;
    for (int i=0;i<=n*n;i++){
        if (i%2==0 || i%3==0) d++;
    }
    return d;
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d",cnt(n));
}