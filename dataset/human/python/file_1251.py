import itertools
def main():
    n=int(input())
    A=[int(i) for i in input().split()]
    rui = list(itertools.accumulate(A))
    mi = 300000000000
    ind = n-1

    for i in range(n-1):
        mi=min(abs(rui[i]-(rui[ind]-rui[i])),mi)

    print(mi)

if __name__ == '__main__':
    main()
