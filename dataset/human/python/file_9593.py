def main():

  N, K = map(int, input().split())   
  A = [0] + list(map(int, input().split()))
  cur = 1
  visited = [-1] * (N + 1)
  visited[cur] = 0
  for i in range(1, K + 1):
    next_cur = A[cur]
    if next_cur == cur:
      print(next_cur)
      return
    elif visited[next_cur] != -1:
      mod = i - visited[next_cur]
      start = visited[next_cur]
      break
    else:
      visited[next_cur] = visited[cur] + 1
      cur = next_cur
  else:
    print(next_cur)
    return
  K = (K - start) % mod
  print(visited.index(K+start))
  
  
if __name__ == "__main__":
  main()
