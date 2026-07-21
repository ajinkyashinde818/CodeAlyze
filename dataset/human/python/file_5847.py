import sys

number = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
c = list(map(int,input().split()))
answer = 0

for i in range(number):
    answer += b[a[i]-1]
    
    if i != 0:
        if a[i-1] == a[i]-1:
            answer += c[a[i-1]-1]

print(answer)
