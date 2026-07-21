def main():
    s = input()
    n = int(input())
    pre = ''
    suf = ''
    r = 1
    for _ in range(n):
        q = input().split()
        if len(q) == 1:
            r *= -1
            continue
        if r * int(q[1]) in (1, -2):
            pre = q[2] + pre
        else:
            suf += q[2]
    ans = pre + s + suf
    if r == -1:
        ans = ans[::-1]
    print(ans)


if __name__ == '__main__':
    main()
