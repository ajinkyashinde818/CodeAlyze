from collections import deque

def string_formation(s, q_list):
    ans = deque()
    for x in s:
        ans.append(x)
    count = 0
    for query in q_list:
        if query[0] == '1':
            count += 1
        else:
            if count % 2 == 0:
                if query[1] == '1':
                    ans.appendleft(query[2])
                else:
                    ans.append(query[2])
            else:
                if query[1] == '1':
                    ans.append(query[2])
                else:
                    ans.appendleft(query[2])
    if count % 2 == 1:
        ans.reverse()
    print(''.join(ans))

s = input()
q = int(input())
q_list = []
for _ in range(q):
    tmp = input().split()
    q_list.append(tmp)

string_formation(s, q_list)
