import math 
  
def formula(y):
    return int(((8 * y + 1) ** 0.5 - 1) / 2)

def factorize(n): 
    count = 0; 
    ans = 0
    while ((n % 2 > 0) == False):  
          
        n >>= 1;  
        count += 1; 
  
    if (count > 0): 
        ans += formula(count)
  
    for i in range(3, int(math.sqrt(n)) + 1): 
        count = 0; 
        while (n % i == 0):  
            count += 1; 
            n = int(n / i); 
        if (count > 0): 
            ans += formula(count)
        i += 2; 
  
    if (n > 2): 
        ans += 1
    return ans

n = int(input())            
print(factorize(n))
