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
#define pb push_back
#define mp make_pair
#define mod 1717171769
#define  LSOne(S) (S&(-S))
#define all(a) a.begin(),a.end()
#define Prime 31
using namespace std;
int main()
{
    #ifdef shakil
    freopen("input.txt","w",stdout);
   // freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE
  int T=10;

  srand(time(0));
    cout<<T<<endl;
  while(T--)
  {
    int n=20;
    int q=1+rand()%25;

    cout<<n<<" "<<q<<endl;
    for(int i=0;i<n;i++) cout<< -100+rand()%200<<" ";
    cout<<endl;
    for(int i=0;i<q;i++)
    {
        int t=rand()%2;
        if(t==0)
        {
            int a=1+rand()%n;
            int b=1+rand()%n;
            printf("1 %d %d\n",a,b);
        }
        else{
            int a=1+rand()%n;
            int b=1+rand()%n;
            if(a>b) swap(a,b);
            ll c=-100+rand()%200;
            printf("2 %d %d %lld\n",a,b,c);
        }
    }
  }
  return 0;
}

