import sys
input = sys.stdin.readline
def main():
    K, S = map(int, input().split())
    CNT = 0
    for x in range(K+1):
        for y in range(K+1):
            if S - x -y >= 0 and S - x -y <= K:
                CNT += 1
    print(CNT)            

if __name__ == '__main__':
    main()
