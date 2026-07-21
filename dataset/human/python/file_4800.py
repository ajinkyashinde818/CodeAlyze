def main():
    s = input()
    t = input()
    sl = [c for c in s]
    tl = [c for c in t]
    sl.sort()
    tl.sort(reverse=True)
    s2 = "".join(sl)
    t2 = "".join(tl)

    if s2 < t2:
        print("Yes")
    else:
        print("No")


if __name__ == '__main__':
    main()
