#include<bits/stdc++.h>
using namespace std;

int main(int argc,char **argv){
    int T=argv[1][0]-'0';
    if(T==1){
        int n,m=3e4;
        char s[100]={};
        scanf("%d%s",&n,s+1);
        printf("1 %d %d\n%s\n",n,m,s+1);
        int seed=398281730;
        for(int i=1;i<=n;i++)seed^=i*s[i];
        mt19937 mt_rand(seed);
        for(int i=1;i<=m;i++){
            int x=mt_rand()%int(1e9)+1;
            printf("%d%c",x," \n"[i==m]);
        }
    }
    else{
        ifstream input("input"),output("output");
        int n,m,m2,a[100001]={};
        char s[100]={};
        input>>T>>n>>m>>s+1;
        for(int i=1;i<=m;i++)input>>a[i];
        output>>m2;
        int seed=19281723;
        for(int i=1;i<=n;i++)seed^=i*s[i];
        mt19937 mt_rand(seed);
        vector<int> vec;
        int pos=1;
        for(int i=1;i<=m2;i++){
            int x; output>>x;
            while(a[pos]!=x&&pos<m)pos++;
            if(a[pos]==x&&(mt_rand()&1))vec.push_back(x);
        }
        input.close(),output.close();
        ofstream next_input("input");
        next_input<<2<<endl<<(int)vec.size()<<endl;
        for(int i :vec)next_input<<i<<' ';
        next_input<<endl;
        next_input.close();
    }
    return 0;
}
