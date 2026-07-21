import math

def tri_num(num):
    t = c = 0
    while t + c < num:
        c += 1
        t += c
    return c

def main():
    N = int(input())

    pf = {}
    m = N
    for i in range(2,int(m**0.5)+1):
        while m%i==0:
            pf[i]=pf.get(i,0)+1
            m//=i
    if m>1:pf[m]=1

    ans = 0
    for i in pf.values():
        ans += tri_num(i)

    print(ans)
    
if __name__ == "__main__":
    main()
