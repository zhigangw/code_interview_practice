#include <bits/stdc++.h>
using namespace std;
 
const long NEG = -1000000000000000000LL; 
int N_WPT, M_FND;
vector<int> pr_lv;     
vector<long> diffcult_vec, enjoy_vec; 
vector<vector<int>> g_nodes;
vector<long> w2w_enjoy;  
vector<int> acc_in, acc_timer;
int timer = 0;
 
void dfs(int u) {
    acc_in[u] = ++timer;
    for (int v : g_nodes[u]) {
        w2w_enjoy[v] = w2w_enjoy[u] + enjoy_vec[v];
        dfs(v);
    }
    acc_timer[u] = timer;
}
 
 
struct RouteTree {
    int n;
    vector<array<long, 11>> route; 
    vector<int> l_vec;        
 
    RouteTree(int n) : n(n) {
        route.resize(4*n);
        l_vec.assign(4*n, 0);
    }
 
    void apply(int index, int value) {
        if(value == 0) return;
        int next_l = l_vec[index] + value;
        array<long, 11> next_array;
        if(next_l >= 11) {
            for (int i = 0; i < 11; i++) next_array[i] = NEG;
        } else {
           
            for (int j = 0; j < 11; j++) {
                if(j - value >= 0)
                    next_array[j] = route[index][j - value];
                else
                    next_array[j] = NEG;
            }
        }
        route[index] = next_array;
        l_vec[index] = next_l;
        if(l_vec[index] > 11) l_vec[index] = 11; 
    }
 
    void push_back(int index) {
        if(l_vec[index] != 0) {
            apply(index*2, l_vec[index]);
            apply(index*2+1, l_vec[index]);
            l_vec[index] = 0;
        }
    }
 
    array<long, 11> merge(const array<long, 11>& leftArr, const array<long, 11>& rightArr) {
        array<long, 11> res;
        for(int i = 0; i < 11; i++){
            res[i] = max(leftArr[i], rightArr[i]);
        }
        return res;
    }
 
    void build_tree(vector<array<long, 11>> &base, int index, int l, int r) {
        if(l == r) {
            route[index] = base[l];
            return;
        }
        int mid = (l+r)/2;
        build_tree(base, index*2, l, mid);
        build_tree(base, index*2+1, mid+1, r);
        for (int i = 0; i < 11; i++) {
            route[index][i] = max(route[index*2][i], route[index*2+1][i]);
        }
    }
 
    void update_route(int index, int l, int r, int ql, int qr, int value) {
        if(ql > r || qr < l) return;
        if(ql <= l && r <= qr) {
            apply(index, value);
            return;
        }
        push_back(index);
        int mid = (l+r)/2;
        update_route(index*2, l, mid, ql, qr, value);
        update_route(index*2+1, mid+1, r, ql, qr, value);
        for (int i = 0; i < 11; i++) {
            route[index][i] = max(route[index*2][i], route[index*2+1][i]);
        }
    }
 
    array<long, 11> query() {
        return route[1];
    }
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N_WPT;
    pr_lv.resize(N_WPT+1, 0);
    diffcult_vec.resize(N_WPT+1, 0);
    enjoy_vec.resize(N_WPT+1, 0);
    g_nodes.assign(N_WPT+1, vector<int>());
    w2w_enjoy.resize(N_WPT+1, 0);
    acc_in.resize(N_WPT+1, 0);
    acc_timer.resize(N_WPT+1, 0);
    
    for (int i = 2; i <= N_WPT; i++){
        cin >> pr_lv[i] >> diffcult_vec[i] >> enjoy_vec[i];
        g_nodes[pr_lv[i]].push_back(i);
    }
    
    w2w_enjoy[1] = 0;
    dfs(1);
    
    vector<array<long, 11>> base(N_WPT+1);
    for (int u = 1; u <= N_WPT; u++){
        array<long, 11> arr_ll;
        arr_ll[0] = w2w_enjoy[u];
        for (int k = 1; k < 11; k++){
            arr_ll[k] = NEG;
        }
        base[acc_in[u]] = arr_ll;
    }
    
    RouteTree route_t(N_WPT);
    route_t.build_tree(base, 1, 1, N_WPT);
    
    vector<tuple<long, int, int, int>> edges;
    for (int i = 2; i <= N_WPT; i++){
        edges.push_back({diffcult_vec[i], acc_in[i], acc_timer[i], i});
    }
    sort(edges.begin(), edges.end(), [](auto &a, auto &b){
        return get<0>(a) > get<0>(b);
    });
    
    cin >> M_FND;

    vector<long> results(M_FND, 0);

    vector<tuple<long,int,int>> queries;

    for (int j = 0; j < M_FND; j++){
        int s, c;
        cin >> s >> c;
        queries.push_back({s, c, j});
    }

    sort(queries.begin(), queries.end(), [](auto &a, auto &b){
        return get<0>(a) > get<0>(b);
    });
    
    int edgeIndex = 0;
    for (auto &q : queries){
        long s;
        int c, rd;
        tie(s, c, rd) = q;
        while (edgeIndex < edges.size() && get<0>(edges[edgeIndex]) > s) {
            long diff;
            int L, R, node;

            tie(diff, L, R, node) = edges[edgeIndex];

            route_t.update_route(1, 1, N_WPT, L, R, 1);

            edgeIndex++;
        }
        array<long, 11> cur = route_t.query();
        long best = NEG;
        for (int k = 0; k <= c; k++){
            best = max(best, cur[k]);
        }
        if(best < 0) best = 0;
        results[rd] = best;
    }
    
    for (int i = 0; i < M_FND; i++){
        cout << results[i] << "\n";
    }
    
    return 0;
}