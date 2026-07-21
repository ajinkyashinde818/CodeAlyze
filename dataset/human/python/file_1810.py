def srch_all(ptn, str):
    index = []
    i = -1
    while True:
        i = str.find(ptn, i + 1)
        if i > -1:
            index.append(i)
        else:
            break
    return index

def judge(i, jlist, len):
    for l in jlist:
        k = 1
        while k < M:
            try:
                if n[i + 1][l:l + len] == m[k]:
                    pass
                else:
                    return 'No'
            except:
                return 'No'
            i += 1
            k += 1
        else:
            return 'Yes'

N, M = map(int, input().split())
i = 0
n = []
while i < N:
    n.append(input())
    i += 1

i = 0
m = []
while i < M:
    m.append(input())
    i += 1

i = 0
r = 'No'
while i < N:
    result = srch_all(m[0], n[i])
    if len(result) > 0:
        r = judge(i, result, len(m[0]))
        if r == 'Yes':
            break
    i += 1
print(r)
