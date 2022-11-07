vector<int> dist(n);
vector<bool> vis(n);
priority_queue<pair<ll, ll>> q;
for (int i = 0; i < n; i++) dist[i] = 1e9;
dist[h] = 0;
q.push(make_pair(0, h));
while (!q.empty()) {
	long long node = q.top().second;
	q.pop();
	if (vis[node]) continue;
	vis[node] = true;
	for (auto j : adj[node]) {
		ll x = j.first, w = j.second;
		if (dist[node] + w < dist[x]) {
			dist[x] = dist[node] + w;
			q.push(make_pair(-dist[x], x));
		}
	}
}
