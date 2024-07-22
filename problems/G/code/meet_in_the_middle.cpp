// meet_in_the_middle.cpp
// s = 1e11

#include<bits/stdc++.h>
using namespace std;

mt19937_64 rnd(random_device{}());

int n;
long long m,a[1001];
unordered_map<long long,unsigned long long> mp1,mp2;

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
    while(true){
        pair<unsigned long long,long long> tmp;
        tmp=get(a);
        if(tmp.second<m){
            if(mp2[m-tmp.second])print(tmp.first,mp2[m-tmp.second]);
            else mp1[tmp.second]=tmp.first;
        }
        tmp=get(a+n);
        if(tmp.second<m){
            if(mp1[m-tmp.second])print(tmp.first,mp1[m-tmp.second]);
            else mp2[tmp.second]=tmp.first;
        }
    }
    return 0;
}
