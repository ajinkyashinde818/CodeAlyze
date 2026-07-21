from array import array

N = int(input())
A = list(map(int, input().split()))

i_of_minimum_abs = 0
minimum_abs = 10**9
Aarray = array('l', A)

for i in range(N):
    a = Aarray[i]
    if abs(a) < minimum_abs:
        minimum_abs = min(minimum_abs, abs(a))
        i_of_minimum_abs = i

for i in range(i_of_minimum_abs):
    if Aarray[i] < 0:
        Aarray[i] = -Aarray[i]
        Aarray[i+1] = -Aarray[i+1]
        
for i in reversed(list(range(i_of_minimum_abs+1,N))):
    if Aarray[i] < 0:
        Aarray[i] = -Aarray[i]
        Aarray[i-1] = -Aarray[i-1]

print(sum(Aarray))
