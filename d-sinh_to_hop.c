#include<stdio.h>
#include<stdio.h>

int sth[17]={0};
void hv(int n, int cnt, int k, int tmp){
    if (cnt==k){
        int cp, tmp;
        for (int i=0;i<cnt;++i){
            printf("%d ", sth[i]);
        }
        printf("\n");
        return;
    }
    for (int i=tmp;i<=n;++i){
        sth[cnt]=i;
        hv(n, cnt+1, k, i+1);
    }
}
int main(){
    int n,k;
    scanf("%d%d", &n, &k);
    hv(n, 0, k, 1);
}