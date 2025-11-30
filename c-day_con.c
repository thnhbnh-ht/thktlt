#include <stdio.h>
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    long long cnt[k + 1];
    for (int i = 0; i <= k; i++) cnt[i] = 0;
    cnt[0] = 1; 
    for (int i = 0; i < n; i++) {
        for (int t = k; t >= a[i]; t--) {
            cnt[t] += cnt[t - a[i]];
        }
    }
    printf("%lld", cnt[k]);
    return 0;
}
