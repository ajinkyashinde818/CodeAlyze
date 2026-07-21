import sys
input = sys.stdin.readline

a,b = ( int(x) for x in input().split() )

min_ = min([a,b])

ret = a * b

for i in reversed(range(1,min_+1)):
  if a % i == 0 and b % i == 0:
    ret = int(a * b / i)
    break

print(ret)
