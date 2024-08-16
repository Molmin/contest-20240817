#include<bits/stdc++.h>
using namespace std;

int n,s,t,n2,s2,g;
int cnt[500001];

int main(){
    scanf("%d%d%d",&n,&s,&t);
    bool flag=s<t;
    if(flag)swap(s,t);
    printf("%d\n",(int)ceil(1.0*s*t/n));
    g=__gcd(n,s),n2=n/g,s2=s/g;
    int now=1;
    for(int i=1;i<=t;i++){
        cnt[now]++,now+=s2;
        if(now>n2)now-=n2;
    }
    auto printS=[&](){
        for(int i=1;i<=n;i++)
            printf("%d",i<=s);
        printf("\n");
    };
    auto printT=[&](){
        for(int i=1;i<=n2;i++)
            for(int j=1;j<=g;j++)
                printf("%d",j<=cnt[i]);
        printf("\n");
    };
    if(flag)printT(),printS();
    else printS(),printT();
    return 0;
}
