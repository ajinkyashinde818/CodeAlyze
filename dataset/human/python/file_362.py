import math

def main():
    n = int(input())
    a = [int(t) for t in input().split()]

    m = 0
    if 0 in a or len([x for x in a if x<0])%2==0:
        m = sum([abs(x) for x in a])
    else:
        a_ = [abs(x) for x in a]
        m = sum(a_)-2*min(a_)

    print(m)

if __name__ == "__main__":
    main()
