/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-06-15
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int t,m;
bool vis[400003];

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    t=inf.readInt(1,2),m=inf.readInt();
    if(t==1){
        int x=inf.readInt(1,4*m+1);
        int y=inf.readInt(x+1,4*m+2);
        string ansToken=ans.readToken();
        string userToken=ouf.readToken();
        if(userToken!="No"&&userToken!="Yes")quitf(_wa,"The first token should be \"Yes\" or \"No\".");
        if(userToken=="Yes"){
            vis[x]=vis[y]=true;
            for(int i=1;i<=m;i++){
                int a,b,c,d;
                a=ouf.readInt(1,4*m+2);
                if(vis[a])quitf(_wa,"There are duplicate numbers present (%d).",a); vis[a]=true;
                b=ouf.readInt(a+1,4*m+2);
                if(vis[b])quitf(_wa,"There are duplicate numbers present (%d).",b); vis[b]=true;
                c=ouf.readInt(b+1,4*m+2);
                if(vis[c])quitf(_wa,"There are duplicate numbers present (%d).",c); vis[c]=true;
                d=ouf.readInt(c+1,4*m+2);
                if(vis[d])quitf(_wa,"There are duplicate numbers present (%d).",d); vis[d]=true;
                if(c-b!=b-a)quitf(_wa,"The given group [%d,%d,%d,%d] is not a valid sequence.",a,b,c,d);
                if(d-c!=c-b)quitf(_wa,"The given group [%d,%d,%d,%d] is not a valid sequence.",a,b,c,d);
            }
        }
        if(ansToken=="Yes"){
            if(userToken=="Yes")quitf(_ok,"Correct (type = %d)",t);
            else quitf(_wa,"Your judgment is incorrect.");
        }
        else{
            if(userToken=="Yes")quitf(_fail,"Judgement Failed.");
            else quitf(_ok,"Correct (type = %d)",t);
        }
    }
    else{
        long long userAnswer=ouf.readLong();
        long long standardAnswer=ans.readLong();
        if(userAnswer==standardAnswer)quitf(_ok,"Correct (type = %d)",t);
        else quitf(_wa,"Wrong Answer (type = %d)",t);
    }
    return 0;
}
