def main():
    a = input().split(" ")
    K = int(a[0])
    S = int(a[1])
    X = Y = Z = count = 0

    for x in range(K + 1):
        for y in range(K + 1):
            xy = x + y
            if S - xy <= K and 0 <= S - xy:
                count += 1
    print(count)

if __name__ == '__main__':
    main()
