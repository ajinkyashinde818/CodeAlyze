def gcd(a,b): 
    if a == 0: 
        return b 
    return gcd(b % a, a) 
  
def lcm(a,b): 
    return (a*b) / gcd(a,b) 

def main():
    A, B = list(map(int, input().split()))

    print(int(lcm(A,B)))

if __name__ == "__main__":
    main()
