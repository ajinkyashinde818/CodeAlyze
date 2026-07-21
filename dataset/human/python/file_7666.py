import sys 
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
S = readline().decode().rstrip()
Q = int(readline())
cnt = 0
start = ''
end = ''
for i in range(Q):
    A = list(map(str,readline().decode().split()))
    if A[0] == '1':
        cnt +=1
    else:
        if (cnt + int(A[1])) % 2:
            start += A[2]
        else:
            end += A[2]
ans = start + S + end
if cnt % 2 == 1:
    print(end[::-1] + S[::-1] + start)
else:
    print(start[::-1] + S + end)
