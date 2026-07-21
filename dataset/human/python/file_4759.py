import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline

S = readline().rstrip().decode()
T = readline().rstrip().decode()

s = [ S[i] for i in range(len(S))]
t = [ T[i] for i in range(len(T))]

s.sort()
t.sort()
t.reverse()

for i in range(min(len(S),len(T))):
    if ord(s[i]) < ord(t[i]):
        print("Yes")
        exit(0)
    if ord(s[i]) > ord(t[i]):
        print("No")
        exit(0)

if len(S) < len(T):
    print("Yes")
    exit(0)
else:
    print("No")
    exit(0)
