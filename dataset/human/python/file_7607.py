import sys

s = sys.stdin.readline().strip()
q = int(sys.stdin.readline().strip())

heads = []
tails = []
is_reverse = -1

for i in range(q):
    query = sys.stdin.readline().strip()

    if query[0] == '1':
        is_reverse *= -1
    else:
        t, f, c = query.split()
        if f == '1':  # to current head
            if is_reverse == 1:
                tails.append(c)
            else:
                heads.append(c)
        else:  # to current tail
            if is_reverse == 1:
                heads.append(c)
            else:
                tails.append(c)

if is_reverse == 1:
    print(''.join(tails[::-1]) + s[::-1] + ''.join(heads))
else:
    print(''.join(heads[::-1]) + s + ''.join(tails))
