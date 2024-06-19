#include <iostream>
#include <vector>
#include<algorithm>
#include<utility>
#include<map>
#include<unordered_map>
#include<cmath>
#include<climits>
#include<deque>
#include<set>
#include<queue>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define  int long long
#define  endl '\n'
vector<pair<int,pair<int,int>>>edgeList;
struct  DSU
{
	vector<int>parent,sizes;

	void init(int n )
	{
		parent.resize(n+1);
        sizes.resize(n+1);
		for (int i = 1; i <= n; i++) {
            parent[i] = i;
            sizes[i] = 1;
        }

	}
	int find_root(int u)
	{
		if (parent[u] == u)
			return u; 
		return parent [u] = find_root(parent[u]);
	}
void merge(int u, int v)
	{
		int root_u = find_root(u);
		int root_v = find_root(v);
		if (root_u != root_v) {
            if (sizes[root_u] > sizes[root_v])
                swap(root_v, root_u);
            parent[root_u] = root_v;
            sizes[root_v] += sizes[root_u];
        }

	}
};
void solve()
{

}

signed main()
{
 // kruskal algorithm 
    int n , m ;cin>>n>>m ;
    edgeList.resize(m);
    for(int i =0 ;i<m;i++)
    {
        int u ,v,c ;cin>>u>>v>>c;
        edgeList[i]= {c,{u,v}};
    }
    DSU s;
    s.init(n);
    sort(edgeList.begin(),edgeList.end());
     int cost = 0 ;
     for(int i=0;i<m;i++)
     {
         if(s.parent[edgeList[i].second.first]!=s.parent[edgeList[i].second.second])
         {
             s.merge(edgeList[i].second.first,edgeList[i].second.second);
             cost+=edgeList[i].first;

         }


     }
     cout<<cost<<endl;



   
}


