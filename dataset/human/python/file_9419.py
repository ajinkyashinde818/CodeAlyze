import collections


def main():
    N, K = list(map(int, input().split(' ')))
    A  = list(map(int, input().split(' ')))
    
    where_li = []
    pre = 0
    for i in range(N):
        where_li.append(A[pre])
        pre = A[pre]-1
    
    len_w = len(where_li)
    a = where_li.index(A[pre])
    # print(a)
    mod_s = len_w-a # ループにかかる歩数
    # print(where_li)
    if K<=len_w:
        print(where_li[K-1])
    else:
        nokori = K - len_w
        if nokori % mod_s==0:
            d = mod_s
        else:
            d = nokori % mod_s
        print(where_li[d-1+a])

main()
