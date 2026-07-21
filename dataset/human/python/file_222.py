import math

N = int(input())
k = int(math.sqrt(N * 2)) + 1
if k * (k-1) == N*2:
    print("Yes")
    print(str(k))
    print_list = []
    used = 0
    for i in range(k):
        if i == 0:
            single_list = [str(k-1)] + [str(a+1) for a in range(k-1)]
            print(" ".join(single_list))
            print_list.append(single_list)
            used = k-1
        else:
            single_list = [str(k-1)] + [a[i] for j, a in enumerate(print_list)] + [str(a + used + 1) for a in range(k-1-i)]
            print(" ".join(single_list))
            print_list.append(single_list)
            used += k-1-i
else:
    print("No")
