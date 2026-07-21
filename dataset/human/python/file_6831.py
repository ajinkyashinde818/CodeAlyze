from collections import deque

s = input()
q = int(input())

query_list = []
for _ in range(q):
    query_list += [input()]

deq = deque(s)
true_position = True

for i in range(q):
    if len(query_list[i])==1:
        true_position = not true_position
        # print(s)
    else:
        if query_list[i][2]=="1":
            if true_position:
                deq.appendleft(query_list[i][4])
            else:
                deq.append(query_list[i][4])
        elif query_list[i][2]=="2":
            if true_position:
                deq.append(query_list[i][4])
            else:
                deq.appendleft(query_list[i][4])

if true_position:
    ans = "".join(deq)
else:
    deq.reverse()
    ans = "".join(deq)

print(ans)
