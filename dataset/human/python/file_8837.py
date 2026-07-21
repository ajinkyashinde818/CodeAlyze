def check(a):
  if a < 0:
    return a * -1
  else:
    return a

def main():
  K, N = map(int, input().split())
  As = list(map(int, input().split()))
  r = []
  r.append(K-As[-1]+As[0])
  for x in range(N-1, -1, -1):
    solve = As[x] - As[x-1]
    r.append(check(solve))
  ans = sorted(r)
  ans.remove(ans[-1])
  print(K-ans[-1])

if __name__ == "__main__":
  main()
