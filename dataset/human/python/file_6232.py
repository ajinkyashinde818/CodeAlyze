"""
N,K = list(map(int,input().split()))
A = list(map(int,input().split()))

A.sort()


def bisect(i,V):
    l = i+1
    r = N-1
    if A[i]*A[r]<V:
        return r-i
    if [i]*A[l]>=V:
        return 0
    while r-l>1:
        if A[i]*A[(l+r)//2]<V:
            l = (l+r)//2
        else:
            r = (l+r)//2
    return r

"""


N = input()
N = N[::-1]

count = 0
flag = False
for i in range(len(N)):
    s = int(N[i])
    if not flag:

        if s>5:
            count += 10-s
            flag = True
        elif s==5:
            count += 5
            if i<len(N)-1:
                t = int(N[i+1])
                if t>=5:
                    flag=True
        else:
            count += s
            flag=False
    else:

        if s+1>=10:
            #A.append("0")
            #B.append("0")
            flag = True
        elif s+1>5:
            count += 10-s-1
            #A.append("0")
            #B.append(str(10-s-1))
            flag = True
        elif s+1==5:
            count += 5
            if i<len(N)-1:
                t = int(N[i+1])
                if t>=5:
                    flag=True
                else:
                    flag=False
            else:
                flag=False

        else:
            count += s+1

            flag=False

if flag:
    count+=1

print(count)
