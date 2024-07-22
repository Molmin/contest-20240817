#include<bits/stdc++.h>
using namespace std;

int n,a[200001],b[200001];
set<int> answer;

void check(int v){
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(v%b[i])cnt++;
    if(cnt<=1)answer.insert(v);
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i),b[i]=a[i];
    sort(b+1,b+1+n);
    check(b[n]);
    if(n>1)check(b[n-1]);
    for(int i=1;i<=n;i++)
        if(answer.find(a[i])!=answer.end())
            printf("%d ",i);
    if(answer.empty())printf("NO");
    printf("\n");
    return 0;
}
