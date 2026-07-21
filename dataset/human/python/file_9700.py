import sys
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
N,K = LI()
A = [0]+LI()
town = 1
route = [1]
town_set = set([1])
while 1:
    town = A[town]
    route.append(town)
    if town in town_set:
        break
    town_set.add(town)
loopstart_index = route.index(route[-1])
loop_len = (len(route)-1)-loopstart_index
ans_index = loopstart_index+(K-loopstart_index)%(loop_len)
if K<loopstart_index:
    ans_index = K
print(route[ans_index])
