import collections

S = input()
Q = int(input())

Query = [input() for i in range(Q)]

deq = collections.deque(S)

flg = False
for q in Query:
    query = q.split(' ')
    if query[0]=='1':
        flg = not flg

    elif query[0] == '2':
        if query[1] == '1':
            if flg == True:
                deq.append(query[2])
            else:
                deq.appendleft(query[2])
        else:
            if flg==True:
               deq.appendleft(query[2])
            else:
               deq.append(query[2]) 
if flg == True:
    deq.reverse()        
print(''.join(deq))
