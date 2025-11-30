// #include<stdio.h>
// long long tbinh(long long n,long long m){
//     long long f1=1,f2=1,fi=0,res;
//     if (n==1 || n==2){
//         return f1%m;
//     }
//     for (int i=3;i<=n;i++){
//         fi=(f1+f2)%m;
//         f1=f2;
//         f2=fi; 
//     }
//     return fi%m;
// }
// int main(){
//     long long n,m;
//     scanf("%lld %lld", &n,&m);
//     long long res=tbinh(n,m);
//     printf("%lld ",res);
//     return 0;
// }

#include<stdio.h>
typedef long long ll;

int m;
ll c[2][2];

void nhan(ll a[][2], ll b[][2]){
    ll c[2][2];
    for (int i=0;i<2;i++){ //m
        for (int j=0;j<2;j++){ //p
            c[i][j]=0;
            for (int k=0;k<2;k++){ //n
                c[i][j]+=(a[i][k] * b[k][j])%m;
            }
        }
    }
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            a[i][j]=c[i][j]%m;
        }
    }
}

void mu(ll a[][2], int n, ll res[][2]){
    res[0][0]=res[1][1]=1;
    while (n){
        if (n&1){
            nhan(res, a);
        }
        nhan(a,a);
        n>>=1;
    }
}

int main(){
    int n;
    scanf("%d %d", &n, &m);
    c[0][0]=c[0][1]=c[1][0]=1;
    c[1][1]=0;
    ll kq[2][2]={0};
    mu(c,n-1,kq);
    printf("%lld",kq[0][0]);
    return 0;
}