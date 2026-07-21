import sys
input = sys.stdin.readline

def main():
    S = input()[:-1]
    Q = int(input())
    li = [[] for _ in range(2)]
    now = 0
    for _ in range(Q):
        x = input()
        if(x[0] == '2'):
            if(x[2]=='1'):
                li[1-now].append(x[4])
            else:
                li[now].append(x[4])
        else:
            now = 1-now

    s = ''.join(li[1-now][::-1]) + S[::-(now*2-1)] + ''.join(li[now])
    print(s)

if __name__ == '__main__':
    main()
