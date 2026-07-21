from collections import Counter
s = input()
t = input()
s_cnt = sorted(Counter(s).most_common())
t_cnt = sorted(Counter(t).most_common())[::-1]
s_replaced = ""
t_replaced = ""
for k, v in s_cnt:
    s_replaced += k * v 
for k, v in t_cnt:
    t_replaced += k * v 

def judge(s, t):
    for i in range(min(len(s), len(t))):
        if ord(s[i]) > ord(t[i]):
            return False
        if ord(s[i]) < ord(t[i]):
            return True
    if len(s) < len(t):
        return True
    else:
        return False

if judge(s_replaced, t_replaced):
    print("Yes")
else:
    print("No")
