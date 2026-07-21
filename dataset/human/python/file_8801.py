def solve():
  k, n = list(map(int, input().split()))
  a = list(map(int, input().split()))

  dist = [a[i + 1] - a[i] for i in range(n - 1)]
  dist.append(a[0] + k - a[n - 1])
  
  max_dist = max(dist)
  
  print(k - max_dist)

if __name__ == "__main__":
  solve()
