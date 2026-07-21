def ans(n, k, list_a):
    i=0
    dic={}
    dic[1]=1
    list_memo=[1]
    while i<k:
        next = list_a[list_memo[i]-1]
        if next not in dic:
            list_memo.append(next)
            dic[next]=1
        else:
            num=list_memo.index(next)
            len_list=len(list_memo)
            i+=1
            x = len_list-num
            k=k-num
            
            #print(k)
            k%=x
            return list_memo[num+k]
            #return 50000
            
        i+=1
    return list_memo[i]
        




n, k = (int(x) for x in input().split())
list_a = list(map(int, input().split()))
print(ans(n, k, list_a))
