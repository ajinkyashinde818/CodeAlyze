import math
N = int(input())
S = input()
ans = 1
ans_base = 1
numofS = 0  # 線の左端になっている点をSとするとその数はちょうどNでないといけない
line = 0  # 左から順に線を引く。上に何本通っているかをあらわす
for i in range(2*N):
    if S[i] == "B":
        if line % 2 == 0:
            numofS += 1
            line += 1
        else:
            ans_base *= line
            line -= 1
    else:
        if line % 2 == 0:
            ans_base *= line
            line -= 1
        else:
            line += 1
            numofS += 1

    if line < 0:
        ans = 0
        break
    ans_base %= 10**9+7
if numofS != N:
    ans = 0
    # print(numofS)

if ans != 0:
    fact = math.factorial(N)
    fact %= 10**9+7
    ans = ans_base * fact
    ans %= 10**9+7
print(ans)
