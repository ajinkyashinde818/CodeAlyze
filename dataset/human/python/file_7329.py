from collections import deque

ans = deque()
center_ans_1 = input()
center_ans = list(center_ans_1)
for i in range(len(center_ans)):
    a = center_ans[i]
    ans.append(a)

q = int(input())
list_data = [ list(map(str,input().split(" "))) for i in range(q)]
#print(list_data)
re = 0
for i in range(q):
    list_a = list_data[i]
    #print(list_a)
    if list_a[0] == "1":
        re += 1
    elif list_a[0] == "2":
        if list_a[1] == "1":
            if re % 2 == 0:
                ans.appendleft(list_a[2])
            elif re % 2 == 1:
                ans.append(list_a[2])
        elif list_a[1] == "2":
            if re % 2 == 0:
                ans.append(list_a[2])
            elif re % 2 == 1:
                ans.appendleft(list_a[2])

if re % 2 == 1:
    ans.reverse()

print("".join(ans))
