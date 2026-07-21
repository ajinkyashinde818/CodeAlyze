def main():
    import sys

    def input(): return sys.stdin.readline().rstrip()

    n = int(input())
    a = list(map(int, input().split()))
    s, m = 0, 10**18
    flag = 1
    for x in a:
        s += abs(x)
        flag ^= (x<0)
        m = min(m, abs(x))

    if flag or (0 in a):
        print(s)
    else:
        print(s-2*m)
        
    
    
if __name__ == '__main__':
    main()
