import sys
input = sys.stdin.readline
s = input().rstrip('\n')
q = int(input())
s1 = []
s2 = []
k = 0
for i in range(q):
    r = input().rstrip("\n")
    if r == "1":
        k = (k + 1) % 2
    else:
        _, f, c = r.split()
        f = int(f) - 1
        if (k + f) % 2:
            s2.append(c)
        else:
            s1.append(c)

s1.reverse()
ans = s1 + list(s) + s2

if k:
    ans.reverse()
print("".join(ans))
