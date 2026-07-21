import sys
input = sys.stdin.readline

s = input().strip()
q = int(input())
query = [list(input().strip().split()) for _ in range(q)]

left = ''
right = ''
t = False
for ls in query:
    if len(ls) == 1:
        t = not t
    else:
        two, f, c = ls
        if f == '1':
            if t:
                right += c
            else:
                left += c
        else:
            if t:
                left += c
            else:
                right += c

if t:
    print(right[::-1] + s[::-1] + left)
else:
    print(left[::-1] + s + right)
