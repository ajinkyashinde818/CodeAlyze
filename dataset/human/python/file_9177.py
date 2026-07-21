def main():
    Ss = input()
    S = list(Ss)
    now = 0
    T = ''
    Sr = []
    for i in range(1,len(S)+1):
        Sr.append(S[-i])
    ans = []
    while True:
        tmp5 = Sr[now:now+5]
        tmp6 = Sr[now:now+6]
        tmp7 = Sr[now:now+7]
        if tmp5[0] == 'e' and tmp5 == ['e','s','a','r','e']:
            ans.append('erase')
            now += 5
        elif tmp5[0] == 'm' and tmp5 == ['m','a','e','r','d']:
            ans.append('dream')
            now += 5
        elif tmp6[0] == 'r' and tmp6 == ['r','e','s','a','r','e']:
            ans.append('eraser')
            now += 6
        elif tmp7[0] == 'r' and tmp7 == ['r','e','m','a','e','r','d']:
            ans.append('dreamer')
            now += 7
        else:
            print('NO')
            
            return

        if now >= len(S):
            break
    for i in range(1,len(ans)+1):
        T += ans[-i]
    if Ss == T:
        print('YES')
    else:
        print('NO')

if __name__ == '__main__':
    main()
