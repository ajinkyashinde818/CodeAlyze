def hondan(w,m):
    m_sum = b_lis[0]
    num = 0
    if w < max(b_lis):
        return False
    else:
        for i in range(len(b_lis) - 1):
            m_sum += b_lis[i + 1]
            if m_sum > w:

                m_sum = b_lis[i + 1]
                num += 1

        if num < m:
            return True
        else:
            return False
        
def nibutan(f_id,e_id,m):
    
    
    m_id = int((f_id + e_id) / 2)
    m_bo = hondan(m_id,m)


    if (f_id > e_id):
        return m_id + 1
    else:
        if m_bo:
            return(nibutan(f_id,m_id -1,m))
        elif not m_bo:
            return(nibutan(m_id + 1,e_id,m))
        else:
            return m_id + 1



while True:
    global w_lis
    b_lis = []
    w_lis = []
    dan_num = [0]

    m,n = map(int,input().split())
    if m == n == 0:
        break
    for i in range(n):
        num = int(input())
        b_lis.append(num)
    s_num = int(sum(b_lis) /m)

    print(nibutan(s_num,1500000,m) )
