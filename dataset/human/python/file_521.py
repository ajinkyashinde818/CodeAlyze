def resolve():
    n = int(input())
    a = list(map(int, input().split()))
    negative = len([True for ai in a if ai <= 0])
    ans = sum([abs(ai) for ai in a])
    if negative % 2 == 0:
        print(ans)
    else:
        m = min([abs(ai) for ai in a])
        print(ans - m * 2)


if __name__ == "__main__":
    resolve()
