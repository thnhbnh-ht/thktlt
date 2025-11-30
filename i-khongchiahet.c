#include<stdio.h>
typedef long long ll;
ll sol(int n, int k){
    int a=k/(n-1);
    int b=k%(n-1);
    if (b==0) return a*n-1;
    else return a*n+b;
}
int main(){
    int q;
    scanf("%d", &q);
    for (int i=0;i<q;++i){
        int n,k;
        scanf("%d%d", &n, &k);
        printf ("%d\n", sol(n,k));
    }
}