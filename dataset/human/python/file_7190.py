import sys
input = sys.stdin.readline
s = input().rstrip()
q = int(input())
query = []
rev = 0
for i in range(q):
    query.append(list(map(str, input().split())))
sa = []
sb = []
for i in range(q):
    if len(query[i]) == 1:
        rev = (rev + 1) % 2
    else:
        if rev == 0:
            if query[i][1] == '1':
                sa.append(query[i][2])
            else:
                sb.append(query[i][2])
        else:
            if query[i][1] == '2':
                sa.append(query[i][2])
            else:
                sb.append(query[i][2])
ssa = ''.join(sa)
ssa = ssa[::-1]
ssb = ''.join(sb)
ss = ssa + s + ssb
if rev == 1:
    ss = ss[::-1]
print(ss)
