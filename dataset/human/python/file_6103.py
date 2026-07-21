def input_int_list():
    return [int(x) for x in input().split()]

N = int(input())
A = input_int_list()
B = input_int_list()
C = input_int_list()

satisfaction = B[A[0] - 1]
last_dish = A[0]
for a in A[1:]:
    satisfaction += B[a - 1]
    if a == last_dish + 1:
        satisfaction += C[last_dish - 1]

    last_dish = a


print(satisfaction)
