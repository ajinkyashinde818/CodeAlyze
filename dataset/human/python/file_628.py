def abs(i):
    if i <0:
        i = -i
    return i
N = int(input())
As = [int(Ai) for Ai in input().split()]
count = 0
for i in As:
    if i <= 0:
        count += 1
As_prime = [abs(Ai) for Ai in As]
if count % 2 == 0:
    print(sum(As_prime))
else:
    print(sum(As_prime)-2*min(As_prime))
