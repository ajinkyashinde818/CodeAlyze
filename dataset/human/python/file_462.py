import sys
input=sys.stdin.readline

def main():
    _ = int(input())
    A = list(map(int, input().split()))
    m = 0
    for i,a in enumerate(A):
        if a < 0:
            m += 1
        A[i] = abs(a)
    if m%2 == 1:
        print(sum(A)-min(A)*2)
    else:
        print(sum(A))

if __name__ == '__main__':
    main()
