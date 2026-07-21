import sys
input=sys.stdin.readline

def main():
    K,S = map(int, input().split())
    n = 0
    for i in range(K+1):
        for j in range(K+1):
            if S-i-j >= 0 and S-i-j <= K:
                n += 1
    print(n)

if __name__ == '__main__':
    main()
