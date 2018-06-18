#include<bits/stdc++.h>
#define ll long long int
#define LL long long int
#define ULL unsigned long long int
#define sf(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define fr first
#define sc second
#define pii pair<int,int>
#define pll pair<LL,LL>
#define vi vector<int>
#define vll vector<LL>
#define vpii  vector<pii>
#define rep1(a,b) for(int a=1;a<=b;a++)
#define rep2(a,b) for(int a=0;a<b;a++)
#define CLR(a,b) memset(a,b,sizeof(a))
#define Clear(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define  LSOne(S) (S&(-S))
#define all(a) a.begin(),a.end()
#define Prime 31
using namespace std;
#define maxn 200100
#define INF 1<<30
#define mMax 200005
#define nMax 1005
#define SZ(a) a.size()
string gen(int m,int lim=26)
{
    string ans="";
    for(int i=0;i<m;i++) ans+= (char)('a' + rand()%lim);
    return ans;
}
int main()
{
    #ifdef shakil
        freopen("input.txt","w",stdout);
    //freopen("output.txt","w",stdout);
    #endif
//    int T=1;
//    cout<<T<<endl;
//    while(T--)
//    {
//        set<string> S;
//        int n,m;
//        n=1+rand()%10;
//        m=1+rand()%10;
//        for(int i=0;i<n;i++)
//        {
//            string a=gen(m,3);
//            if(S.count(a)==0) cout<<a<<endl;
//            else i--;
//        }
//    }
    cout<<10<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<40000<<endl;
        for(int i=1;i<40000;i++)
            cout<<i<<" "<<i+1<<" "<<i<<endl;
        cout<<100000<<endl;
        for(int i=0;i<100000;i++)
            cout<<1<<" "<<40000<<endl;
    }
    return 0;
}
