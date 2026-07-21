from collections import Counter
from sys import stdin

def main():
    N = int(input())
    S = input()

    cnt = Counter(S)
    ans = 1
    for i in cnt.values():
        ans *= i + 1
        ans %= 1000000007
    print(ans - 1)

input = lambda: stdin.readline().rstrip()
main()
