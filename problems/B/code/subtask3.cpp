#include<bits/stdc++.h>
using namespace std;

int n,cnt[10000001];
vector<int> ids[1000001];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x; scanf("%d",&x);
        ids[x].push_back(i);
    }
    for(int i=1;i<=1e6;i++){
        for(int j=i;j<=1e6;j+=i)
            cnt[j]+=(int)ids[i].size();
    }
    vector<int> answer;
    for(int i=1;i<=1e6;i++)
        if(cnt[i]>=n-1)for(int j :ids[i])answer.push_back(j);
    sort(answer.begin(),answer.end());
    for(int i :answer)printf("%d ",i);
    if(answer.empty())printf("NO\n");
    return 0;
}
