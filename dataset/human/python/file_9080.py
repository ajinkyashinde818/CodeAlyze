def solve():
    S = input()
    idx = len(S)
    while idx-5 >= 0:
        if S[idx-5:idx] in ["dream","erase"]:
            idx -= 5
        elif idx-6 >= 0 and S[idx-6:idx] == "eraser":
            idx -= 6
        elif idx-7 >=0 and S[idx-7:idx] == "dreamer":
            idx -= 7
        else:
            print('NO')
            return
    else:
        if idx == 0:
            print('YES')
        else:
            print('NO')

if __name__ == '__main__':
    solve()
