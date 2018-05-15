#include <bits/stdc++.h>
using namespace std;
#define LL long long
const LL MXN = 70;
ll b[MXN], n, ans;
int main(){
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++){
        ll u; scanf("%lld", &u);
        for (int j = 60; ~j; j--)
            if (u & (1LL << j)){
                if (!b[j]) {b[j] = u; break;}
                else u ^= b[j];
            }
    }
    for (int j = 60; ~j; j--)
        if ((ans ^ b[j]) > ans) ans ^= b[j];
    printf("%lld", ans);
    return 0;
}
