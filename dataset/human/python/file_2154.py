import sys
DBG = True
BIG = 1000000007
n = int(input())
s = input()
cnt = { 'a':0, 'b':0, 'c':0, 'd':0, 'e':0, 'f':0, 'g':0, 'h':0, 'i':0, 'j':0, 'k':0, 'l':0, 'm':0, 'n':0, 'o':0, 'p':0, 'q':0, 'r':0, 's':0, 't':0, 'u':0, 'v':0, 'w':0, 'x':0, 'y':0, 'z':0 }
for i in range(n):
    cnt[s[i]] += 1

prod = 1
for key in cnt:
    prod = (prod * (cnt[key] + 1)) % BIG
print((prod-1)%BIG)
