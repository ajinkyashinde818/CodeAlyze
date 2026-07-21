def main():
  N, K = map(int, input().split())
  A = list(map(int, input().split()))
  flag = [False] * N
  flag[0] = True
  move = [0]
  num = 0
  while True:
    num += 1
    c_next =  A[move[-1]]-1
    move.append(c_next)
    if flag[c_next]:
      break
    else:
      flag[c_next] = True
  for i, j in enumerate(move):
    if j == c_next:
      if c_next == 0:
        key = 0
      else:
        key = i
      c_cycle = num-key
      break
  if K < key:
    print(move[K]+1)
  else:
    K -= key
    K %= c_cycle
    print(move[key + K]+1)

if __name__  == "__main__":
  main()
