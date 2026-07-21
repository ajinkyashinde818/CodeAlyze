import sys
read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines

def main():
    K,S = map(int, readline().split())

    ans = 0
    for x in range(K+1):
        for y in range(K+1):
            if 0 <= S - x - y <= K:
                ans += 1 

    print(ans)


if __name__ == "__main__":
    main()
