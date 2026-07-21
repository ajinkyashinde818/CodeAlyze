import sys

def input():
    return sys.stdin.readline()[:-1]

def mi():
    return map(int, input().split())

def ii():
    return int(input())

def main():
    K, S = mi()
    cnt = 0
    for x in range(K+1):
        for y in range(K+1):
            z = S-x-y
            if 0 <= z <= K:
                cnt += 1
    print(cnt)

if __name__ == '__main__':
    main()
