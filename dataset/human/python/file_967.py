N = int(input())
S = input()
ss = [s == 'W' for s in S]

def mul(a, b):
    return (a * b) % (10**9 + 7)

ans = 1
num = 0
for s in ss:
    if num % 2 == s:
        num += 1
    else:
        ans = mul(ans, num)
        num -= 1

if num > 0:
    ans = 0

for i in range(2, N + 1):
    ans = mul(ans, i)

print(ans)
