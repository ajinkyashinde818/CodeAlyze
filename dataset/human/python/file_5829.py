def main():
  n = int(input())
  a_s = list(map(int, input().split(' ')))
  b_s = list(map(int, input().split(' ')))
  c_s = list(map(int, input().split(' ')))
  ans = 0
  for i in range(n):
    ans += (b_s[a_s[i]-1] + c_s[a_s[i]-1]) if (i != n-1 and a_s[i+1]) == (a_s[i] + 1) else b_s[a_s[i]-1]
  print(ans)


if __name__ == '__main__':
  main()
