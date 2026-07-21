import sys
readline = sys.stdin.readline
write = sys.stdout.write
def solve():
    N = int(readline())
    if N == 0:
        return False
    f = ".*".index
    MP = [list(map(f, readline().strip())) for i in range(N)]
    D = [[0]*N for i in range(N)]
    ds = [0]*N
    for i in range(N):
        MPi = MP[i]
        Di = D[i]
        for j in range(N):
            if MPi[j]:
                ds[j] = 0
            else:
                ds[j] += 1
                Di[j] = ds[j]
    ans = 0
    def gen():
        for i in range(N):
            st = []
            Di = D[i]
            for j in range(N):
                c = Di[j]
                last = j
                while st and st[-1][1] >= c:
                    k, d = st.pop()
                    yield min(d, j-k)
                    last = k
                st.append((last, c))
            while st:
                k, d = st.pop()
                yield min(d, N-k)
    write("%d\n" % max(gen()))
    return True
while solve():
    ...
