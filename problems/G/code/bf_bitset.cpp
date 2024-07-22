// bf_bitset.cpp
// s = 1e7

#include<bits/stdc++.h>
using namespace std;

int n;
long long m,a[1001];
bitset<10000001> f[1001];

int main(){
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n*2;i++)
        scanf("%lld",a+i);
    f[0][0]=true;
    for(int i=1;i<=n*2;i++)
        f[i]=f[i-1]|(f[i-1]<<a[i]);
    vector<int> vec;
    int now=m;
    for(int i=n*2;i>=1;i--){
        if(f[i-1][now])continue;
        now-=a[i],vec.push_back(i);
    }
    reverse(vec.begin(),vec.end());
    printf("%d\n",(int)vec.size());
    for(int i :vec)printf("%d ",i);
    return 0;
}
