import sys
s = input()
s = s[::-1]
A = ['dreamer','dream','eraser', 'erase']
for i in range(len(A)):
    A[i] = A[i][::-1]
while(len(s)!=0):
    cs = s
    for i in range(len(A)):
        if (s.startswith(str(A[i]))):
            #print(A[len(A[i])+1:])
            s = s[len(A[i]):]
            #print(s)
            break
    if (cs == s):
        print('NO')
        sys.exit()
print('YES')
