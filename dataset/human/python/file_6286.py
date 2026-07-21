import sys
input = sys.stdin.readline

n = list(input().strip())
ans = 0

carry = False
for i in range(len(n) - 1, -1, -1):
    p = int(n[i])
    if carry:
        p += 1
        carry = False
    if p == 10:
        carry = True
    elif p >= 6:
        carry = True
        ans += 10 - p
    elif p == 5:
        if i != 0 and int(n[i - 1]) >= 5:
            carry = True
            ans += 5
        else:
            carry = False
            ans += 5
    else:
        ans += p
if carry:
    ans += 1
print(ans)
