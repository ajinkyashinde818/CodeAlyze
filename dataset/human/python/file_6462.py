import sys
def I(): return int(sys.stdin.readline())
def LI(): return [int(x) for x in sys.stdin.readline().split()]

def main():
    N = I()
    if N%2==1:
        print(0)
        return

    ans = 0
    ans += N//10
    q = 50
    while(N//q>0):
        ans += N//q
        q *= 5

    print(ans)

if __name__ == "__main__":
    main()
