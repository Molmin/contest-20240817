#include<bits/stdc++.h>
using namespace std;

int n,a[200001];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    vector<int> answer;
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=n&&cnt<=1;j++)
            if(a[i]%a[j])cnt++;
        if(cnt<=1)answer.push_back(i);
    }
    for(int i :answer)printf("%d ",i);
    if(answer.empty())printf("NO");
    printf("\n");
    return 0;
}
