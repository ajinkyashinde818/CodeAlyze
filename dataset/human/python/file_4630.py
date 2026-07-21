d = ''
for i in range(26):
    d += chr(ord('a') + i)
for i in range(26):
    d += chr(ord('A') + i)

def decode(c,key):
    i = d.find(c)
    return d[(i-key) % 52]

while True:
    N = int(input())
    if N == 0: break
    ks = list(map(int,input().split()))
    S = input()
    ans = ''
    for i,c in enumerate(S):
        ans += decode(c, ks[i%N])
    print(ans)
