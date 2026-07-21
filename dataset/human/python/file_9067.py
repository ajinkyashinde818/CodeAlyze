def main():
    S = input()
    D = ['dream', 'dreamer', 'erase', 'eraser']
    D = [d[::-1] for d in D]
    tmp = ''
    for s in S[::-1]:
        tmp = ''.join([tmp, s])
        if tmp in D:
            tmp = ''
        if len(tmp) > 7:
            print('NO')
            exit()
    if tmp == '':
        print('YES')
    else:
        print('NO')

if __name__ == '__main__':
    main()
