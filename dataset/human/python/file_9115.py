def slove():
    import sys
    input = sys.stdin.readline
    s = str(input().rstrip('\n'))
    s = s.replace("eraser", "").replace("erase", "").replace("dreamer", "").replace("dream", "")
    print("YES" if s == "" else "NO")


if __name__ == '__main__':
    slove()
