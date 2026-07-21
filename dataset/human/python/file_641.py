import sys
def input(): return sys.stdin.readline().rstrip()

def main():
    _ = int(input())
    A = list(map(int, input().split()))
    A_abs = [abs(a) for a in A]
    mc = sum([1 for a in A  if a < 0])

    ans = sum(A_abs)
    if mc % 2 != 0:
        ans -= min(A_abs) * 2
    print(ans)

if __name__ == '__main__':
    main()
