def main():
    
    import collections

    N = int(input())

    def factorization(num):
        factorize = []
        while (num % 2 == 0):
            num //= 2
            factorize.append(2)
        
        division = 3
        
        while (division * division <= num):
            
            if (num % division == 0):
                factorize.append(division)
                num //= division
            else:
                division += 2
            
        if (num != 1):
            factorize.append(num)
        
        return (factorize)
    
    def count_div(n):
        cnt = 0
        sub = 0
        
        while (n > 0):
            sub += 1
            n -= sub
            if (n >= 0):
                cnt += 1

        return(cnt)

    facts = factorization(N)
    CTR_facts = collections.Counter(facts).most_common()
    
    ans = 0
    
    for i in range(len(CTR_facts)):
        v = CTR_facts[i][1]
        
        tmp = count_div(v)
        ans += tmp
    
    print(ans)


if __name__ == '__main__':
    main()
