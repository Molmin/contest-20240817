#include<bits/stdc++.h>
using namespace std;

mt19937_64 mt_rand(random_device{}());
long long rnd(long long l,long long r){
    return mt_rand()%(r-l+1)+l;
}

int subtask,test;
int n,m;
char s[1000];

int main(){
    scanf("%d%d",&subtask,&test);
    if(subtask==1)n=4;
    else if(subtask==3)n=8;
    else if(subtask==5)n=28;
    else n=40;
    int pw,pm,py,pother;
    int type=test%8;
    if(type==0||type==1){
        int type=rnd(0,4);
        if(type==0)pw=0,pm=0,py=0,pother=100;
        if(type==1)pw=70,pm=10,py=10,pother=10;
        if(type==2)pw=10,pm=70,py=10,pother=10;
        if(type==3)pw=10,pm=10,py=70,pother=10;
        if(type==4)pw=10,pm=10,py=10,pother=70;
    }
    if(type==2||type==3)pw=25,pm=25,py=25,pother=25;
    if(type==4||type==5)pw=16,pm=17,py=17,pother=50;
    if(type>=6){
        for(int i=1;i<=n;i++){
            if(i<=n/3)s[i]='w';
            else if(i<=n/3*2)s[i]='m';
            else if(i<=n/3*3)s[i]='y';
            else s[i]=rnd('a','z');
        }
    }
    else{
        for(int i=1;i<=n;i++){
            int v=rnd(0,99);
            if(i<n/3)v=v/2;
            if(i>n-n/3)v=50+v/2;
            if(v<pw)s[i]='w';
            else if(v<pw+pm)s[i]='m';
            else if(v<pw+pm+py)s[i]='y';
            else s[i]=rnd('a','z');
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int k=j+1;k<=n;k++)
                if(s[i]=='w'&&s[j]=='m'&&s[k]=='y')m++;
    int pdel;
    type=rnd(1,5);
    if(type==1)pdel=0;
    if(type==2)pdel=10;
    if(type==3)pdel=50;
    if(type==4)pdel=90;
    if(type==5)pdel=100;
    if(subtask==2)pdel=0;
    if(subtask==6)pdel=100;
    for(int i=1;i<=n;i++)
        if(rnd(0,99)<pdel)s[i]='?';
    if(n>8&&pdel)for(int i=1;i<=3;i++)
        s[rnd(1,n)]=rnd(0,3)?rnd('a','z'):'?';
    if(n>8)m+=rnd(-3,3);
    else if(rnd(1,10)>3)m+=rnd(-1,1);
    m=min(m,subtask==4?80:3000),m=max(m,0);
    printf("%d %d\n%s\n",n,m,s+1);
    return 0;
}
