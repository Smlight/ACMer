#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int n;
        scanf("%d",&n);
        if (n%3==0) {
            long long x=n/3;
            printf("%lld\n",x*x*x);
        } else if (n%4==0) {
            long long x=n/4;
            printf("%lld\n",x*x*x*2);
        } else {
            puts("-1");
        }
    }
    return 0;
}
