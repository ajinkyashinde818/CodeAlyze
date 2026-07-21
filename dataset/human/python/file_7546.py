import sys
input = sys.stdin.readline

S = input().strip()
Q = int(input())

reverse = False

before = ""
after = ""

for _ in range(Q):
    s = input().strip()
    if s[0] == "1":
        reverse = not reverse
    else:
        _, f, c = s.split()
        if f == "1":
            if reverse:
                after = after + c
            else:
                before = c + before
        else:
            if reverse:
                before = c + before
            else:
                after = after + c

if reverse:
    print(after[::-1] + S[::-1] + before[::-1])
else:
    print(before + S + after)
