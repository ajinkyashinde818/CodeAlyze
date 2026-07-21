import sys
input = sys.stdin.readline

def main():
    k, s = map(int, input().split())
    ans = 0
    for x in range(k+1):
        if x > s:
            break
        for y in range(k+1):
            if x + y > s:
                break
            if s - (x + y) <= k:
                ans += 1

    print(ans)

if __name__ == '__main__':
    main()
