#include<bits/stdc++.h>
using namespace std;
#define LL long long
long long t,m,ans,cnt;
int a[55],mm,x,y,det;
vector<pair<int,int>>f;
set<pair<int,int>>s;
vector<int>out[233333];
int main()
{
	scanf("%lld%lld",&t,&m);
	ans=(m+1)*(m+2)/2;
	ans+=m*(m-1)/2;
	if(m<=5)ans+=0;
	else if(m==6)ans+=2;
	else if(m==7)ans+=5;
	else ans+=m;
	if(t==2){
		cout<<ans<<endl;
		return 0;
	}
	scanf("%d%d",&x,&y);
	int A=x-1,B=y-x-1,C=4*m+2-y;
	if(A%4!=C%4 || A%4>=2)return printf("No\n"),0;
	if(B==2){
		if(m<=5)return printf("No\n"),0;
		if(m==6 && min(A,C)<9)return printf("No\n"),0;
		if(m==7 && min(A,C)<5)return printf("No\n"),0;
	}
	if(A%4==0){
		printf("Yes\n");
		cnt=0;
		for(int i=1;i<=4*m+2;i++)if(i!=x && i!=y){
			printf("%d%c",i,cnt<3?' ':'\n');
			cnt=(cnt+1)%4;
		}
		return 0;
	}
	if(B>2){
		printf("Yes\n");
		cnt=0;
		for(int i=1;i<=x-2;i++){
			printf("%d%c",i,cnt<3?' ':'\n');
			cnt=(cnt+1)%4;
		}
		for(int i=y+2;i<=4*m+2;i++){
			printf("%d%c",i,cnt<3?' ':'\n');
			cnt=(cnt+1)%4;
		}
		int d=B/4+1;
		for(int i=1;i<=d;i++){
			int st=x+i;
			if(i==d-1)st-=d;
			for(int j=0;j<4;j++)printf("%d%c",st+j*d,j<3?' ':'\n');
		}
		return 0;
	}
	printf("Yes\n");
	if(min(A,C)>=9){
		f.push_back(make_pair(1,8));
		f.push_back(make_pair(2,2));
		f.push_back(make_pair(3,4));
		f.push_back(make_pair(5,7));
		f.push_back(make_pair(14,2));
		f.push_back(make_pair(21,1));
	}
	else if(min(A,C)>=5){
		f.push_back(make_pair(1,2));
		f.push_back(make_pair(2,6));
		f.push_back(make_pair(4,6));
		f.push_back(make_pair(11,2));
		f.push_back(make_pair(12,6));
		f.push_back(make_pair(19,2));
		f.push_back(make_pair(26,1));
	}
	else{
		f.push_back(make_pair(1,3));
		f.push_back(make_pair(3,10));
		f.push_back(make_pair(6,3));
		f.push_back(make_pair(8,3));
		f.push_back(make_pair(16,6));
		f.push_back(make_pair(18,1));
		f.push_back(make_pair(24,1));
		f.push_back(make_pair(29,1));
	}
	for(auto pi:f){cnt++;for(int i=0;i<4;i++)a[pi.first+i*pi.second]=cnt;}
	if(A>C)reverse(a+1,a+4*cnt+3);
	for(int i=1;i<=4*cnt+2;i++)if(!a[i]){det=x-i;break;}
	for(int i=1;i<=4*cnt+2;i++)if(a[i])out[a[i]].push_back(i+det);
	for(int i=1;i<=cnt;i++){
		for(auto j:out[i])printf("%d ",j);
		printf("\n");
	}
	int o=0;
	for(int i=1;i<=4*m+2;i++)if(i-det<1 || i-det>4*cnt+2){
		printf("%d%c",i,o<3?' ':'\n');
		o++,o%=4;
	}
//	cout<<cnt<<endl;
}
