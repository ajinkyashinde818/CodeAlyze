import sys,math,collections,itertools
input = sys.stdin.readline

N,K=list(map(int,input().split()))
A =[0]+list(map(int,input().split()))
town = 1
town_list = [1]
towntown = [0]*(N+1)
towntown[1]=1
count = 0
while True:
    town = A[town]
    count +=1
    if count == K:
        print(town)
        exit()
    if towntown[town] == 0:
        town_list.append(town)
        towntown[town] =1
    else:
        roop_town_num = town
        break
    
l_ini_index = town_list.index(roop_town_num)
len_roop = len(town_list)-l_ini_index 

if K <= l_ini_index:
    print(town_list[K])
else:
    print(town_list[((K-l_ini_index)%len_roop+l_ini_index)])
