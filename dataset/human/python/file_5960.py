n = int(input())
data = []
for i in range(3):
    data.append(list((map(lambda x: int(x), input().split()))))


content_plus = 0

for i in range(n):
    if i == 0:
        pass
    else:
        if data[0][i-1]+1 == data[0][i]:
            content_plus = content_plus + data[2][data[0][i-1]-1]


def sum(list):
    lsum = 0
    for i in range(len(list)):
        lsum = lsum+list[i]
    return lsum

print(sum(data[1])+content_plus)
