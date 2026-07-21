def main():
    mod = 10 **9 +7
    n=int(input())
    s=input()
    alp = [0 for i in range(26)]
    for i in range(n):
        alp[ord(s[i])-97] += 1
    ans = 1
    for i in range(26):
        ans *= (alp[i]+1)


    print((ans-1)%mod)

main()
