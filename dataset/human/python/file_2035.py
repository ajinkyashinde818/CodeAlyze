from sys import stdin

N = int(stdin.readline().rstrip())
s = stdin.readline().rstrip()

inf = 10 ** 9 + 7
ans = 1

alphabet = [x for x in 'abcdefghijklmnopqrstuvwxyz']
count = [1 for _ in range(26)]

for i in range(len(s)):
    count[alphabet.index(s[i])] += 1

for j in count:
    ans = ans * j % inf

print(ans - 1)
