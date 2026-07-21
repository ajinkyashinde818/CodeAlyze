def main():
    n = int(input())
    
    ans = 0
    i = 2
    while i * i <= n:
        count = 0
        while n % i == 0:
            count += 1
            n //= i
        times = 1
        while count > 0:
            count -= times
            times += 1
            ans += 1
        if count < 0:
            ans -= 1
        i += 1
    
    if n > 1:
        ans += 1
    
    print(ans)

main()
