import sys

def machi(k,W):
    visited = set()
    t = 0
    time = 0
    result = []
    while not t in visited:
        if time > k:
            return -1, result
        visited.add(t)
        result.append(t)
        t = W[t] - 1
        time += 1
    bp = result.index(t)
    return bp,result

        

readline = sys.stdin.readline
readall = sys.stdin.read
ns = lambda: readline().rstrip()
ni = lambda: int(readline().rstrip())
nm = lambda: map(int, readline().split())
nl = lambda: list(map(int, readline().split()))
prl = lambda x: print(*x ,sep='\n')


n,k = nm()
a = nl()
bp,roop = machi(k,a)
if bp == -1:
    print(roop[-1]+1)
    exit()

l_dist = len(roop[bp:])
f_dist = bp
fs = k - f_dist
arp = f_dist + (fs % l_dist)
print(roop[arp]+1)
