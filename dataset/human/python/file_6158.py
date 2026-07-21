def ii():
    return int(input())
def mi():
    return map(int, input().split())
def li():
    return list(mi())

a, b, c = mi()

p = min(b, c)
ans = 2 * p
b -= p
c -= p
if c:
    ans += min(a, c)
    if c > a:
        ans += 1
if b:
    ans += b
print(ans)
