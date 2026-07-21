import sys
s = input()

l = s.replace("x", "")
ll = len(l) // 2
lr = len(l) - ll
if l[:ll] != l[lr:][::-1]:
    print(-1)
    sys.exit()

xcnt = [0] * lr
c = 0
cnt = 0
i = 0
while c != lr:
    if s[i] != "x":
        xcnt[c] = cnt
        c += 1
        cnt = 0
    else:
        cnt += 1
    i += 1
    
c = 0
cnt = 0
i = len(s) - 1
while c != lr:
    if s[i] != "x":
        xcnt[c] -= cnt
        xcnt[c] = abs(xcnt[c])
        c += 1
        cnt = 0
    else:
        cnt += 1
    i -= 1

print(sum(xcnt))
