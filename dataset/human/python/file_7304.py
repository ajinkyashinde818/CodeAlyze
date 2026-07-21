import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

s = input()
q = int(input())
flag = True
p = ''
m = ''
for i in range(q):
    qfc = input()
    if qfc[0] == '1':
        if flag:
            flag = False
        else:
            flag = True
    else:
        if qfc[2] == '1':
            if flag:
                p += qfc[4]
            else:
                m += qfc[4]
        else:
            if flag:
                m += qfc[4]
            else:
                p += qfc[4]
if flag:
    print(p[::-1] + s + m)
else:
    print(m[::-1] + s[::-1] + p)
