import sys

readline = sys.stdin.readline

def main():
    N, M = map(int, readline().split())
    n = []
    for _ in range(N):
        n.append(list(readline()[:-1]))
    m = []
    for _ in range(M):
        m.append(list(readline()[:-1]))

    s = N - M
    if s == 0:
        if n == m:
            flag = True
        else:
            flag = False

    for i in range(s):
        for j in range(s):
            flag = True
            for k in range(M):
                if n[i+k][j:j+M] != m[k]:
                    flag = False
                    break
            if flag:
                break
        if flag:
            break
    if flag:
        print('Yes')
    else:
        print('No')
            
if __name__ == "__main__":
    main()
