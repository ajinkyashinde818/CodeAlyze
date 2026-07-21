import numpy as np

def main():
    n=int(input())
    a=[int(x)-1 for x in input().split()]
    b=[int(x) for x in input().split()]
    c=[int(x) for x in input().split()]

    s=0
    p=n
    for i in range(n):
        s += b[a[i]]
        if p == a[i]-1:
            s += c[p]
        p=a[i]

    print(s)




if __name__ == '__main__':
    main()
