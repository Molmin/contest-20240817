// bf.cpp
// s = 1e6

#include<bits/stdc++.h>
using namespace std;

int n;
long long m,a[1001];
bool f[101][1000001];

int main(){
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n*2;i++)
        scanf("%lld",a+i);
    f[0][0]=true;
    for(int i=1;i<=n*2;i++)
        for(int j=0;j<=1e6;j++)
            f[i][j]=f[i-1][j]||(j>=a[i]&&f[i-1][j-a[i]]);
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
