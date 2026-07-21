from collections import deque


reverse = False

string = deque(input().rstrip())
operate_times = int(input().rstrip())

for i in range(operate_times):
    row = input().rstrip()
    if row[0]=='1':
        if reverse:
            reverse = False
        else:
            reverse = True
    
    if row[0]=='2':
        row = row.split()
        head_or_tail = int(row[1])
        add_string = row[2]

        if reverse:
            if head_or_tail==1:
                string.append(add_string)
            else:
                string.appendleft(add_string)
        
        else:
            if head_or_tail==2:
                string.append(add_string)
            else:
                string.appendleft(add_string)


answer_string = ''
if reverse:
    for _ in range(len(string)):
        right = string.pop()
        answer_string+=right
    print(answer_string)
else:
    print(''.join(string))
