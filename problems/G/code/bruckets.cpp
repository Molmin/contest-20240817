// bruckets.cpp
// s = 1e9

#include<bits/stdc++.h>
using namespace std;

int n;
long long m,a[1001];

int blocklen,cntblock;
long long sum[36];
unordered_map<long long,int> mp;

int main(){
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n*2;i++)
        scanf("%lld",a+i);
    blocklen=max(n*2/36,1);
    cntblock=(n*2-1)/blocklen+1;
    for(int i=1;i<=n*2;i++)
        sum[(i-1)/blocklen]+=a[i];
    for(int i=0;i<(1<<18);i++){
        long long s=0;
        for(int j=1;j<=18;j++)
            if((i>>j-1)&1)s+=sum[j-1];
        if(!mp[s])mp[s]=i;
    }
    for(int i=0;i<(1<<18);i++){
        long long s=0;
        for(int j=1;j<=18;j++)
            if((i>>j-1)&1)s+=sum[17+j];
        if(mp[m-s]){
            vector<int> vec;
            int status=mp[m-s];
            for(int j=1;j<=n*2;j++){
                int id=(j-1)/blocklen;
                if((id<18&&((status>>id)&1))||(id>=18&&((i>>id-18)&1)))
                    vec.push_back(j);
            }
            printf("%d\n",(int)vec.size());
            for(int i :vec)printf("%d ",i);
            return 0;
        }
    }
    puts("???");
    return -1;
}
