from sys import stdin
def LI(): return list(map(int,stdin.readline().rstrip().split()))

tmp = LI()

k,s = [tmp.pop(0) for i in range(2)]

c=0
for i in range(k,-1,-1):
    if i<=s:
        for j in range(k,-1,-1):
            if 0<=s-i-j and s-i-j<=k:
                c += 1

print(c)
