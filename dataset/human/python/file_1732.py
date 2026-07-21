import sys
input_num = input().split()
N = int(input_num[0])
M = int(input_num[1])

AB = [input() for i in range(0, N + M)]
A = AB[0: N]
B = AB[N:]

diff = N - M
matches = []
for i in range(0, diff+1):
    l = 0
    while N - l > diff:
        index = A[i][l:].find(B[0])
        if index != -1 and i <= diff:
            matches.append((index, l, i))
        l += 1
if len(matches) == 0:
    print("No")
    sys.exit()
count_no = []
for m, l, i in matches:
    for a, b in zip(A[i:], B):
        if a[l:].find(b) != m:
            count_no.append(0)
            break
if len(count_no) == len(matches):
    print("No")
else:
    print("Yes")
