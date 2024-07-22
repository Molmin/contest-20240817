#include<bits/stdc++.h>
using namespace std;

mt19937_64 mt_rand(random_device{}());
long long rnd(long long l,long long r){
    return mt_rand()%(r-l+1)+l;
}

int subtask,test;

int main(){
    scanf("%d%d",&subtask,&test);
    string input="CF";
    auto contestId=[&](int val){
        string str="";
        while(val)str+=char('0'+val%10),val/=10;
        str.reserve();
        input+=str;
    };
    if(test<=3)contestId(rnd(1,9));
    else if(test<=6)contestId(rnd(10,99));
    else if(test<=9)contestId(rnd(100,999));
    else if(test<=12)contestId(rnd(1000,9999));
    else if(test<=15)contestId(rnd(10000,99999));
    else contestId(rnd(100000,844844));
    input+=char(rnd('A','Z'));
    if(subtask==2)input+=char(rnd('0','9'));
    cout<<input<<endl;
    return 0;
}
