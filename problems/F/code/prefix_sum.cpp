#include<bits/stdc++.h>
using namespace std;

int n,x,y,a[500001];

int main(){
    scanf("%d%d%d",&n,&x,&y);
    int ans=ceil(1.0*x*y/n);
    printf("%d\n",ans);
    for(int i=1;i<=n;i++)
        printf("%d",i<=x);
    printf("\n");
    for(int i=1;i<=n;i++)
        a[i]=min(1ll*y,(1ll*ans*i)/x);
    for(int i=1;i<=n;i++)
        printf("%d",a[i]-a[i-1]);
    printf("\n");
    return 0;
}
