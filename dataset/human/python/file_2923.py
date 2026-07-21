N = int(input())
number = N
List = [0 for i in range(1000000)]
answer = 0

def cul(x):
    number = 1
    while x >= (number+2)*(number + 1)//2:
        number += 1
    return number

i = 2
while number > 1:
    while number % i == 0:
        number //= i
        List[i] += 1
    i +=1

    if i == 1000001:
        answer = 1
        break

for x in List:
    if x == 0:
        continue
    else:
        answer += cul(x)

print(answer)
