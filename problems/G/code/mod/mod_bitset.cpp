// mod_bitset.cpp
// s = 1e12

#include<bits/stdc++.h>
using namespace std;
const int cntbase=1,base[cntbase]={10000000};

mt19937 mt_rand(random_device{}());
int rnd(int l,int r){
    return mt_rand()%(r-l+1)+l;
}

int n;
long long s,a[1001];
bitset<10000000> dp[cntbase][1001];

int main(){
    scanf("%d%lld",&n,&s),n*=2;
    for(int i=1;i<=n;i++)
        scanf("%lld",a+i);
    for(int _=0;_<cntbase;_++){
        dp[_][0][0]=true;
        for(int i=1;i<=n;i++)
            dp[_][i]=dp[_][i-1]|(dp[_][i-1]<<(a[i]%base[_]))|(dp[_][i-1]>>(base[_]-a[i]%base[_]));
    }
    while(true){
        vector<int> vec;
        int now[cntbase];
        for(int _=0;_<cntbase;_++)now[_]=s%base[_];
        long long sum=0;
        for(int i=n;i>=1;i--){
            bool flag1=true,flag2=true;
            for(int _=0;_<cntbase;_++){
                if(!dp[_][i-1][now[_]])flag1=false;
                if(!dp[_][i-1][(now[_]-a[i]%base[_]+base[_])%base[_]])flag2=false;
            }
            if(!flag2||(flag1&&rnd(0,1)))continue;
            for(int _=0;_<cntbase;_++)now[_]=(now[_]-a[i]%base[_]+base[_])%base[_];
            vec.push_back(i),sum+=a[i];
        }
        if(sum==s){
            reverse(vec.begin(),vec.end());
            printf("%d\n",(int)vec.size());
            for(int i :vec)printf("%d ",i);
            printf("\n");
            return 0;
        }
    }
    return 0;
}
