#include<bits/stdc++.h>
using namespace std;

int n,a[200001];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    vector<int> answer;
    for(int i=1;i<=n;i++){
        bool flag=true;
        for(int j=1;j<=n&&flag;j++)
            for(int k=j+1;k<=n&&flag;k++)
                if(a[i]%a[j]&&a[i]%a[k])
                    flag=false;
        if(flag)answer.push_back(i);
    }
    for(int i :answer)printf("%d ",i);
    if(answer.empty())printf("NO");
    printf("\n");
    return 0;
}
