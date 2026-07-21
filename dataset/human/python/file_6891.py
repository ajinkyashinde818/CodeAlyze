import collections

S = input()

Q = int(input())

list1 = collections.deque()
list2 = []
flag = 1

for _ in range(Q):
    op = input().split()
    if len(op) == 1:
        flag *= -1
    else:
        if flag == 1:
            if op[1] == '1':
                list1.appendleft(op[2])
            else:
                list2.append(op[2])
        else:
            if op[1] == '1':
                list2.append(op[2])
            else:
                list1.appendleft(op[2])

if flag == 1:
    print("".join(list1) + S + "".join(list2))
else:
    print(("".join(list1) + S + "".join(list2))[::-1])
