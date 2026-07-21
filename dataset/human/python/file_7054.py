import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
from collections import deque
 
S = deque(readline().rstrip().decode())
Q = int(readline())
query = readlines()
 
rev = False
for q in query:
    if q[0] == ord('1'):
        rev = not rev
    else:
        _, f, c = q.decode().split()
        f = int(f)
        if rev ^ (f == 1):
            S.appendleft(c)
        else:
            S.append(c)
 
T = ''.join(S)
if rev:
    T = T[::-1]
print(T)
