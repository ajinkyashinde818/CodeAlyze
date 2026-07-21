import sys

s=input()
t=input()
s_list=[]
t_list=[]
for i in range(len(s)):
	s_list.append(s[i])
for j in range(len(t)):
	t_list.append(t[j])
s_list.sort()
t_list.sort(reverse=True)
print("Yes" if s_list<t_list else "No")
