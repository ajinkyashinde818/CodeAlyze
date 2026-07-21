def m_i(l):
    stack = 1
    ans = 0
    l = list(l)
    for i in l :
        if i == 'm' :
            ans += stack * 1000
            stack = 1
        elif i == 'c' :
            ans += stack * 100
            stack = 1
        elif i == 'x' :
            ans += stack * 10
            stack = 1
        elif i == 'i' :
            ans += stack
            stack = 1
        else :
            stack = int(i)
    return ans
    
def i_m(l):
    ans = []
    a = l // 1000
    if a == 1 :
        ans.append('m')
    elif a != 0 :
        ans.append(str(a))
        ans.append('m')
    l -= a * 1000
    a = l // 100
    if a == 1 :
        ans.append('c')
    elif a != 0 :
        ans.append(str(a))
        ans.append('c')
    l -= a * 100
    a = l // 10
    if a == 1 :
        ans.append('x')
    elif a != 0 :
        ans.append(str(a))
        ans.append('x')
    a = l - a * 10
    if a == 1 :
        ans.append('i')
    elif a != 0 :
        ans.append(str(a))
        ans.append('i')
    ans = ''.join(ans)
    return ans

n = int(input())
for i in range(n) :
    a, b = input().split()
    ans = m_i(a) + m_i(b)
    print(i_m(ans))
