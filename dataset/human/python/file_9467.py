import sys 
def solve():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))

    p_bool = [False] * n
    ne_p = 1
    p_bool[ne_p-1] = True
    step = 0
    for i in range(n):
        ne_p = a[ne_p-1]
        step += 1
        if p_bool[ne_p-1]:
            break
        else:
            p_bool[ne_p-1] = True
        if step == k:
            print(ne_p)
            sys.exit()
    
    p_list = []
    sta = ne_p
    for i in range(n):
        ne_p = a[ne_p-1]
        step += 1
        p_list.append(ne_p)
        if ne_p == sta:
            break
        if step == k:
            print(ne_p)
            sys.exit()

    len_l = len(p_list)
    left = k-step
    left -= (left//len_l) * len_l
    print(p_list[left-1])
    # p_list = [1]
    # ne_p = a[0]
    # p_bool = [False] * n
    # p_bool[0] = True
    # check = False
    # step = 0
    # for _ in range(n):
    #     p_bool[ne_p-1] = True
    #     p_list.append(ne_p)
    #     step = 0
    #     if step == k:
    #         #print(ne_p)
    #         sys.exit()
    #     ne_p = a[ne_p-1]
    #     # if ne_p in p_list:
    #     #     ind = p_list.index(ne_p)
    #     #     break
    #     if p_bool[ne_p-1]:
    #         check = True
    #         break
        
    # #print(p_list)
    # #print(p_bool)
    # if check:
    #     ind = p_list.index(ne_p)
    # else:
    #     ind = 0
    # k = k - ind
    # #print(ind)
    # #print(k)
    # #print(p_list)
    # #print(k%(len(p_list)-ind))
    # print(p_list[ind + k%(len(p_list)-ind)])

solve()
