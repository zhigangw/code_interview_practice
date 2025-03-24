#include <bits/stdc++.h>

// int in_a[105], c, ans[105], n_num;

int popcnt(int n){
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

long long calc(int i, int j) {
    return (j == 0) ? (((1ll << i) - 1) << 1) : ((1ll << i) - 1);
}

long long hds[32][2];

int ini[32][2], jnj[32][2], in_a[105], n_num;

void solve(long long m, int k) {
  if(hds[k][m % 2] > m) printf("-1\n");
  else {
    n_num = 0;
    int now_k = k, now_parity = m % 2;
    while(now_k || now_parity){
      int i = ini[now_k][now_parity], j = jnj[now_k][now_parity];
      in_a[++n_num] = int(calc(i, j));
      now_k ^= i, now_parity ^= j;
    }
    in_a[++n_num] = (m - hds[k][m % 2]) / 2;
    in_a[++n_num] = (m - hds[k][m % 2]) / 2;
    printf("%d\n", n_num);
    for(int i = 1; i <= n_num; ++i) printf("%d ", in_a[i]);
    printf("\n");
  }
  return ;
}

typedef std::pair <int, int> pair_ii;

int main(){
  for(int i = 0; i <= 31; ++i)
    for(int j = 0; j <= 1; ++j)
      hds[i][j] = 1e18;
  hds[0][0] = 0;
  std::queue <pair_ii> q;
  q.push(pair_ii(0, 0));
  while(q.size()){
    pair_ii u = q.front(); q.pop();
    for(int i = 1; i <= 31; ++i)
      for(int j = 0; j <= 1; ++j){
        long long x = calc(i, j);
        if(hds[u.first ^ i][u.second ^ j] > hds[u.first][u.second] + x){
          hds[u.first ^ i][u.second ^ j] = hds[u.first][u.second] + x;
          ini[u.first ^ i][u.second ^ j] = i;
          jnj[u.first ^ i][u.second ^ j] = j;
          q.push(pair_ii(u.first ^ i, u.second ^ j));
        }
      }
  }
  int in_t;
  scanf("%d", &in_t);
  while(in_t--) {
    long long m; 
    int k;
    scanf("%lld%d", &m, &k);
    solve(m, k);
  }
  return 0;
}
