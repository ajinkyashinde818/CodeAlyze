def resolve():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))
    s = 0
    before = 0
    for ai in a:
        s += b[ai - 1]
        if ai == before + 1 and before > 0:
            s += c[before - 1]
        before = ai
    print(s)


if __name__ == "__main__":
    resolve()
