#include<bits/stdc++.h>
using namespace std;

mt19937_64 mt_rand(random_device{}());
long long rnd(long long l,long long r){
    return mt_rand()%(r-l+1)+l;
}

int subtask,test,n,m=5e4;

int main(){
    scanf("%d%d",&subtask,&test);
    if(subtask==1)n=test==1?15:test==2?16:20;
    if(subtask==2)n=test==1?5:test==2?15:50,m=10;
    if(subtask==3)n=test==1?15:test==2?19:49;
    if(subtask==4)n=test==1?30:test==2?40:50;
    printf("%d %d\n",n,m);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++)
            printf("%lld",rnd(0,1));
        printf("\n");
    }
    return 0;
}
