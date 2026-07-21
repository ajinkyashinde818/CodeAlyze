def main():
    k, s = input().split()
    k, s = int(k), int(s)

    count = 0
    for x in range(k+1):

        if k*2 + x < s:
            continue

        for y in range(k+1):
            if 0 <= (s - x - y) <= k:
                count += 1

    print(count)


if __name__ == "__main__":
    main()
