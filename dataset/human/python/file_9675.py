import sys
N, K = map(int, input().split())
A = list(map(int, input().split()))

now = 1
temp_l = [0]*N
temp_count = [-1]*N
temp_count[0] = 0
for i in range(N):
    pre = now
    now = A[pre-1]
    if temp_l[now-1] == 1:
        end = now
        temp = i+1
        break
    else:
        temp_l[now-1] = 1
        temp_count[now-1] = i+1

s_index = temp_count[end-1]
repeat = temp - s_index
if K <= s_index:
    print(temp_count.index(K)+1)
else:
    K -= s_index
    K = K % repeat
    print(temp_count.index(K+s_index)+1)
