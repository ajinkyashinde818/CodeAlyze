k, s = list(map(int, input().split()))

minz = max(0, s-2*k)
maxz = min(s, k)

def f(s, k):
    if k >= s:
        return (s+1)
    else:
        return (2*k-s)+1

ans = 0
for i in range(minz, maxz+1):
    ans += f(s-i, k)

print(ans)
