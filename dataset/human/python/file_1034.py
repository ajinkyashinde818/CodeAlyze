import sys
n = int(input())
s = input()
mod = 10**9 + 7

if s[0] == "W":
    print(0)
    sys.exit()

sg = 1
ans = 1
now = 0
for i in range(1, n*2):
    if s[i] == s[i-1]:
        now = (now+1)%2
    if now == 0:
        sg += 1
    else:
        ans = (ans * sg) % mod
        sg -= 1
    if sg < 0 or sg > n:
        ans = 0
        break
    # print(i,sg)

if sg != 0:
    print(0)
    sys.exit()

for i in range(1, n+1):
    ans = (ans*i) % mod
print(ans)
