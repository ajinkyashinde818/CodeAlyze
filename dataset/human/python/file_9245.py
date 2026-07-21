import sys

read = sys.stdin.read
readline = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 8)
INF = float('inf')
MOD = 10 ** 9 + 7


def main():
    S = input()
    end = len(S)
    while end>0:
        if S[end-5:end]=='dream' or S[end-5:end]=='erase':
            end -= 5
        elif S[end-7:end]=='dreamer':
            end -= 7
        elif  S[end-6:end]=='eraser':
            end -= 6
        else:
            print('NO')
            break
    else:
        print('YES')



if __name__ == '__main__':
    main()
