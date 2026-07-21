import collections

N = int(input())
S = list(input())

lst = [0] * 26
for i in range(N):
    lst[ord(S[i]) - 97] += 1

for i in range(len(lst)):
    if i == 0:
        pass
    else:
        lst[i] += lst[i] * sum(lst[:i])

ans = sum(lst)
    
print(ans % (10**9 + 7))
