mod = 10**9 + 7

def factorial(n):
    res = 1
    for p in range(2,n+1):
        res *= p
        res %= mod
    return res

N = int(input())
S = input()

T = "L"

L = 0
R = 0

for i in range(1,2*N):
    if S[i] == "W":
        if (L - R + 1) % 2 == 0:
            R += 1
            T += "R"
        else:
            L += 1
            T += "L"
    else:
        if (L - R + 1) % 2 == 0:
            L += 1
            T += "L"
        else:
            R += 1
            T += "R"

if T[-1] == "L" or T.count("L") > N:
    print(0)
    exit()

L = 0
ans = 1

for i in range(2*N):
    if T[i] == "L":
        L += 1
    else:
        ans *= L
        ans %= mod
        L -= 1

ans *= factorial(N)
ans %= mod
print(ans)
