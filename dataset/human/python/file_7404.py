if __name__ == '__main__':
    d = input()
    n = int(input())
    qs = [input() for e in range(n)]
    s = []
    e = []
    r = False
    for q in qs:
        if q == '1':
            r = not(r)
        elif q.startswith("2 1"):
            e.append(q[-1]) if r else s.append(q[-1])
        else:
            s.append(q[-1]) if r else e.append(q[-1])
    print("".join(e[::-1]) + d[::-1] + "".join(s) if r else "".join(s[::-1]) + d + "".join(e))
