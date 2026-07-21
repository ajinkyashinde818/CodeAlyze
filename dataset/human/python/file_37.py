s = input()
answer = 0
s =s.split(" ")
R = int(s[0])
G = int(s[1])
B = int(s[2])
N = int(s[3])

def turukame(g,b,n):
    ans = 0
    for j in range(n//g+1):
        if (n-g*j) % b == 0:
            ans = ans + 1
    return ans


for i in range(N // R+1):
    answer = answer + turukame(G,B,N-R*i)

print(answer)
