#include<bits/stdc++.h>
using namespace std;

int n,m;
char s[52];

int main(){
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%s",s+1);
        for(int i=1;i<=n;i++)s[i]=97-s[i];
        printf("%s\n",s+1);
    }
    return 0;
}
