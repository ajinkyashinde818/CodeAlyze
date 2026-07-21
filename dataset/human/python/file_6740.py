def main():
    S = input()
    Q = int(input())
    queries = [input() for _ in range(Q)]

    reverse = False
    front = ""

    for e in queries:
        if e[0] == '1':
            reverse = not reverse
        else:
            T, F, C = e.split()
            if F == '2': F = True
            else: F = False

            if reverse ^ F:
                # 末尾に追加
                S += C
            else:
                # continue
                # 先頭に追加，ここの計算がボトルネック
                front += C
        # print(S)

    if reverse:
        S = S[::-1]
        S = S + front
    else:
        S = front[::-1] + S

    print(S)
    

if __name__ == '__main__':
    main()
