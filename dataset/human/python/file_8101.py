import sys
input = sys.stdin.readline

def main():
    K, S = [int(x) for x in input().split()]
    ans = 0
    for x in range(K + 1):
        for y in range(K + 1):
            z = S - x - y
            if z < 0 or z > K:
                continue
            else:
                ans += 1

    print(ans)




if __name__ == '__main__':
    main()
