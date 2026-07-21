N=int(input())
munou=[]
count=0
sumi=set()
if N==1:
    print(0)
    exit()
def factorization(n):
    def sieve(n):
        is_prime = [True for _ in range(n+1)]
        is_prime[0] = False

        for i in range(2, n+1):
            if is_prime[i-1]:
                j = 2 * i
                while j <= n:
                    is_prime[j-1] = False
                    j += i
        table = [ i for i in range(1, n+1) if is_prime[i-1]]
        return table
    arr = []
    temp = n
    for i in sieve(int(n**0.5)):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])
    if temp!=1:
        arr.append([temp, 1])
    if arr==[]:
        arr.append([n, 1])
    return arr
kari=factorization(N)
for i in range(len(kari)):
    for j in range(1,kari[i][1]+1):
        z=kari[i][0]**j
        if N%z==0 and z not in sumi:
            sumi.add(z)
            N=N/z
            count+=1
print(count)
#print(kari)
