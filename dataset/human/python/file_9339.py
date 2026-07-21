n,k=[int(i) for i in input().split()]

a=[None]+[int(i) for i in input().split()]

circle=[1]
for i in range(n):
    circle.append(a[circle[-1]])

def get_head_double(circle):
    check=[0]*(n+1)
    for i in circle:
        check[i]+=1
    for i in circle:
        if check[i]>=2:
            ans=i
            break
    ans_list=[]
    while len(ans_list)<2:
        for i,j in enumerate(circle):
            if j==ans:
                ans_list.append(i)
    return ans_list

ans_list=get_head_double(circle)
circle_front=circle[:ans_list[0]]
circle_back=circle[ans_list[0]:ans_list[1]]

if len(circle_front)>k:
    print(circle_front[k])
else:
    k=k-len(circle_front)
    print(circle_back[k%len(circle_back)])
