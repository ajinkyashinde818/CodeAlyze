s = list(input())
t = list(input())
def judge(l1,l2): # l1 (= l2
    for e in l1:
        if e not in l2:
            return False
            break
        elif e  == l1[-1]:
            return True
if len(s) < len(t) and judge(s,t):
    print("Yes")
else:
    s_ord = [ord(e) for e in s]
    t_ord = [ord(e) for e in t]
    s_ord.sort()
    t_ord.sort()
    t_ord.reverse()
    for i in range(min(len(t_ord),len(s_ord))):
        if t_ord[i] > s_ord[i]:
            print("Yes")
            break
        elif i == min(len(t_ord),len(s_ord)) - 1:
            print("No")
