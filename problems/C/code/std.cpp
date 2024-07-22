#include<bits/stdc++.h>
using namespace std;

int n,m;
char s[52];

int main(){
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%s",s+1);
        s[1]='0'+'1'-s[1];
        printf("%s\n",s+1);
    }
    return 0;
}
