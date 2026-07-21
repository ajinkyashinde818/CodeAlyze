import sys
int1 = lambda x: int(x) - 1
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(500000)

S = readline().decode().rstrip()
q = int(readline())

head = ""
tail = ""
flip = 0
for _ in range(q):
    que = readline().decode().split()
    if len(que) == 1:
        flip += 1

    else:
        if que[1] == '1':
            if flip % 2 == 0:

                head = ''.join([que[2], head])
            else:
                tail = ''.join([tail, que[2]])

        else:
            if flip % 2 == 0:

                tail = ''.join([tail, que[2]])
            else:
                head = ''.join([que[2], head])

if flip % 2 == 0:
    print(''.join([head, S, tail]))
else:
    print(''.join([tail[::-1], S[::-1], head[::-1]]))
