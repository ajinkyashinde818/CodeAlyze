def parse():
  N, K = map(int, input().split(" "))
  A = []
  for a in input().split(" "):
    A.append(int(a) - 1)
  return N, K, A

def fast_pow(x, n):
    """
    O(log n)
    """
    if n == 0:
        return 1

    K = 1
    while n > 1:
        if n % 2 != 0:
            K *= x
        x *= x
        n //= 2

    return K * x

def fast_mod(x, N):
  # return x % N
  if N % 2 == 0:
    return x & (N - 1)
  else:
    return x % N

def main():
  N, K, A = parse()
  # print(N, K, A)

  # 移動
  town = 0
  route = [0]
  loop_start_index = None
  i = 0
  visited = [False for i in range(N)]
  visited[0] = True
  for i in range(K):
    # 次の町に移動
    town = A[town]

    if visited[town]:
      # ループ検出
      loop_start_index = route.index(town)
      break

    visited[town] = True
    route.append(town)

  if loop_start_index == None:
    print(town + 1)
  else:
    loop_route = route[loop_start_index:]
    # print(loop_route, K, i)
    print(loop_route[(K - (i + 1)) % len(loop_route)] + 1)
    # print(loop_route[])
  # print(town)
  exit(0)

  # 経路の計算
  route = []
  next_town = A[0]
  town = 0
  while not (next_town in route):  # 既出の町に行く場合
    route.append(town)
    next_town = A[town]
    town = next_town
  once_route = route[:route.index(next_town)]
  loop_route = route[route.index(next_town):]
  # print("once_route:", once_route)
  # print("loop_route:", loop_route)
  
  

  # print([town + 1 for town in route])
  # print("K %% len(loop_route):", K % len(loop_route))
  # print(route[K % len(loop_route) + len(once_route)] + 1)
  if K >= len(route) and len(once_route) > 0:
    # print("loop")
    loop_K = K - len(route)
    print(loop_route[fast_mod(loop_K, len(loop_route))] + 1)
    # print(loop_route[loop_K % len(loop_route)] + 1)
  else:
    # print("normal")
    # print(route[fast_mod(K, len(loop_route))] + 1)
    # print("K:", K)
    # print("K %% len(route):", K % len(route))
    print(route[fast_mod(K, len(route))] + 1)
    # print(route[K % len(route)] + 1)

if __name__ == "__main__":
  main()
