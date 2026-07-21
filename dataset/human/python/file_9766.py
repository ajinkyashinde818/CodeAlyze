import sys
input = sys.stdin.readline
def main():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    D = 1
    LOG = {}
    PATH = []
    for i in range(N):
        PATH.append(D)
        LOG.setdefault(D,i)

        if LOG[D] == i:
            D = A[D-1]
            # print(PATH,LOG, i)
            continue
        else:
            # print("break",D, i)
            break

    # if i-LOG[D] < K:
    if LOG[D] < K:
        K = (K-i)%(i-LOG[D])
        LAST = PATH[LOG[D]+K]
    else:
        LAST = PATH[K]
    print(LAST)

if __name__ == '__main__':
    main()
