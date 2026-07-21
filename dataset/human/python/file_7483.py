from collections import deque
S=input()
Q=int(input())
words=[]
for a in range(Q):
    A=input().split()
    words.append(A)
T=[a for a in S]
answers=deque(T)
number=0
for a in words:
    if a[0]=='1':
        number+=1
    else:
        if number%2==0:
            if a[1]=='1':
                answers.appendleft(a[2])
            else:
                answers.append(a[2])
        else:
            if a[1]=='1':
                answers.append(a[2])
            else:
                answers.appendleft(a[2])
if number%2==0:
    kotae=list(answers)
    moji=''
    for a in kotae:
        moji+=a
    print(moji)
else:
    kotae = list(answers)
    kotae.reverse()
    moji = ''
    for a in kotae:
        moji += a
    print(moji)
