import sys
s=input()
t=input()
s_l=[]
t_l=[]

for i in range(len(s)):
    s_l.append(s[i])
    s_l.sort()
for i in range(len(t)):
    t_l.append(t[i])
    t_l.sort(reverse=True)


for i in range(min(len(s),len(t))):   
    
    if ord(s_l[i])>ord(t_l[i]):
        print("No")
        sys.exit()
    elif ord(s_l[i])==ord(t_l[i]):
        pass
    elif ord(s_l[i])<ord(t_l[i]):
        print("Yes")
        sys.exit()
    
if len(s)>=len(t):
    print("No")
else:
    print("Yes")
