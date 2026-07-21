max2 = lambda x,y: x if x > y else y
min2 = lambda x,y: x if x < y else y

import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline


def solve(A,B):
    N = len(A)
    start = [-1]*(N+1)
    end = [-1]*(N+1)
    start[A[0]] = 0
    end[A[-1]] = N

    for i,(p,a) in enumerate(zip(A,A[1:]),start=1):
        if a!=p:
            start[a] = i
            end[p] = i

    ca = [0]*(N+1)
    cb = [0]*(N+1)
    for a in A:
        ca[a] += 1
    for b in B:
        cb[b] += 1

    order = sorted((v for v in range(N+1) if ca[v] or cb[v]), key=lambda v:ca[v]+cb[v])
    res = [-1]*N
    # print(cnt)
    # print(start)
    # print(order)
    try:
        remaining = [(v,cb[v]) for v in order]
        s = set(v for v,_ in remaining)
        for v in reversed(order):
            if v not in s:
                continue
            add_back = None
            i = start[v]
            j = end[v]
            while i < j:
                u,r = remaining.pop()
                if u == v:
                    add_back = (u,r)
                    u,r = remaining.pop()
                n = min2(r,j-i)
                for k in range(i,i+n):
                    res[k] = u
                i += n
                if n < r:
                    remaining.append((u,r-n))
                else:
                    s.discard(u)
            if add_back:
                remaining.append(add_back)

        i = 0
        for u,r in remaining:
            while r > 0:
                while res[i] >= 0:
                    i += 1
                res[i] = u
                r -= 1
                i += 1
    except IndexError:
        return None
    return res


if __name__ == '__main__':
    N = int(readline())
    A = list(map(int,readline().split()))
    B = list(map(int,readline().split()))
    res = solve(A,B)
    if res is None:
        print('No')
    else:
        print('Yes')
        print(*res)
