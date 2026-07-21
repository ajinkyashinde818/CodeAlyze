from sys import stdin

N = int(stdin.readline().rstrip())
data = stdin.readline().rstrip().split()

abs_sum = 0
negative_elements = []
zero_exist = False

for number in data:
    num = int(number)
    abs_sum += abs(num)
    if num == 0:
        zero_exist = True
    elif num < 0:
        negative_elements.append(int(num))

if len(negative_elements) % 2 == 0 or zero_exist:
    print(abs_sum)
else:
    print(abs_sum - (2 * min([abs(int(x)) for x in data])))
