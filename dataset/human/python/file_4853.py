import sys
s= list(input())
t= list(input())
s.sort()
t.sort()

count = 0
for i in range(min(len(t),len(s))):
    if t[i] == s[i]:
        count += 1
if count == min(len(t),len(s)):
    if len(s)<len(t):
        print("Yes")
    else:
        print("No")
        

elif s[0]<t[len(t)-1]:

    print("Yes")


else:
    print("No")
