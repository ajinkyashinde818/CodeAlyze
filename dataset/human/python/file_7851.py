from sys import stdin

n, k, s = map(int, stdin.readline().rstrip().split())
flag = 0

for i in range(n):
    if flag < k:
        print(s)
        flag += 1
    else:
        if s == 10 ^ 9:
            print(s-1)
        else:
            if s == 1:
                print(2)
            else:
                print(s-1)
