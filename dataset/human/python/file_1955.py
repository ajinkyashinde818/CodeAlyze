from itertools import permutations
def main():
  n, m = map(int, input().split())
  a=[]
  for i in range(n):
    a.append(input())
  b = ""
  for j in range(m):
    b += input()
  for i in range(n - m + 1):
    for j in range(n - m + 1):
      x = ""
      for k in range(m):
        x += a[j+k][i: i + m]
      if b == x:
        print("Yes")
        return
  print("No")
main()
