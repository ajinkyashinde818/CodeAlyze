import sys
ai = lambda: list(map(int, input().split()))

n = int(input())
a = ai()
d = [a[i]-a[i-1] for i in range(n)]

s = sum(a)
if s % (n*(n+1)//2) != 0:
    print('NO')
    sys.exit()

s //= n*(n+1)//2
d = [i-s for i in d]

if all(i % n == 0 for i in d) and sum(-i//n for i in d if i < 0) == s:
    print('YES')
else:
    print('NO')
