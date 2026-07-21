def main():
    import sys

    def input(): return sys.stdin.readline().rstrip()
    
    n = int(input())
    if n%2 == 1:
        print(0)
        exit(0)
    
    def count(k, n):
        now = k
        cnt = 0
        while now <= n:
            cnt += n//now
            now *= k
        return cnt

    n //= 2
    ans = count(5, n)
    print(ans)

if __name__ == '__main__':
    main()
