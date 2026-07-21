from sys import stdin
import math
input=input=stdin.readline().rstrip().split()
for i in range(len(input)):
  input[i]=int(input[i])

output=0
R=input[0]
G=input[1]
B=input[2]
N=input[3]
for r in range(math.floor(N/R)+1):
    for g in range(math.floor(N/G)+1):
        #for b in range(math.floor(N/B)+1):
        #print(r,g)
        #if r*R+g*G+b*B==N:
        b=N-(r*R+g*G)
        #b/B
        #if b>=0:
        if b<0:
            break
        if b % B == 0:
            #print(r,g)
            output+=1
print(output)
