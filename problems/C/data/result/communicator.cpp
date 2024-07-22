#include<bits/stdc++.h>
using namespace std;

int main(int argc,char **argv){
    int T=argv[1][0]-'0';
    if(T==1){
        int n,m;
        cin>>n>>m;
        ofstream input("input1.tmp");
        input<<n<<' '<<m<<endl;
        cout<<n<<' '<<m<<endl;
        while(m--){
            string s; cin>>s; input<<s<<endl;
        }
        input.close();
    }
    else{
        ifstream input1("input1.tmp"),output1("output1.tmp");
        ofstream input2("input2.tmp");
        int n,m;
        input1>>n>>m;
        input2<<n<<' '<<m<<endl;
        while(m--){
            string s,t;
            input1>>s,output1>>t;
            int cnts=0,cntt=0;
            assert(t.size()==n);
            for(int i=0;i<n;i++){
                assert(t[i]=='0'||t[i]=='1');
                cntt+=t[i]-'0',cnts+=s[i]-'0';
            }
            assert((cntt&1)!=(cnts&1));
            input2<<t<<endl;
        }
        input1.close(),output1.close(),input2.close();
    }
    return 0;
}
