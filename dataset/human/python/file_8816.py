def input_int_list():
    return [int(thing) for thing in input().split(" ")]

K,N=input_int_list()
A_list=sorted(input_int_list())
A_list=A_list+[A_list[0]+K]
max_dis=0
for i in range(N):
    max_dis=max(max_dis,A_list[i+1]-A_list[i])
print(K-max_dis)
