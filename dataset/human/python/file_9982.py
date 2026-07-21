def calculate_gcd(x, y):
   while(y):
       x, y = y, x % y
   return x

def calculate_lcm(x, y):
    lcm = (x*y)//calculate_gcd(x,y)
    return lcm


str = input()
list1=str.split(' ')
a=int(list1[0])
b=int(list1[1])

lcm= calculate_lcm(a,b)

print(lcm)
