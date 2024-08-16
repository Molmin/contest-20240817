#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[30005],p[30005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	if(t==1)
	{
		cin>>n>>m;
		string b;
		cin>>b;
		for(int i=1;i<=m;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			p[i]=b[i-1]-'a';
		p[0]=-1;
		for(int i=1;i<=n;i++)
			if(p[i]==p[i-1])
				p[i]=26;
		int len=m/n;
		vector<int> v;
		for(int i=1;i<=n;i++)
			for(int j=i*len-len+1;j<=i*len;j++)
				if(a[j]%27==p[i])
					v.push_back(a[j]);
		cout<<v.size()<<"\n";
		for(int x:v)
			cout<<x<<" ";
	}
	else
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>p[i];
		for(int i=1;i<=n;i++)
			p[i]%=27;
		p[0]=-1;
		for(int i=1;i<=n;i++)
			if(p[i]!=p[i-1])
				a[++m]=p[i];
		for(int i=1;i<=m;i++)
			if(a[i]==26)
				a[i]=a[i-1];
		for(int i=1;i<=m;i++)
			cout<<char(a[i]+97);
	}
}
