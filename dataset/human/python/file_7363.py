import sys
input = sys.stdin.readline

s = input().strip()
q = int(input())
front = []
back = []
flip = False

for i in range(q):
    query = input()
    if query[0] == '1':
        flip = (not flip)
    else:
        _, f, c = query.split()
        if flip:
            if f == '1':
                back.append(c)
            else:
                front.append(c)
        else:
            if f == '1':
                front.append(c)
            else:
                back.append(c)

if flip:
    print(''.join(back[::-1]) + s[::-1] + ''.join(front))
else:
    print(''.join(front[::-1]) + s + ''.join(back))
