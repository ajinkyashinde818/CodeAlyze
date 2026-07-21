url = "https://atcoder.jp//contests/abc049/tasks/arc065_a"

def main():
    words = ['dream','dreamer', 'erase', 'eraser']
    s = input()
    rs = s[::-1]
    while rs != '':
        tmp = len(rs)
        for word in words:
            if len(word) > len(rs):
                continue
            rs = rs[0:len(word)].replace(word[::-1], '') + rs[len(word):]
        if tmp == len(rs):
            print('NO')
            exit()
    print('YES')

if __name__ == '__main__':
    main()
