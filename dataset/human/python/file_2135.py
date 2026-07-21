from collections import Counter
if __name__ == "__main__":
    n = int(input())
    s = list(input())
    cnt = Counter(s)
    ans = 1
    for i in cnt.values():
        ans *= int(i)+1
        ans = ans%(10**9+7)
    print(ans%(10**9+7)-1)
