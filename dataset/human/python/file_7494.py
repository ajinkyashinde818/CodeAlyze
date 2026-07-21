import sys
input = sys.stdin.readline

s = input().strip()
qq = int(input())

rev = False
pre = ''
suf = ''
for _ in range(qq):
    q = input().strip()
    if q[0] == '1':
        rev = not rev
    else:
        c = q[4]
        if not rev:
            if q[2] == '1':
                pre += c
            else:
                suf += c
        else:
            if q[2] == '1':
                suf += c
            else:
                pre += c
ans = pre[::-1] + s + suf
if rev:
    ans = ans[::-1]
print(ans)
