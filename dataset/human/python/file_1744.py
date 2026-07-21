n, m = map(int, input().split())

a = []
for i in range(n):
   a.append(input())

b = []
for i in range(m):
   b.append(input())

def func(base, target):
   for i in range(n-m+1):
      check = base[i:i+m]
      for j in range(n-m+1):
         check2 = [line[j:j+m] for line in check]
         if check2 == target:
            return print('Yes')
   return print('No')

func(a,b)
