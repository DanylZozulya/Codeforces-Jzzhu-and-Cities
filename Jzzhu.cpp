#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
const int M = 100001;


struct edge {
	int x;
	ll cst;
	bool f;
	edge(int a, ll b, bool c) {
		x = a;
		cst = b;
		f = c;
	}
	bool operator <(const edge &a)const {
		if (cst == a.cst)
			return f > a.f;
		return cst > a.cst;
	}
};


int n, m, x, y, z, a, b, k, ans;
vector<pair<int, int> >v[M];
bool vis[M];
ll cost[M];
priority_queue<edge>q;

void dijkstra() {
	q.push(edge(1, 0, 0));
	for (int i = 1; i <= n; i++)cost[i] = 1e18;
	cost[1] = 0;
	while (!q.empty()) {
		edge a = q.top();
		q.pop();
		if (vis[a.x]) {
			ans += a.f;
			continue;
		}
		vis[a.x] = true;
		for (int i = 0; i < v[a.x].size(); i++) {
			int newnode = v[a.x][i].first;
			int edgecost = v[a.x][i].second;
			if (edgecost + a.cst < cost[newnode]) {
				cost[newnode] = edgecost + a.cst;
				q.push(edge(newnode, cost[newnode], 0));
			}
		}
	}


}
int main() {

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		v[x].push_back(make_pair(y, z));
		swap(x, y);
		v[x].push_back(make_pair(y, z));
	}
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		q.push(edge(x, y, 1));
	}
	dijkstra();
	cout << ans;
	return 0;
}


