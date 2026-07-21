import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10000000)
s = 0 
def main():
    n, k = map(int, readline().split())
    a = [int(i)-1 for i in readline().split()]
    done = [0 for _ in range(n)] 
    cycle = []
    def dfs(x):
        global s
        if done[x] == 1:
            s = x
            return
        nx = a[x]
        done[x] = 1
        cycle.append(x)
        dfs(nx)

    dfs(0)
    start_idx = cycle.index(s)
    ln = len(cycle)
    if k < ln: 
        print(cycle[k]+1)
    else:
        k -= start_idx
        idx = start_idx+(k%(ln-start_idx))
        print(cycle[idx]+1)
if __name__ == '__main__':
    main()
