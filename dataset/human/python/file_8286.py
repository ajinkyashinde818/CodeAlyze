import sys
input = sys.stdin.readline

def main():
  n = int(input())
  alist = list(map(int, input().split()))
  asum = sum(alist)
  rm = (1 + n) * n // 2
  if asum % rm != 0:
    print('NO')
  else:
    k = asum // rm
    d = [a-pa-k for pa, a in zip(alist, alist[1:])]
    d.append(alist[0] - alist[-1] - k)
    nk = 0
    for _d in d:
      if _d % n != 0:
        break
      else:
        nk += abs(_d) // n
    else:
      if nk == k:
        print('YES')
      else:
        print('NO')
      sys.exit(0)
    print('NO')


if __name__ == '__main__':
  main()
