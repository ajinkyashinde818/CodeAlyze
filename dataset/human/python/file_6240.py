import sys
range = xrange
input = raw_input

ord0 = ord('0')

S = [ord(c)-ord0 for c in input()]

n = len(S)

i = n - 1
while S[i] == 0:
    i -= 1
S = S[:i + 2]

n = len(S)
DP0 = [0]*(n + 1)
DP1 = [0]*(n + 1)

DP1[0] = 1

for i in range(n):
    if S[i] != 0:
        DP0[i + 1] = min(DP1[i] + 1 + min(9 - S[i], S[i]), DP0[i] + S[i])
        DP1[i + 1] = min(DP0[i] + 1 + min(9 - S[i], S[i]), DP1[i] + 9 - S[i])
    else:
        DP0[i + 1] = min(DP1[i] + 1 + min(10 - S[i], S[i]), DP0[i] + S[i])
        DP1[i + 1] = min(DP0[i] + 1 + min(10 - S[i], S[i]), DP1[i] + 10 - S[i])

print DP0[-1]
