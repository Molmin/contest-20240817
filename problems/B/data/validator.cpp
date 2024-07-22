#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int getSubtaskId(){
    ifstream in("id.tmp");
    int x; in>>x;
    return x;
}

int main(int argc,char* argv[]){
    registerValidation(argc, argv);
    int subtask=getSubtaskId();
    int n=inf.readInt(1,subtask==1?300:subtask==2?2e3:2e5,"n");
    inf.readEoln();
    set<int> S;
    for(int i=1;i<=n;i++){
        int x=inf.readInt(1,subtask==3?1e6:1e9,"a_i");
        if(i==n)inf.readEoln();
        else inf.readSpace();
        if(subtask==4){
            ensuref(S.find(x)==S.end(),"duplicate numbers");
            S.insert(x);
        }
    }
    inf.readEof();
    return 0;
}
