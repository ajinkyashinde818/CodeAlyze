import itertools
num2alpha = lambda c: chr(c+64)
alpha2num = lambda c: ord(c) - ord('A') + 1

N = int(input())
S = list(input())
S_unique = list(set(S))
S_kind = len(S_unique)

count_list = [0] * 27

for i in range(1,27):
    tmp = num2alpha(i).lower()
    count = S.count(tmp)
    count_list[i] = count % 1000000007

count_list_new = []
for i in range(len(count_list)):
    if count_list[i] != 0:
        count_list_new.append(count_list[i]+1)

#print(count_list_new)
ans = 1
for i in range(len(count_list_new)):
    ans *= count_list_new[i] % 1000000007

ans -= 1
print(ans % 1000000007)
