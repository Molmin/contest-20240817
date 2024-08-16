/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-07-11
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
const int mod=998244353,modg=3;

int n,x,y;

int power(int x,int y=mod-2){
    if(y==0)return 1;
    int tmp=power(x,y>>1);
    tmp=1ll*tmp*tmp%mod;
    if(y&1)tmp=1ll*tmp*x%mod;
    return tmp;
}

inline void NTT(int *a,int len,int k=1){
    vector<int> rev;
    for(int i=0;i<len;i++)
        rev.push_back((i?rev[i>>1]:0)>>1|((i&1)?(len>>1):0));
    for(int i=0;i<len;i++)
        if(i<rev[i])swap(a[i],a[rev[i]]);
    for(int h=2;h<=len;h<<=1){
        int w=power(modg,(mod-1)/h);
        if(k==-1)w=power(w,h-1);
        for(int i=0;i<len;i+=h){
            int now=1;
            for(int j=i;j<i+(h>>1);j++,now=1ll*now*w%mod){
                int x=a[j],y=1ll*now*a[j+(h>>1)]%mod;
                a[j]=(x+y)%mod,a[j+(h>>1)]=(x-y+mod)%mod;
            }
        }
    }
    if(k==-1)for(int i=0,inv=power(len);i<len;i++)a[i]=1ll*a[i]*inv%mod;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt(1,5e5,"n");
    x=inf.readInt(0,n,"x"),y=inf.readInt(0,n,"y");
    int user=ouf.readInt(0,n);
    int answer=(int)ceil(1.0*x*y/n);
    if(user!=answer)quitf(_wa,"Wrong Answer");
    string a=ouf.readToken(),b=ouf.readToken();
    if(a.size()!=n||b.size()!=n)quitf(_wa,"PE");
    for(int i=1;i<=n;i++)
        if(a[i-1]!='0'&&a[i-1]!='1')quitf(_wa,"PE");
    for(int i=1;i<=n;i++)
        if(b[i-1]!='0'&&b[i-1]!='1')quitf(_wa,"PE");
    int k=1; while(k<=n*3)k<<=1;
    vector<int> f(k,0),g(k,0);
    for(int i=1;i<=n;i++)f[i-1]=a[n-i]-'0';
    for(int i=1;i<=n;i++)g[i-1]=g[i-1+n]=b[i-1]-'0';
    NTT(&f[0],k,1);
    NTT(&g[0],k,1);
    for(int i=0;i<k;i++)f[i]=1ll*f[i]*g[i]%mod;
    NTT(&f[0],k,-1);
    bool flag=false;
    for(int i=1;i<=n;i++)
        if(f[n-2+i]>answer)flag=true;
    for(int i=1;i<=n;i++)
        x-=a[i-1]=='1',y-=b[i-1]=='1';
    if(x!=0||y!=0)flag=true;
    if(flag)quitf(_pc(50),"Partially Correct");
    else quitf(_ok,"Correct");
    return 0;
}
