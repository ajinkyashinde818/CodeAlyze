s = input()
s_rev = s[::-1]
T_list = ['maerd', 'remaerd', 'esare', 'resare']
 
def mojicut(s, r):
    n = s.replace(r, "", 1)
    return n
 
 
while len(s_rev) > 0:
    s_len = len(s_rev)
    for i in T_list:
        if s_rev.startswith(i):
            s_rev = mojicut(s_rev, i)
            break
    if len(s_rev) == s_len:
        break
 
if len(s_rev) > 0:
    print("NO")
else:
    print("YES")
