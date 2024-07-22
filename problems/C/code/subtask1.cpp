#include<bits/stdc++.h>
using namespace std;

int n,m;
char s[52];
vector<int> vec[2];
int id[1<<20];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<(1<<n);i++){
        id[i]=vec[__builtin_popcount(i)&1].size();
        vec[__builtin_popcount(i)&1].push_back(i);
    }
    while(m--){
        scanf("%s",s+1);
        int v=0;
        for(int i=1;i<=n;i++)
            if(s[i]=='1')v|=1<<i-1;
        v=vec[(__builtin_popcount(v)&1)^1][id[v]];
        for(int i=1;i<=n;i++)
            s[i]='0'+((v>>i-1)&1);
        printf("%s\n",s+1);
    }
    return 0;
}
