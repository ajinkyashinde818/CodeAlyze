from sys import stdin
input = stdin.readline

s = input().rstrip()
q = int(input())

isRev = False

head = ''

for i in range(q):
    query = list(input().split())
    if len(query) == 1:
        isRev = not isRev
    else:
        if isRev and query[1] == '1':
            s = s + query[2]
        elif query[1] == '1':
            head = head + query[2]
        elif isRev and query[1] == '2':
            head = head + query[2]
        elif query[1] == '2':
            s = s + query[2]
            
if isRev:
    s = s[::-1] + head
else:
    s = head[::-1] + s
        
print(s)
