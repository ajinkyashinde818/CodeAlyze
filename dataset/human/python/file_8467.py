def main():
  k, n = map(int, input().split())
  dis = tuple(map(int, input().split()))

  diff = [dis[i + 1] - dis[i] for i in range(n - 1)]
  diff.append(k - dis[-1] + dis[0])

  max_dis = 0
  max_idx = 0
  for i, d in enumerate(diff):
    if d > max_dis:
      max_dis = d
      max_idx = i

  diff[max_idx] = 0

  print(sum(diff))

main()
