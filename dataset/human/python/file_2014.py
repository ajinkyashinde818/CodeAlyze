def main():
  from collections import Counter
  n = int(input())
  s = input()
  mod = 10**9+7
  c = Counter(s)
  cv = list(c.values())
  cl = len(cv)
  ans = 1
  for i in range(cl):
    ans *= (cv[i]+1)
  print((ans-1)%mod)
main()
