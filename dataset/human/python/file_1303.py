def input():
    import sys
    return sys.stdin.readline().rstrip()


def main():
    import math
    import collections
    import itertools

    n = int(input())
    as_ = list(map(int, input().split()))
    
    sunuke = as_[0]
    araiguma = sum(as_[1:])
    diff = abs(sunuke - araiguma)
    for i in range(1, n - 1):
        sunuke += as_[i]
        araiguma -= as_[i]
        diff = min(diff, abs(sunuke - araiguma))

    print(diff)
    
if __name__ == '__main__':
    main()
