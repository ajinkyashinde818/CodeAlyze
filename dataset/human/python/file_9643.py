from collections import defaultdict

N,K=list(map(int,input().split()))
a_list=list(map(int,input().split()))
alr = defaultdict(int)
alr[1] = 1
counter = 2
next = a_list[0]
base_roop = 0
last_index = 1
while True:
    if alr[next] != 0:
        base_roop = counter-1
        break
    else:
        alr[next] = counter
        last_index = next
        next = a_list[next-1]
        counter += 1

# nextから何回でlastに帰ってくるか
alr_next = defaultdict(int)
next_roop = 0
while True:
    if a_list[next-1]==last_index:
        next_roop += 1
        alr_next[next] = next_roop
        break
    else:
        next_roop+=1
        alr_next[next] = next_roop
        next = a_list[next-1]
next_roop+=1

if K<base_roop:
    ans = K%base_roop+1
    for k,v in alr.items():
        if v==ans:
            print(k)
            exit()
else:
    K-=base_roop
    ans = K%next_roop+1
    for k,v in alr_next.items():
        if v==ans:
            print(k)
            exit()
    print(last_index)
