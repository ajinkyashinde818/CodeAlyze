from collections import Counter

if __name__ == '__main__':
    n = int(input())
    s = list(input())
    s = Counter(s)
    s = s.most_common()
    ans = 1

    for k, v in s:
        if v > 1:
            ans *= v + 1
        else:
            ans *= 2
        ans %= (10 ** 9 + 7)

    print(ans - 1)
