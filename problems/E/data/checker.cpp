/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-08-08
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,m;
string s,t,tans;

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt(),m=inf.readInt();
    s=inf.readToken(),t=ouf.readToken(),tans=ans.readToken();
    if(t=="-1"){
        if(tans=="-1")quitf(_ok,"Correct");
        else quitf(_wa,"Wrong Answer");
    }
    if(tans=="-1")quitf(_wa,"Wrong Answer");
    if(t.size()!=s.size())quitf(_wa,"Wrong Answer");
    for(int i=0;i<n;i++){
        if(t[i]<'a'||t[i]>'z')quitf(_wa,"Wrong Answer");
        if(s[i]!='?'&&s[i]!=t[i])quitf(_wa,"Wrong Answer");
    }
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            for(int k=j+1;k<n;k++)
                if(t[i]=='w'&&t[j]=='m'&&t[k]=='y')cnt++;
    if(cnt==m)quitf(_ok,"Correct");
    else quitf(_wa,"Wrong Answer");
    return 0;
}
