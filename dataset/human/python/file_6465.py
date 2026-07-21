import sys
def input():
    return sys.stdin.readline()[:-1]
def gcd(a,b):
    if b == 0:
        return a
    return gcd(b,a%b)

def main():
    N = int(input())
    if N%2 == 1:
        print(0)
    else:
        t = 2*5
        s = 0
        while t <= N:
             s += N//t
             t *= 5
        print(s)
if __name__ == '__main__':
    main()
