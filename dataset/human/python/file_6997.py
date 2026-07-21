def main():
    s = input()
    q = int(input())
    r = 1
    front = ""
    back = ""
    for _ in range(q):
        n, *fc = input().split()
        if n == "1":
            r *= -1
        else:
            f, c = fc
            f = 1 if f == "1" else -1
            if f*r == 1:
                front += c
            else:
                back += c
    if r == 1:
        print(front[::-1]+s+back)
    else:
        print(back[::-1]+s[::-1]+front)

if __name__ == "__main__":
    main()
