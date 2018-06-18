#include<bits/stdc++.h>
using namespace std;

#define sl(n) scanf("%lld", &n)
#define ll long long
#define LL long long
#define fr first
#define pb push_back
#define sc second
#define vi vector<int>
#define pls pair<long long,string>
vector<ll>M, C;
int pointer;
void init()
{
    M.clear();
    C.clear();
    pointer=0;
}
//Returns true if either line l1 or
//line l3 is always better than line l2
bool bad(int l1, int l2, int l3)
{
	/*
	intersection(l1,l2) has x-coordinate (b1-b2)/(m2-m1)
	intersection(l1,l3) has x-coordinate (C1-C3)/(m3-m1)
	set the former greater than the latter, and
	cross-multiply to eliminate division
	*/
	return (1.0 * (C[l3] - C[l1]) * (M[l1] - M[l2])) <=
	       (1.0 *(C[l2] - C[l1]) * (M[l1] - M[l3]));
}
void add(long long m, long long c)
{
//First, let's add it to the end
	M.push_back(m);
	C.push_back(c);
//If the penultimate is now made irrelevant
//between the antepenultimate and the ultimate,
//remove it. Repeat as many times as necessary
	while (M.size() >= 3 &&
	        bad(M.size() - 3, M.size() - 2, M.size() - 1))
	{
		M.erase(M.end() - 2);
		C.erase(C.end() - 2);
	}
}
//Returns the minimum y-coordinate of any
//intersection between a given vertical line
//and the lower envelope
long long query(long long x)
{
//If we removed what was the best line for the
//previous query, then the newly inserted line
//is now the best for that query
	if (pointer > M.size()) pointer = M.size() - 1;
//Any better line must be to the right, since
//query values are non-decreasing
	while (pointer < M.size() - 1 && (M[pointer + 1]*x +C[pointer + 1] < M[pointer]*x + C[pointer]))
		pointer++; //MinValue Wanted...
	return M[pointer]*x + C[pointer];
}

LL w[100100];
LL cum[100100];
LL d[100100];
LL c2[100100];
LL dp[1002][1002];

int main()
{
    #ifdef shakil
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE
    int n,k;
    while(~scanf("%d %d",&n,&k))
    {
        for(int i=0;i<n;i++) scanf("%lld %lld",&d[i],&w[i]);
        c2[0]=w[0]*d[0];
        for(int i=1;i<n;i++)
            c2[i]=c2[i-1]+ w[i]*d[i];
        cum[0]=w[0];
        for(int i=1;i<n;i++) cum[i]=cum[i-1]+w[i];
        dp[0][0]=0;
        for(int i=1;i<n;i++) dp[0][i]= -c2[i-1]+cum[i-1]*d[i];
//        for(int i=0;i<n;i++)
//            cout<<dp[0][i]<<endl;
        for(int p=1;p<k;p++)
        {
            init();
           // cout<<dp[p-1][p-1]<<endl;
            add(-cum[p-1],dp[p-1][p-1]+c2[p-1]);
            for(int i=p;i<n;i++)
            {
                dp[p][i]=query(d[i]) - c2[i-1]+ cum[i-1]*d[i];
                add(-cum[i],dp[p-1][i] +c2[i] );
            }
        }
        printf("%lld\n",dp[k-1][n-1]);
    }


    return 0;
}
