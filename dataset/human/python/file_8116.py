K, S = [int(n) for n in input().split()]

def main():

    ans = 0
    for x in range(K + 1):
        for y in range(x + 1):
            z = S - x - y
            if z < 0 or\
                K < z or\
                x < z or\
                y < z:
                continue
            if x == y == z:
                ans += 1
            elif x != y != z:
                ans += 6
            else:
                ans += 3
    print(ans)

if __name__ == '__main__':
    main()
