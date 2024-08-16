#include<bits/stdc++.h>
using namespace std;

mt19937 mt_rand(random_device{}());
inline int rnd(int l,int r){
    return mt_rand()%(r-l+1)+l;
}

int subtaskId,testId;

int main(){
    scanf("%d%d",&subtaskId,&testId);
    int n=40,p;
    if(testId==1)p=0;
    if(testId==2)p=25;
    if(testId==3)p=50;
    if(testId==4)p=75;
    if(subtaskId==1)n=1;
    if(subtaskId==2)n=5;
    if(subtaskId==3)n=15;
    if(subtaskId==4)p=0;
    printf("%d\n",n);
    char ch=rnd('a','z');
    for(int i=1;i<=n;i++){
        if(rnd(1,100)>p){
            char nxt;
            do nxt=rnd('a','z');
            while(nxt==ch);
            ch=nxt;
        }
        printf("%c",ch);
    }
    printf("\n");
    return 0;
}
