il1 = input().split()
il2 = input().split()

K = int(il1[0])
N = int(il1[1])
A = [int(i) for i in il2]

import copy

fixed_A = copy.copy(A)

for i in A:
    fixed_A.append(i+K)

ans_list =[]

for i in range(len(A)):
    # print("i = "+str(i))
    ans_list.append(fixed_A[i+N-1] - A[i])

ans_list.sort()

print(ans_list[0])
