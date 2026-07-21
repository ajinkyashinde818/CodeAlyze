import sys

input = sys.stdin.readline
n = int(input())
a_list = list(map(int, input().split()))
new_list = []
cnt = 0
for a in a_list:
    if a < 0:
        cnt += 1
        a = -a
    new_list.append(a)
if cnt%2 == 0:
    print(sum(new_list))
else:
    print(sum(new_list)-min(new_list)*2)
