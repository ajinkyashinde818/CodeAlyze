import sys
sys.setrecursionlimit(10**7)

def main():
    def gcd(a, b):
        if b == 0:
            return a
        else:
            return gcd(b, a%b)

    def lcd(a, b):
        return int(a / gcd(a, b)) * b
    
    a, b = map(int, input().split())
    ans = lcd(a, b)
    print(ans)

if __name__ == '__main__':
    main()
