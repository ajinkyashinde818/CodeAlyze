def main():
  N, K, S = (int(_) for _ in input().split())
  output = []
  for _ in range(K):
    output.append(S)
  if S == 10 ** 9: a = S - 1
  else:
    a = S + 1
  for _ in range(N - K):
    output.append(a)
  print(*output)
  return

if __name__ == '__main__':
  main()
