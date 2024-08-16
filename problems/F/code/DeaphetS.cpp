#include<bits/stdc++.h>
using namespace std;
#define N 500050
int n,x,y,a[N],b[N],s[N<<1];
int main()
{
	scanf("%d%d%d",&n,&x,&y);
	for(int i=0;i<x;i++)a[i]=1;
	for(int i=0,st=0,k=0;i<y;i++){
		if(b[k]){
			while(b[st])st++;
			k=st;
		}
		b[k]=1;
		k=(k+x)%n;
	}
	int ans=0;
	s[0]=b[0];
	for(int i=1;i<2*n;i++)s[i]=s[i-1]+b[i%n];
	for(int i=x;i<2*n;i++)ans=max(ans,s[i]-s[i-x]);
	printf("%d\n",ans);
	for(int i=0;i<n;i++)printf("%d",a[i]);printf("\n");
	for(int i=0;i<n;i++)printf("%d",b[i]);printf("\n");
}
