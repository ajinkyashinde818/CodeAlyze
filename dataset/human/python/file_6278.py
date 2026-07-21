def main():
    n = input()
    l = len(n)
    ans = 0
    p = 0

    for i in range(l-1, -1, -1):
        v = int(n[i])
        if p == 1:
            v += 1
        if v > 5 or (i != 0 and v == 5 and int(n[i-1]) >= 5):
            ans += (10-v)
            p = 1
        else:
            ans += v
            p = 0
    if p == 1:
        ans += 1

    print(ans)
main()
