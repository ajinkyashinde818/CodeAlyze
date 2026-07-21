D = "mcxi"
V = [1000, 100, 10, 1]
def conv1(s):
    v = 0; t = 1
    for c in s:
        idx = D.find(c)
        if idx > -1:
            v += t * V[idx]
            t = 1
        else:
            t = int(c)
    return v
def conv2(v):
    s = []
    for i in range(4):
        if v >= V[i]:
            k = v // V[i]
            if k > 1:
                s.append(str(k))
            s.append(D[i])
            v -= k * V[i]
    return "".join(s)

N = int(input())
ans = []
for i in range(N):
    p, q = input().split()
    ans.append(conv2(conv1(p) + conv1(q)))
print(*ans, sep='\n')
