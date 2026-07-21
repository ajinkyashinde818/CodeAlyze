import sys
input = sys.stdin.readline

s = input().split()[0]
q = int(input())

left, right = [], []
state = 1
for _ in range(q):
    q_i = input().split()
    if len(q_i) == 1:
        state = (state)%2 + 1
    else:
        _, f, c = q_i
        f = int(f)
        if (f+state)%2 == 0:
            left += [c]
        else:
            right += [c]
if state == 1:
    print(''.join(left[::-1]) + s + ''.join(right))
else:
    print(''.join(right[::-1]) + s[::-1] + ''.join(left))
