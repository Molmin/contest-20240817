#include<bits/stdc++.h>
using namespace std;

int n,a[200001],b[200001];

bool check(int v){
    if(!v)return false;
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(a[v]%a[i])cnt++;
    return cnt<=1;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i),b[i]=i;
    sort(b+1,b+1+n,[&](int x,int y){
        return a[x]<a[y];
    });
    if(b[n-1]>b[n])swap(b[n-1],b[n]);
    if(check(b[n-1]))printf("%d ",b[n-1]);
    if(check(b[n]))printf("%d ",b[n]);
    if(!check(b[n-1])&&!check(b[n]))printf("NO");
    printf("\n");
    return 0;
}
