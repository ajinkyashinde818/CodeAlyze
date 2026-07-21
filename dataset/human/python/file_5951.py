import sys
n = int(input())
a_ls = [int(i) for i in sys.stdin.readline().split()]
b_ls = [int(i) for i in sys.stdin.readline().split()]
c_ls = [int(i) for i in sys.stdin.readline().split()]
cnt = 0
for i in range(n-1):
    if a_ls[i+1] - a_ls[i] == 1:
        cnt += c_ls[a_ls[i]-1]
cnt += sum(b_ls)
print(cnt)
