import sys
def input(): return sys.stdin.readline().strip()

def main():
    n, m = map(int, input().split())
    A = [input() for _ in range(n)]
    B = [input() for _ in range(m)]
    for i in range(n - m + 1):
        for j in range(n - m + 1):
            correspond = True
            for p in range(m):
                for q in range(m):
                    if A[i + p][j + q] != B[p][q]:
                        correspond = False
                        break
            if correspond:
                print("Yes")
                return
    print("No")

if __name__ == "__main__":
    main()
