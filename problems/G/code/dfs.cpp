// dfs.cpp
// s = 1e9

#include<bits/stdc++.h>
using namespace std;

int n;
long long m,a[1001],suf[1001];
vector<int> vec;

void dfs(int id,long long diff){
    if(id==n*2+1){
        if(diff==0){
            printf("%d\n",(int)vec.size());
            for(int i :vec)printf("%d ",i);
            exit(0);
        }
        return;
    }
    if(suf[id]<abs(diff))return;
    dfs(id+1,diff-a[id]);
    vec.push_back(id);
    dfs(id+1,diff+a[id]);
    vec.pop_back();
}

int main(){
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n*2;i++)
        scanf("%lld",a+i);
    for(int i=n*2;i>=1;i--)suf[i]=suf[i+1]+a[i];
    dfs(1,0);
    return 0;
}
