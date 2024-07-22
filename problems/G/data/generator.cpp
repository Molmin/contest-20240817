#include<bits/stdc++.h>
using namespace std;

mt19937_64 mt_rand(random_device{}());
long long rnd(long long l,long long r){
    return mt_rand()%(r-l+1)+l;
}

int n=50; // 你可以修改此处的值
long long s=1e12; // 你可以修改此处的值
long long a[1001];

int main(){
    int testid,subtaskid;
    scanf("%d%d",&subtaskid,&testid);
    if(subtaskid==1)n=9;
    if(subtaskid==2)n=18;
    if(subtaskid==3)n=25;
    if(subtaskid==4)n=35;
    if(subtaskid==5)s=1e6;
    if(subtaskid==6)s=1e7;
    if(subtaskid==7)s=1e8;
    if(subtaskid==8)s=1e9;
    if(subtaskid==9)s=1e10;
    if(subtaskid==10)s=1e11;
    printf("%d %lld\n",n,s);
    for(int i=1;i<=n*2;i++)
        a[i]=rnd(1,s);
    a[n]=a[n*2]=s;
    sort(a+1,a+1+n);
    sort(a+1+n,a+1+n*2);
    for(int i=n;i>=1;i--)a[i]-=a[i-1];
    for(int i=n*2;i>=n+2;i--)a[i]-=a[i-1];
    for(int i=1;i<=n*2;i++)
        swap(a[rnd(1,n*2)],a[rnd(1,n*2)]);
    for(int i=1;i<=n*2;i++)
        printf("%lld%c",a[i]," \n"[i==n*2]);
    return 0;
}
