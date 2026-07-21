from collections import deque

S = deque(input())
Q = int(input())
reverse_mode = False #反転毎に全体を反転しているとTLEする
reversed_count = 0
 
for i in range(Q):
    query = [str(e) for e in input().split()]
    if len(query)==1:
        reversed_count += 1
        #反転のモードを切り替える
        if reverse_mode == False:
            reverse_mode = True
        elif reverse_mode == True:
            reverse_mode = False
    
    else:
        if reverse_mode == False:
            if query[1]=="1":
            #先頭に追加
                S.appendleft(query[2])
            else:
            #末尾に追加
                S.append(query[2])
        elif reverse_mode == True:
            if query[1]=="1":
            #反転した先頭に追加＝末尾に追加
                S.append(query[2])
            else:
            #反転した末尾に追加＝先頭に追加
                S.appendleft(query[2])

#終了時に反転回数に応じて逆転orそのままにする
if reversed_count%2 != 0:
    S.reverse()
    
#print(S)
print(''.join(map(str,S)))
