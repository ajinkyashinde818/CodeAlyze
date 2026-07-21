import sys

s = input()
t = input()


lists = [_ for _ in s]
listt = [_ for _ in t]



for i in range(0,len(s)):
    for j in range(0, len(t)):
        if s[i]<t[j]:
            print('Yes')
            sys.exit()

lists.sort()
listt.sort()

if len(lists)<len(listt) and lists[0:len(lists)]==listt[0:len(lists)]:
    print('Yes')
    sys.exit()

print('No')
