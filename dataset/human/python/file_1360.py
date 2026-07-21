import sys

N = int(input())
Cards = list(map(int, input().split()))
if N==2:
    print(abs(Cards[0] - Cards[1]))
    sys.exit()
B = sum(Cards) - Cards[0]
A = Cards[0]

del Cards[0]
del Cards[-1]
answer = 100000000

if N==2:
    print(abs(Cards[0] - Cards[1]))
    sys.exit()
for number in Cards:
    A += number
    B -= number
    if abs(A-B) < answer:
        answer = abs(A-B)

print(answer)
