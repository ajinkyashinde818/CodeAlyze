n = int(input())
 
def prime_factorise(n):
    a = []
    tmp = n
    for i in range(2, int(n**0.5//1 + 1)):
        if tmp % i == 0:
            index = 0  # 指数
            while tmp % i == 0:
                index += 1
                tmp //= i
            a.append([i, index])
 
    if tmp != 1:
        a.append([tmp, 1])

    if a == []:
        a.append([n,1])

    return a
 
x = prime_factorise(n)
count = 0
 
 
for i in range(len(x)):
    if x[0][0] == 1:
        break
 
    k = x[i][1]  # 指数の値
    for j in range(k):
        if n % (x[i][0] ** (j+1)) == 0:
            n //= x[i][0] ** (j+1)
            count += 1
            k -= (j+1) #指数の値をへらす
 
        elif n % (x[i][0]**(j+1)) != 0:
            break
        
        if k <= 0:
            break
 
print(count)
