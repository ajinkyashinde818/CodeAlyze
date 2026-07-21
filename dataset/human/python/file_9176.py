def resolve():
    S = list(input())
    S.reverse()
    substr = ''
    p = ['dream', 'dreamer', 'erase', 'eraser']
    for i in S:
        substr = i + substr
        if substr in p:
            substr = ''
    ans = 'YES' if substr == '' else 'NO'
    print(ans)


if __name__ == "__main__":
    resolve()
