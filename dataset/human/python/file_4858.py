import sys
from collections import Counter

s = input()
t = input()
s_list = []
t_list = []

for i in s:
    s_list.append(ord(i))

for i in t:
    t_list.append(ord(i))

s_list.sort()
t_list.sort(reverse=True)

for i in range(min(len(s_list), len(t_list))):
    if t_list[i] > s_list[i]:
        print('Yes')
        sys.exit()

if set(s_list) == set(t_list) and len(s_list) < len(t_list):
    print('Yes')
else:
    print('No')
