def test():
    s = list(input())
    t = list(input())
    n = min(len(s),len(t))
    s.sort(); t.sort(reverse=True)
    for i in range(n):
        if s[i] < t[i]:
            print("Yes")
            return
        elif s[i] > t[i]:
            print("No")
            return
        elif s[i] == t[i]:
            pass
    if len(s) < len(t):
        print("Yes")
    else:
        print("No")


if __name__ == "__main__":
    test()
