#include<bits/stdc++.h>
using namespace std;

int n,k;
char s[42];
bitset<2501> dp[41][41][41];

void solve(int i,int cntW,int cntY,int k){
    if(i==0)return;
    auto canBe=[&](char ch){
        return s[i]=='?'||s[i]==ch;
    };
    if(s[i]!='?'){
        if(s[i]=='m')k-=cntW*cntY;
        cntW-=s[i]=='w',cntY+=s[i]=='y';
        return solve(i-1,cntW,cntY,k);
    }
    if(cntW&&dp[i-1][cntW-1][cntY][k])
        return s[i]='w',solve(i-1,cntW-1,cntY,k);
    if(dp[i-1][cntW][cntY+1][k])
        return s[i]='y',solve(i-1,cntW,cntY+1,k);
    if(k-cntW*cntY>=0&&dp[i-1][cntW][cntY][k-cntW*cntY])
        return s[i]='m',solve(i-1,cntW,cntY,k-cntW*cntY);
    s[i]='a';
    solve(i-1,cntW,cntY,k);
}

int main(){
    scanf("%d%d%s",&n,&k,s+1);
    for(int i=0;i<=n;i++)
        dp[0][0][i]=true;
    for(int i=1;i<=n;i++){
        auto canBe=[&](char ch){
            return s[i]=='?'||s[i]==ch;
        };
        for(int cntW=0;cntW<=i;cntW++)
            for(int cntY=0;cntY<=n-i;cntY++){
                if(canBe('w')&&cntW)dp[i][cntW][cntY]|=dp[i-1][cntW-1][cntY];
                if(canBe('y'))dp[i][cntW][cntY]|=dp[i-1][cntW][cntY+1];
                if(canBe('m'))dp[i][cntW][cntY]|=dp[i-1][cntW][cntY]<<(cntW*cntY);
                if(s[i]!='w'&&s[i]!='m'&&s[i]!='y')dp[i][cntW][cntY]|=dp[i-1][cntW][cntY];
            }
    }
    for(int cntW=0;cntW<=n;cntW++)
        for(int cntY=0;cntY<=n;cntY++)
            if(dp[n][cntW][cntY][k]){
                solve(n,cntW,cntY,k);
                printf("%s\n",s+1);
                return 0;
            }
    puts("-1");
    return 0;
}