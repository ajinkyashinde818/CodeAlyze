s1 = str(input())
s = s1.split(' ')
k = int(s[0])
n = int(s[1])
l=[]

ls = str(input())
l = ls.split(' ')
l1 = [int(x) for x in l]

def dist(a,b,k):
    if(b>a):
        return (k-b)+a
    else:
        return a-b

l4=[]
for i in range(len(l1)):
    l4.append(k - dist(l1[i],l1[i-1],k))
        
    
print(min(l4))
