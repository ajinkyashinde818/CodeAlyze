def gcd(a,b):
    if a==0 or b==0:
        return max([a,b])
    else:
        if a>=b:
            n=int(a/b)
            return gcd(a-n*b,b)
        else:
            n=int(b/a)
            return gcd(a,b-n*a)

def lcm(a,b):
   return int(a*b/gcd(a,b)) 
a=input().split(" ")
print(lcm(int(a[0]),int(a[1])))
