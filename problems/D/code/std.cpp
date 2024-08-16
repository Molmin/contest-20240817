#include<bits/stdc++.h>
using namespace std;

int main(){
    int T; scanf("%d",&T);
    if(T==1){
        char s[100]={};
        int n,m,pos=1,cnt=0;
        scanf("%d%d%s",&n,&m,s+1);
        for(int i=2;i<=n;i++)
            if(s[i]==s[i-1])s[i]='z'+1;
        vector<int> vec;
        for(int i=1;i<=m;i++){
            int target=s[pos]-'a';
            int x; scanf("%d",&x);
            if(x%27!=target)continue;
            vec.push_back(x),cnt++;
            if(cnt==20)pos++,cnt=0;
            if(pos>n)break;
        }
        printf("%d\n",(int)vec.size());
        for(int i :vec)printf("%d ",i);
    }
    else{
        int m;
        vector<int> vec;
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            int x; scanf("%d",&x),x%=27;
            if(vec.empty()||vec.back()!=x)vec.push_back(x);
        }
        for(int i=1;i<vec.size();i++)
            if(vec[i]==26)vec[i]=vec[i-1];
        for(int i :vec)printf("%c",'a'+i);
        printf("\n");
    }
    return 0;
}
