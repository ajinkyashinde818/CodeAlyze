def INT():
    return int(input())

def MI():
    return map(int, input().split())

def LI():
    return list(map(int, input().split()))

N = INT()
a = LI()

x = a[0]
y = sum(a) - x

ans = abs(x - y)

for i in range(1, N - 1):
    x += a[i]
    y -= a[i]
    ans = min(ans, abs(x - y))
    
print(ans)
