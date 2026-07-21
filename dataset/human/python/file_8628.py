def main():
    import sys
    from collections import defaultdict
    K,N=list(map(int,sys.stdin.readline().split()))
    AL=list(map(int,sys.stdin.readline().split()))
    diff=[AL[i]-AL[i-1] for i in range(1,N)]
    diff.append(K-AL[-1]+AL[0])
    print(K-max(diff))


main()
