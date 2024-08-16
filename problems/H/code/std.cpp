#include<bits/stdc++.h>
using namespace std;

int t,m;
bool vis[1000000];
int answer[100001][4],cnt;

bool dfs(int id){
    if(id>4*m+2)return true;
    if(vis[id])return dfs(id+1);
    cnt++;
    for(int d=1;id+d*3<=4*m+2;d++){
        if(vis[id+d]||vis[id+d*2]||vis[id+d*3])continue;
        vis[id]=vis[id+d]=vis[id+d*2]=vis[id+d*3]=true;
        for(int i=0;i<4;i++)answer[cnt][i]=id+d*i;
        if(dfs(id+1))return true;
        vis[id]=vis[id+d]=vis[id+d*2]=vis[id+d*3]=false;
    }
    cnt--;
    return false;
}

bool dfs2(int id){
    if(id>4*m+2)return true;
    if(vis[id])return dfs2(id+1);
    for(int d=1;id+d*3<=4*m+2;d++){
        if(vis[id+d]||vis[id+d*2]||vis[id+d*3])continue;
        vis[id]=vis[id+d]=vis[id+d*2]=vis[id+d*3]=true;
        if(dfs2(id+1))return true;
        vis[id]=vis[id+d]=vis[id+d*2]=vis[id+d*3]=false;
    }
    return false;
}

int main(){
    scanf("%d%d",&t,&m);
    if(t==1){
        int x,y;
        scanf("%d%d",&x,&y);
        vis[x]=vis[y]=true;
        if(!(x%4==1&&y%4==2)&&!(x%4==2&&y%4==1))return puts("No"),0;
        if(dfs(1)){
            puts("Yes");
            for(int i=1;i<=m;i++)
                printf("%d %d %d %d\n",answer[i][0],answer[i][1],answer[i][2],answer[i][3]);
        }
        else puts("No");
    }
    if(t==2){
        if(m>10)return printf("%lld\n",1ll*(m+1)*(m+1)),0;
        int answer=0;
        for(int i=1;i<=4*m+2;i++)
            for(int j=i+1;j<=4*m+2;j++){
                if(!(i%4==1&&j%4==2)&&!(i%4==2&&j%4==1))continue;
                memset(vis,false,sizeof vis);
                vis[i]=vis[j]=true;
                answer+=dfs2(1);
            }
        printf("%d\n",answer);
    }
    return 0;
}
