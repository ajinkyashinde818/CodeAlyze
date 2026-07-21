import math as mt
import numpy as np

string = input()
collect = []
word = ''
count = 0
n = len(string)
i = 0
for x in string:
    if x != 'x':
        word += x
        collect.append(count)
        if i == n-1:
            collect.append(0)
        count = 0
    elif i == n-1:
        count += 1
        collect.append(count)
    else:
        count += 1
    i += 1

nl = len(word) - 1
i = 0
while i < nl:
    if word[i] != word[nl]:
        print(-1)
        exit()
    i += 1
    nl -=  1
nl = len(collect) - 1
i = 0
out = 0
while i < nl:
    out += np.abs(collect[i] - collect[nl])
    i += 1
    nl -= 1
print(out)
