import sys
input = sys.stdin.readline
N = int(input())
A_array = list(map(int, input().split()))
B_array = list(map(int, input().split()))
C_array = list(map(int, input().split()))
D_array = []
tmp = A_array[0]
for i in range(1,len(A_array)):
    if tmp + 1 == A_array[i]:
        D_array.append(C_array[tmp-1])
    tmp = A_array[i]

print(sum(B_array)+sum(D_array))
