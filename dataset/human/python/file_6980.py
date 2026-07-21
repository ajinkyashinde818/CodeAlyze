rr = raw_input
rri = lambda: int(rr())
rrm = lambda: map(int, rr().split())

from collections import deque

A = deque(rr())
flipped = 0

Q = rri()
for _ in xrange(Q):
    query = rr().split()
    if query[0] == '1':
        flipped ^= 1
    else:
        f, c = query[1:]
        f = int(f)
        if f == 1:
            if flipped == 0:
                A.appendleft(c)
            else:
                A.append(c)
        else:
            if flipped == 0:
                A.append(c)
            else:
                A.appendleft(c)
    #print A, flipped

if flipped == 0:
    print "".join(A)
else:
    print "".join(reversed(A))
