import collections
N=int(input())
S=list(input())
l=[]
c=collections.Counter(S)
num=1
p=10**9+7
values=list(c.values())	#aのCollectionのvalue値のリスト(n_1こ、n_2こ…)
key=list(c.keys())	#先のvalue値に相当する要素のリスト(要素1,要素2,…)
for i in range(len(key)):
    l.append([key[i],values[i]])#lは[要素i,n_i]の情報を詰めたmatrix
#print(l)
for i in range(len(l)):
    num=num*(l[i][1]+1)
print((num-1)%p)
