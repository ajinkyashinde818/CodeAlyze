import sys
input=sys.stdin.readline

def main():
    D,G = map(int, input().split())
    P = []
    C = []
    for i in range(D):
        p,c = map(int, input().split())
        P.append(p)
        C.append(c)
    min_n = 100*D
    for i in range(2**D):
        s = 0
        n = 0
        max_zero_index = -1
        for j in range(D):
            if (i >> j) & 1:
                s += (j+1)*100*P[j] + C[j]
                n += P[j]
            else:
                max_zero_index = max(max_zero_index, j)
        if max_zero_index != -1:
            tmp = P[max_zero_index]
            while s < G and tmp > 0:
                tmp -= 1
                n += 1
                s += (max_zero_index+1)*100
        if s >= G:
            min_n = min(min_n, n)
    print(min_n)

if __name__ == '__main__':
    main()
