import sys
k, n = map(int, sys.stdin.readline().split())
an = list(map(int, sys.stdin.readline().split()))

dai = an[0]+k-an[-1]

for i in range(1, n):
    if an[i]-an[i-1]>dai:
        dai = an[i]-an[i-1]

print(k-dai)
