import string

alphabet = {}
n  = 0
for i in string.ascii_lowercase:
    alphabet[i] = n
    n += 1
    
s = list(input().rstrip())
t = list(input().rstrip())



for i in range(len(s)):
    s[i] = alphabet[s[i]]
    
for i in range(len(t)):
    t[i] = alphabet[t[i]]
    

s.sort()
t.sort(reverse=True)

if s < t:
    print('Yes')
else:
    print('No')
