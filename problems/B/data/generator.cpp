#include<bits/stdc++.h>
using namespace std;

mt19937_64 mt_rand(random_device{}());
long long rnd(long long l,long long r){
    return mt_rand()%(r-l+1)+l;
}

const int prime[9]={2,3,5,7,11,13,17,19,23};
int cnt[9],now=1,cntd=1;
vector<pair<int,int>> best;
void dfs(int pos){
    if(pos==9){
        if(cntd>=1000)best.emplace_back(cntd,now);
        return;
    }
    for(int i=0;i<=(pos?cnt[pos-1]:100);i++){
        cnt[pos]=i,cntd*=i+1;
        dfs(pos+1);
        cntd/=i+1;
        if(1ll*now*prime[pos]>1e9)break;
        now*=prime[pos];
    }
    while(now%prime[pos]==0)now/=prime[pos];
}

int subtask,test;
int n,a[200001];
bool flag=true;

int main(){
    dfs(0),sort(best.begin(),best.end());
    scanf("%d%d",&subtask,&test);
    int var1=114514,var2=1919810,var3=1377,var4=9822;
    if(subtask==3&&test<=8){
        subtask=1;
        var1=47216,var2=43827,var3=281,var4=163;
    }
    if(subtask==4){
        subtask=1;
        if(test==1)test=1;
        else if(test==2)test=3;
        else if(test==3)test=4;
        else if(test==4)test=8;
        else subtask=4;
    }
    if(subtask==1){
        if(test==1)n=1,a[1]=var1;
        if(test==2)n=2,a[1]=a[2]=var2;
        if(test==3)n=2,a[1]=var1,a[2]=var2;
        if(test==4)n=2,a[1]=var1,a[2]=var1*11;
        if(test==5)n=3,a[1]=a[2]=a[3]=var2;
        if(test==6)n=3,a[1]=a[2]=var2,a[3]=var2*9;
        if(test==7)n=3,a[1]=a[2]=var2*7,a[3]=var2;
        if(test==8)n=3,a[1]=var3,a[2]=var4,a[3]=var3*var4;
        if(test>=9)n=test<=14?4:300;
        else flag=false;
    }
    if(subtask==2)n=2000;
    if(subtask>=3)n=200000;
    if(flag&&subtask==4){
        int cntmax=rnd(1,10)>1;
        int cnterror=rnd(1,5)==1?2:rnd(0,1);
        pair<int,int> tmp=best[rnd(0,best.size()-1)];
        int maxn=tmp.second;
        vector<pair<int,int>> prime;
        for(int i=2,x=maxn;i*i<=x;i++){
            if(x%i)continue;
            int cnt=0;
            while(x%i==0)x/=i,cnt++;
            prime.emplace_back(i,cnt);
        }
        n=0;
        set<int> S;
        if(cntmax)a[++n]=maxn,S.insert(maxn);
        for(int i=1;i<=cnterror;i++){
            ++n;
            do a[n]=rnd(1,1e9);
            while(S.find(a[n])!=S.end());
            S.insert(a[n]);
        }
        for(int i=1;i<=2e5;i++){
            ++n;
            int cnt=0;
            do{
                a[n]=1,cnt++;
                for(pair<int,int> j :prime){
                    int x=rnd(0,j.second);
                    while(x--)a[n]*=j.first;
                }
            }
            while(S.find(a[n])!=S.end()&&cnt<10);
            if(cnt==10){
                n--;
                break;
            }
            S.insert(a[n]);
        }
        if(test>=19){
            n=2e5;
            set<int> S;
            for(int i=1;i<=n;i++){
                do a[i]=rnd(1,1e9);
                while(S.find(a[i])!=S.end());
                S.insert(a[i]);
            }
        }
    }
    else if(flag){
        int cntmax=rnd(1,2)?1:rnd(2,10);
        int cnterror=rnd(1,5)==1?2:rnd(0,1);
        if(n==4&&cntmax!=1)cntmax=2;
        if(rnd(1,subtask==1?5:10)==1)cntmax=0;
        int maxn=rnd(1,subtask==3?1e6:1e9);
        vector<pair<int,int>> prime;
        for(int i=2,x=maxn;i*i<=x;i++){
            if(x%i)continue;
            int cnt=0;
            while(x%i==0)x/=i,cnt++;
            prime.emplace_back(i,cnt);
        }
        for(int i=1;i<=cntmax;i++)a[i]=maxn;
        for(int i=cntmax+1;i<=cntmax+cnterror;i++)a[i]=rnd(1,subtask==3?1e6:1e9);
        for(int i=cntmax+cnterror+1;i<=n;i++){
            a[i]=1;
            for(pair<int,int> j :prime){
                int x=rnd(0,j.second);
                while(x--)a[i]*=j.first;
            }
        }
    }
    if(subtask!=4||test<=17){
        if(rnd(1,5)<=3){
            for(int i=1;i<=5;i++)
                swap(a[rnd(1,n)],a[rnd(1,n)]);
        }
        if(rnd(1,4)==1){
            for(int i=1;i<=n;i++)
                swap(a[i],a[rnd(1,n)]);
        }
        else if(rnd(1,2)==1)reverse(a+1,a+1+n);
    }
    printf("%d\n",n);
    for(int i=1;i<=n;i++)
        printf("%d%c",a[i]," \n"[i==n]);
    return 0;
}
