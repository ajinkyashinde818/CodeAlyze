def slove():
    import sys
    input = sys.stdin.readline
    a, b = list(map(str, str(input().rstrip('\n')).split()))
    if a > b:
        print(">")
    elif a < b:
        print("<")
    else:
        print("=")


if __name__ == '__main__':
    slove()
