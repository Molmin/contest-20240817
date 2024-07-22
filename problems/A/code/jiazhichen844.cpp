// Author: jiazhichen844

#include<bits/stdc++.h>
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	string a;
	cin>>a;
	a.erase(0,2);
	string b;
	while(!a.empty()&&a[0]>='0'&&a[0]<='9')
	{
		b+=a[0];
		a.erase(0,1);
	}
	cout<<"https://codeforces.com/contest/"<<b<<"/problem/"<<a<<endl;
}
