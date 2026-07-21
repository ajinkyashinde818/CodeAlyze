def func(N, A_i, B_i, C_i):
    stf = 0
    for i in range(N):
        stf += B_i[i]
        if i >= 1 and (A_i[i] == A_i[i-1] + 1):
            stf += C_i[A_i[i-1]-1]
    return stf

N = int(input())
A_i = list(map(int, input().split(" ")))
B_i = list(map(int, input().split(" ")))
C_i = list(map(int, input().split(" ")))
print(func(N, A_i, B_i, C_i))
