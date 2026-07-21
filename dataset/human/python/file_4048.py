def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
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

def get_z(factor):
    for f_list in factor:
        for i in range(f_list[1]):
            z = f_list[0] ** (i + 1)
            if z not in choice_list:
                choice_list.append(z)
                return z

choice_list = []
n = int(input())
factor = factorization(n)

while n > 1:
    z = get_z(factor)
    if z is None:
        break
#     print(z)
#     print(choice_list)
    n //= z
    factor = factorization(n)
#     print(z)
print(len(choice_list))
