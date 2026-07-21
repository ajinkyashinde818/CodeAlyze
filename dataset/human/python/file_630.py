def main():
    n = int(input())
    a_s = list(map(int, input().split(' ')))

    count = 0
    ans = 0
    _min = 10**9

    for a in a_s:
        if a <= 0:
            count += 1
        ans += abs(a)
        _min = min(_min, abs(a))
    if count % 2 == 1:
        ans -= 2*_min
    print(ans)



if __name__ == '__main__':
    main()
