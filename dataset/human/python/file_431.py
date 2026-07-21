import sys
input = sys.stdin.readline

def main():
    N = int(input())
    A = [int(x) for x in input().split()]
    count = 0
    ans = 0
    mi = float("inf")

    for a in A:
        ans += abs(a)
        mi = min(mi, abs(a))
        if a <= 0:
            count += 1

    if count & 1:
        print(ans - mi * 2)
    else:
        print(ans)

    
    

if __name__ == '__main__':
    main()
