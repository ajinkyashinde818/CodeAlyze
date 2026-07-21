import sys

input = sys.stdin.readline

S = input().strip()
Q = int(input())
Query = []
for _ in range(Q):
    Query.append(input().strip())

rev = S[::-1]
left = ""
right = ""
count = 0
flag = 'Normal'
for value in Query:
    if value == '1':
        count += 1
    if count % 2 == 1:
        flag = 'Reverse'
    else:
        flag = 'Normal'
    if value != "1":
        if flag == 'Normal':
            if value[2] == '1':
                left += value[4]
            elif value[2] == '2':
                right += value[4]
        elif flag == 'Reverse':
            if value[2] == '1':
                right += value[4]
            elif value[2] == '2':
                left += value[4]

if flag == 'Normal':
    ans = left[::-1] + S + right
elif flag == 'Reverse':
    ans = right[::-1] + rev + left
print(ans)
