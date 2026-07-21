import math

n = int(input())

tmpn = n

dic = dict([])

for i in range(2, int(math.sqrt(n))+1):
    if tmpn%i == 0 and tmpn/i > 0:
        divided = True
        while divided:
            tmpn = tmpn/i
            if i in dic.keys():
                dic[i] += 1
            else:
                dic[i] = 1
            if tmpn != 1 and tmpn not in dic.keys():
                dic[int(tmpn)] = 1
            if tmpn%i == 0 and tmpn/i > 0:
                divided = True
            else:
                divided = False

keyls = list(dic.keys())

# print (keyls)

for key1 in keyls:
    for key2 in keyls:
        if key1 < key2:
            if key2%key1 == 0 and key2/key1 > 0:
                if key2 in dic.keys():
                    dic.pop(key2)

if len(dic.keys()) == 0 and n != 1:
    ans = 1
else:
    ans = 0
    for key in dic.keys():
        num = dic[key]
        i = 1
        while num > 0:
            num -= i
            if num >= 0:
                ans += 1
            i += 1

print(ans)
# print(dic)
