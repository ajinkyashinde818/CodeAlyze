N=int(input())
S=input()

def atoi(a):
    alphabet = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o',
                'p','q','r','s','t','u','v','w','x','y','z']
    return alphabet.index(a)

a_list = [0 for i in range(26)]
for i in range(N):
    a_list[atoi(S[i])]+=1
ans = 1
for i in range(26):
    ans *= (a_list[i]+1)
    ans = ans%(10**9 + 7)
if ans>0:
    ans-=1
else:
    ans=10**9 + 6
print(ans)
