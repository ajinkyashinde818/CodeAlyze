def cont(ob,j):
    if (ob <= 0):
            return 0
    for i in range(len(j)):
        ob -= j[i]
        if (ob <= 0):
            return i+1
    return 9999
 
d,ob = map(int,input().split())
lst = []
point = []
kai = [[0 for i in range(ob//100)] for j in range(d)]
 
for i in range(d):
    lst =[]
    a = list(map(int,input().split()))
    for j in range(a[0]):
        lst.append((i+1)*100)
    lst[j] += a[1]
    point.append(lst)
 
 
for i in range(len(kai)):
    for j in range(len(kai[0])):
        if i == 0:
            kai[i][j] = cont((j+1)*100,point[i])
        else:
            if(sum(point[i])<(j+1)*100):
                a = kai[i-1][j]
                b = len(point[i]) + kai[i-1][j-sum(point[i])//100 ]
                if a>b:
                    kai[i][j] = b
                else:
                    kai[i][j] = a
            else:
                a = kai[i-1][j]
                b = cont((j+1)*100,point[i])
                if a>b:
                    kai[i][j] = b
                else:
                    kai[i][j] = a
        #print(kai)
 
#print(point)
print(kai[len(kai)-1][len(kai[0])-1])
