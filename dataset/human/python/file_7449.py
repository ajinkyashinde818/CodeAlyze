import sys

rr = lambda: sys.stdin.readline().rstrip()
rs = lambda: sys.stdin.readline().split()
ri = lambda: int(sys.stdin.readline())

flag = False
s = rr()
q = ri()
front = ''
end = ''
for _ in range(q):
    query = list(rs())
    if query[0] == '1':
        flag = not flag
        continue
    else:
        f = int(query[1])
        c = query[-1]
        if flag == True:
            if f == 1:
                end += c
            else:
                front = c+front
        else:
            if f == 1:
                front = c+front
            else:
                end += c
if flag:
    print((front+s+end)[::-1])
else:
    print(front+s+end)
