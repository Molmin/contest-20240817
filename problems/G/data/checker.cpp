/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-07-06
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n;
long long m,a[101];
bool vis[101];

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt(),m=inf.readLong();
    for(int i=1;i<=n*2;i++)
        a[i]=inf.readLong();
    int k=ouf.readInt(0,n*2);
    long long sum=0;
    for(int i=1;i<=k;i++){
        int x=ouf.readInt(1,n*2);
        if(vis[x])quitf(_wa,"Wrong Answer");
        sum+=a[x],vis[x]=true;
    }
    if(sum==m)quitf(_ok,"Correct");
    else quitf(_wa,"Wrong Answer");
    return 0;
}
