from collections import deque
s=str(input())

front = ""
back = ""#前と後ろに分ける最後につなげてリバース

now_swap = 0
q=int(input())
for i in range(q):
    a = input().strip()
    a = list(a)
    
    if a[0] == "1":
        if now_swap == 0:
           now_swap = 1
        else: #now_step == 1:
            now_swap = 0
    else:
        if now_swap == 1:
            if a[2] == "1":
               # print("back")
                back+=a[4]

            else: #a[1]==2:
               ## print("f 2")
                front = a[4] + front

        else: #now_step == 0:
            if a[2] == "1":
                front = a[4] + front

            else: #a[1]==2:
                #print("hj")
                back+=a[4]
ans= front + s + back
#print(front,a,back)
if now_swap == 1:#合計数が奇数なら
    
    print(ans[::-1])
else:
    print(ans)
