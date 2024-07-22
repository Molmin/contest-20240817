// two_parts_random.cpp
// s = 1e12

#include<bits/stdc++.h>
using namespace std;

mt19937_64 rnd(random_device{}());

int n;
long long m,a[1001];
unordered_map<long long,unsigned long long> mp;

pair<unsigned long long,long long> get(long long *a){
    unsigned long long s=rnd()&((1llu<<n)-1);
    long long sum=0;
    for(int i=1;i<=n;i++)
        if((s>>i-1)&1)sum+=a[i];
    return{s,sum};
}

void print(unsigned long long l,unsigned long long r){
    vector<int> vec;
    for(int i=1;i<=n;i++)
        if((l>>i-1)&1)vec.push_back(i);
    for(int i=1;i<=n;i++)
        if((r>>i-1)&1)vec.push_back(n+i);
    printf("%d\n",(int)vec.size());
    for(int i :vec)printf("%d ",i);
    exit(0);
}

int main(){
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n*2;i++)
        scanf("%lld",a+i);
    for(int i=1;i<=5e5;i++){
        pair<unsigned long long,long long> tmp=get(a);
        mp[tmp.second]=tmp.first;
    }
    while(true){
        pair<unsigned long long,long long> tmp=get(a+n);
        if(mp[m-tmp.second])print(tmp.first,mp[m-tmp.second]);
    }
    return 0;
}
