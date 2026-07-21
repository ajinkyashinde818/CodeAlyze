import sys, math
n = int(input())
s = list(input())
m = 10**9+7
store = 0
ans = 1

for i in range(2*n):
    if i % 2 == 0:
        if s[i] == "B":
            s[i] = "W"
        else:
            s[i] = "B"

for i in range(2*n):
    if s[i] == "W":
        store += 1
    else:
        if store <= 0:
            print(0)
            sys.exit()
        ans = ans % m * store
        store -= 1

if not store == 0:
    print(0)
    sys.exit()

print(ans*math.factorial(n) % m)
