import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


n = int(input())
s = input()
s = list(s)
l = []
M = 10**9+7
prv = "L"
l.append(prv)
if not (s[0]==s[-1]=="B"):
    ans = 0
else:
    for i in range(1,2*n-1):
        if s[i-1]==s[i]:
            l.append("R")
            s[i] = "W" if s[i]=="B" else "B"
        elif s[i-1]!=s[i]:
            l.append("L")
        else:
            ans = 0
            break
    else:
        l.append("R")
        if sum(item=="R" for item in l)!=n:
            ans = 0
        else:
            num = 0
            ans = 1
            for item in l[::-1]:
                if item=="R":
                    num += 1
                else:
                    ans *= num
                    ans %= M
                    num -= 1
            for i in range(1, n+1):
                ans *= i
                ans %= M
print(ans)
