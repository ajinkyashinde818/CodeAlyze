def main():
    K, S = map(int, input().split())

    ans = 0
    for x in range(min(K, S) + 1):
        for y in range(min(K, S - x) + 1):
            z = S - x - y
            if z < 0 or z > K: continue
            ans += 1

    print(ans)


if __name__ == '__main__':
    main()
