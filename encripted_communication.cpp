#include <bits/stdc++.h>

int N, A, B, c[200005], d[200005];
std::map <int, int> map_t, visited;
long long accumulated = 0ll;

void dfs(int x){
  if(visited.find(x) != visited.end()) return ;
  visited[x] = 1;
  if(A - x != x && map_t.find(A - x) != map_t.end() && visited.find(A - x) == visited.end()){
    int a_x = std::min(map_t[x], map_t[A - x]);
    map_t[x] -= a_x, map_t[A - x] -= a_x;
    accumulated += 1ll * a_x;
    dfs(A - x);
  }
  if(A != B && B - x != x && map_t.find(B - x) != map_t.end() && visited.find(B - x) == visited.end()){
    int a_x = std::min(map_t[x], map_t[B - x]);
    map_t[x] -= a_x, map_t[B - x] -= a_x;
    accumulated += 1ll * a_x;
    dfs(B - x);
  }
  return ;
}

int main(){
  scanf("%d%d%d", &N, &A, &B);
  for(int i = 1; i <= N; ++i){
    scanf("%d%d", &c[i], &d[i]);
    map_t[d[i]] = c[i];
  }
  for(int i = 1; i <= N; ++i){
    int marker = 0;
    if(map_t.find(A - d[i]) != map_t.end() && A - d[i] != d[i]) ++marker;
    if(A != B && map_t.find(B - d[i]) != map_t.end() && B - d[i] != d[i]) ++marker;
    if(marker == 1) dfs(d[i]);
  }
  if(A % 2 == 0 && map_t.find(A / 2) != map_t.end()) accumulated += map_t[A / 2] / 2;
  if(A != B && B % 2 == 0 && map_t.find(B / 2) != map_t.end()) accumulated += map_t[B / 2] / 2;
  printf("%lld\n", accumulated);
  return 0;
}
