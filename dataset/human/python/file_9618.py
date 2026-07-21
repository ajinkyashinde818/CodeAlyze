n , k = map(int,input().split())
S = list(map(int,input().split()))
l = [1]
for i in range(2*n):
    l.append(S[l[i]-1])

L = len(l)
def f(s, e):
    a = s
    b = s

    while True:
        a += 2
        b += 1
        if a >= e:
            return None
        if l[a] == l[b]:
            break

    a = 0
    while True:
        a += 1
        b += 1
        if b >= e:
            return None
        if l[a] == l[b]:
            break

    return a, b

c, d = f(0, L)
loop = l[c:d]

m = d - c 
A = c + 1
B = d + 1
if k <=  n:
    print(l[k])
else:
   K = (k - c) % m
   print(loop[K])
