def solve():
    a = input()
    q = int(input())
    
    top = []
    tail = []
    rev = 0
    for _ in range(q):
        _q = [i for i in input().split()]
        t, f, c =0, 0, 0
        t = int(_q[0])
        if t == 2:
            f, c = int(_q[1]), _q[2]
        
        if t == 1:
            rev = 1 - rev
        elif t == 2:
            if (f + rev) % 2 == 1:
                top.append(c)
            else:
                tail.append(c)
                
    if rev == 1:
        a = a[::-1]
        _top = tail
        tail = top
        top = _top
    
    print("".join(list(reversed(top))), end="")
    print(a, end="")
    print("".join(tail))


if __name__ == "__main__":
    solve()
