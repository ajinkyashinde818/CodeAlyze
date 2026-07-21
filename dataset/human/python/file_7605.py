import sys
range = xrange
input = raw_input

S = input()
start = []
end = []
par = 1

q = int(input())
for _ in range(q):
    quer = input()
    if quer == '1':
        par ^= 1
    else:
        _, f, c = quer.split()
        f = int(f) - 1
        if par ^ f:
            start.append(c)
        else:
            end.append(c)

T = ''.join([''.join(reversed(start)), S, ''.join(end)])

if par:
    print T
else:
    print T[::-1]
