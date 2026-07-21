import sys
input = sys.stdin.readline

def main():
    N, M = map(int, input().split())
    A = [input().strip() for i in range(N)]
    B = [input().strip() for i in range(M)]

    ok = False
    for sy in range(N-M+1):
        for sx in range(N-M+1):
            ok = True
            for y in range(M):
                for x in range(M):
                    if A[sy+y][sx+x] != B[y][x]:
                        ok = False
                        break
                if not ok:
                    break
            if ok:
                break
        if ok:
            break
    
    if ok:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()
