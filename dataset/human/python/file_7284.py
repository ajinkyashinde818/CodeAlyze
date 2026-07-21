import sys
input = sys.stdin.readline

S = input().rstrip()
Q = int(input())
head = ''
tail = ''
rev = False

for _ in range(Q):
    query = list(input().split())
    if query[0] == '1':
        if rev:
            rev = False
        else:
            rev = True
    elif query[0] == '2':
        f = query[1]
        c = query[2].rstrip()
        if f == '1':
            if rev:
                tail = tail + c
            else:
                head = c + head
        else:
            if rev:
                head = c + head
            else:
                tail = tail + c
if rev:
    tmp = head + S + tail
    print(tmp[::-1])
else:
    print(head + S + tail)
