import math

n = int(input())
s = list(input())
mod = 10**9+7

cnt_w = 0
cnt_ans = 1

for i in range(0,n*2):
    if i%2 == 0:
        if s[i] == "B":
            s[i] = "W"
        else:
            s[i] = "B"
    if s[i] == "W":
        cnt_w += 1
        continue
    if s[i] == "B":
        cnt_ans *= cnt_w
        cnt_w -= 1
        cnt_ans %= mod

if s.count("B") != s.count("W"):
    print(0)
    exit()
    
print((cnt_ans*math.factorial(n))%mod)
