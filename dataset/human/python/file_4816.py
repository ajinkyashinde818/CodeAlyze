def slove():
    import sys
    input = sys.stdin.readline
    s = list(str(input().rstrip('\n')))
    t = list(str(input().rstrip('\n')))
    s.sort()
    t.sort(reverse=True)
    print("Yes" if s < t else "No")


if __name__ == '__main__':
    slove()
