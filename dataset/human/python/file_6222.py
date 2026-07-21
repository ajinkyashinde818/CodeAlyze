import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
s = readline().rstrip().decode('utf-8')

s = "0"+s

lst1 = []

for i in range(len(s)):
    lst1.append(int(s[i]))

n = len(lst1)-1

res = 0

for i in range(n,-1,-1):
    if lst1[i] <= 4: #自分で払ったほうが良い
        res += lst1[i]
    elif lst1[i] == 5: #5の場合、その上の桁によって話が変わってくる
        if lst1[i-1] >= 5: #どうせ次の桁で多くなるなら
            res += 5 #おつりでもらって
            lst1[i-1] += 1 #次の桁を1枚多く払う
        else: #そうでないなら、素直にその桁は5枚払う。
            res += 5
    else: #お釣りをもらったほうが良い
        res += 10-lst1[i]
        lst1[i-1] += 1 #一個上の桁で払う金が一枚多くなる
print(res)
