import math

def factorization(n):
    factor_list = []
    tmp = int(math.sqrt(n)) + 1
    for num in range(2, tmp+1):
        if n % num == 0:
            count = 0
            while n % num == 0:
                count += 1
                n //= num
                
            factor_list.append([num, count])
        
    if n != 1:
        factor = [n, 1]
        factor_list.append(factor)
    #print(n)
    return factor_list
            

def main():
    n = int(input())
    count = 0
    
    factor_list = factorization(n)
    
    for _, exponent in factor_list:
        #exponent = 1
        #n /= factor[0] ** exponent
        #count += 1
        #factor[1] -= exponent
        #exponent += 1
        #print(exponent)
        i = 1
        while exponent >= i:
            #print(factor_list)
            #n /= factor[0] ** exponent
            count += 1
            exponent = exponent - i
            i += 1
    
    print(count)
    return
    
if __name__ == '__main__':
    main()
