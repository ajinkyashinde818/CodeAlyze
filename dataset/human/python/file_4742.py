def abc082_b():
    s = sorted(input())
    t = sorted(input(), reverse=True)

    for i in range(min(len(s), len(t))):
        if ord(s[i]) < ord(t[i]):
            print("Yes")
            return 0

    if len(s) < len(t):
        for c in s:
            if c in t:
                t.remove(c)
            else:
                print("No")
                return 0
        print("Yes")
        return 0

    print("No")


abc082_b()
