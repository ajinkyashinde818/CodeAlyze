import sys

s = input()
q = int(input())
rev = 0
append_front_rev = ''
append_rear = ''

for line in sys.stdin:
    q = line.strip()
    if q == '1':
        rev ^= 1
    else:
        _, f, c = q.split()
        if f == '1':
            if rev == 0:
                append_front_rev += c
            else:
                append_rear += c
        else:
            if rev == 0:
                append_rear += c
            else:
                append_front_rev += c

s = append_front_rev[::-1] + s + append_rear
if rev:
    s = s[::-1]
print(s)
