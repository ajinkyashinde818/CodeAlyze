import copy
import sys
input = sys.stdin.readline
n,k = map(int, input().split())
data = []
bit_k = format(k, 'b')
len_k = len(bit_k)
for i in range(n):
    a, b = map(int, input().split())
    if a <= k:
        tmp = format(a, 'b')
        tmp = tmp.zfill(len_k)
        data.append([tmp,b])
def check_value(bit):
    res = 0
    for i in range(len(data)):
        flag = True
        dd = data[i][0]
        for j in range(len_k):
            if bit[j] == '0' and dd[j] == '1':
                flag = False
                break
        if flag:
            #print("tmp:{} bit{}".format(tmp, bit))
            res += data[i][1]
    return res
ans = check_value(bit_k)
tmp = []
for i in range(len_k):
    p = []
    if bit_k[i] == '1':
        p = tmp + ['0'] + ['1']*(len_k-1-i)
    else:
        tmp += bit_k[i]
        continue
    p = "".join(p)
    ans = max(ans, check_value(p))
    tmp += bit_k[i]
print(ans)
