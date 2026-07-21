def solv_quadratic_equation(a, b, c):
    """ 2次方程式を解く  """
    D = (b**2 - 4*a*c) ** (1/2)
    x_1 = (-b + D) / (2 * a)
    x_2 = (-b - D) / (2 * a)


    return x_1, x_2





n=int(input())
N=n
a = []
while n % 2 == 0:

    a.append(2)
    n //= 2
f = 3
while f * f <= n:
    if n % f == 0:

        a.append(f)
        n //= f
    else:
        f += 2
if n != 1:

    a.append(n)

aa=set(a)
g=0
for i in aa:
    x1,x2=solv_quadratic_equation(1,1,-2*a.count(i))
    g=int(max(x1,x2))+g



print(g)
