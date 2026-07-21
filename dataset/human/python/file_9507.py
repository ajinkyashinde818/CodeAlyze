from sys import stdin

def main():
    n, k = map(int, stdin.readline().rstrip().split())
    a = [int(x)-1 for x in stdin.readline().rstrip().split()]
    n = a[0]
    his = [-1, n]
    f = his.append
    s = set()
    while True:
        n = a[n]
        if n in s:
            f(n)
            break
        f(n)
        s.add(n)
    idx = his.index(his[-1])
    loop = len(his[his.index(his[-1]):-1])
    if len(his) > k:
        print(his[k]+1)
    else:
        t = (k - idx) % loop
        g = his[idx:-1]
        print(g[t]+1)
main()
