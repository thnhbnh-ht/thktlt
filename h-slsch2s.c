#include<stdio.h>
int ucln(int a, int b){
    if (b==0) return a;
    return ucln(b,a%b);
}
int bcnn(int a, int b){
    return (a/ucln(a,b)*b);
}
int main(){
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    printf("%d",n/a+n/b-bcnn(a,b));
    return 0;
}