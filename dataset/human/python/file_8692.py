import numpy as np
K, N = map(int, input().split())
x_list = list(map(int, input().split()))

sub_x_list = x_list.copy()[1:]
sub_x_list.append(K + x_list[0])

for i in range(N):
    sub_x_list[i] -= x_list[i]
    
max_i = max(sub_x_list)
print(K - max_i)
