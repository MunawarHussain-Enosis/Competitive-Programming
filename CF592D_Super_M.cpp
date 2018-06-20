#include <bits/stdc++.h>
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
#define  LSOne(S) (S & (-S))
#define all(a) a.begin(),a.end()
#define Prime 31
using namespace std;
#define maxn 200100
#define INF 1<<29
#define inf 1ll<<62
#define mMax 20005
#define nMax 2505
#define SZ(a) a.size()
#define  Unique(A) (A.resize(distance(A.begin(),unique(all(A)))))
void printVector(vi a) {for(int ii=0;ii<SZ(a);ii++) cout<<a[ii]<<endl;}
std::vector<vi> edges;
int dp[123457];
int marked[123457];

int n,m;
struct MinPair{
	pii first,second;
	MinPair(){
		first = pii(0,INF);
		second = pii(0,INF);
	}
	void push(int dist,int ind){
		if(first.fr<dist){
			swap(first,second);
			first=pii(dist,ind);
		}
		else if(first.fr==dist){
			if(first.sc>ind){
				swap(first,second);
				first = pii(dist,ind);
			}
			else second = pii(dist,ind);
		}
		else{
			if(second.fr<dist){
				second = pii(dist,ind);
			}
			else if(second.sc==ind){
				second.sc = min(second.sc,ind);
			}
		}
	}
	pii findMax(){
		return first;
	}
	pii findMin(){
		return second;
	}
};

MinPair dpEnpoints[1][123457];

void dfs(int u,int par){
	for(auto v:edges[u]){
		if(v==par) continue;
		dfs(v,u);
		marked[u] += marked[v];
	}
	return;
}

void dfs1(int u,int par){
	dpEnpoints[0][u].push(0,u);
	for(auto v:edges[u]){
		if(v==par) continue;
		dfs1(v,u);
		if(marked[v]>0){
			dpEnpoints[0][u].push(dpEnpoints[0][v].findMax().fr+1,
									v);
		}
	}
	return;
}

void dfs2(int u,int par){
	if(u>1 && marked[u]<m){
		pii Max= dpEnpoints[0][par].findMax();
		pii Min= dpEnpoints[0][par].findMin();
		if(Max.sc!=u)
			dpEnpoints[0][u].push(Max.fr+1,par);
		else
			dpEnpoints[0][u].push(Min.fr+1,par);
	}
	for(auto v:edges[u]){
		if(v==par) continue;
		dfs2(v,u);
	}
	return;
}
int dfs3(int u,int par){
	int res= 0;
	for(auto v:edges[u]){
		if(v==par) continue;
		if(marked[v]==0) continue;
		res += dfs3(v,u) + 2;
	}
	return res;
}

vi haunted;
int main()
{
	cin>>n>>m;
	edges.assign(n+1,vi());
	int u,v;
	rep1(i,n-1){
		scanf("%d %d",&u,&v);
		edges[u].pb(v);
		edges[v].pb(u);
	}
	rep1(i,m){
		scanf("%d",&u);
		haunted.pb(u);
		marked[u] = 1;
	}
	if(m==1){
		cout<<haunted[0]<<endl;
		cout<<0<<endl;
		return 0;
	}
	dfs(1,0);
	dfs1(1,0);
	dfs2(1,0);
	Clear(marked,0);
	rep1(i,m) marked[haunted[i-1]] = 1;
	int ans=0,ind=1;
	for(int i=1;i<=n;i++){
		if(marked[i]==0) continue;
		pii Max = dpEnpoints[0][i].findMax();
		if(ans<Max.fr) ans=Max.fr,ind=i;
	}
	dfs(ind,0);
	ans= dfs3(ind,0) - ans;
	cout<<ind<<endl;
	cout<<ans<<endl;
    return 0;
}
