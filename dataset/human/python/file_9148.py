def main():
    S = input()
    Si = S[::-1]
    a = ['maerd', 'remaerd', 'esare', 'resare']
    temp = str()
    cnt = 0
    for i in Si:
        temp += i
        if temp in a:
            cnt += len(temp)
            temp = str()
    print('YES' if cnt == len(S) else 'NO')

if __name__ == '__main__':
    main()
