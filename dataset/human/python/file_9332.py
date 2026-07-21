def mapint_inp():
    return map(int, input().split())

def intinp():
    return int(input())

n, k = mapint_inp()
a = list(mapint_inp())

s = []
order_of_teleport = [-1]*(n+1)
cycle = 1
l = 0
v = 1
while order_of_teleport[v] == -1:
    order_of_teleport[v] = len(s)
    s.append(v)
    v = a[v-1]
c = len(s) - order_of_teleport[v] # サイクルの長さ
l = order_of_teleport[v] # 例外部分の長さ

if k < l: print(s[k])
else:
    k -= l
    k %= c
    print(s[l+k])
