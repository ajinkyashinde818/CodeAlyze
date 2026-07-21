def main():
    while True:
        n = int(input())
        if n == 0:
            return
        kk = list(map(int,input().split()))
        S = input()
        ans = ""
        for i,s in enumerate(S):
            if s.islower():
                k = (ord(s)-ord('a')-kk[i%len(kk)])
                if k < -26:
                    ans += chr(ord('a')+k%26)
                elif k < 0:
                    ans += chr(ord('A')+k%26)
                else:
                    ans += chr(ord('a')+k)
            if s.isupper():
                k = (ord(s)-ord('A')-kk[i%len(kk)])
                if k < -26:
                    ans += chr(ord('A')+k%26)
                elif k < 0:
                    ans += chr(ord('a')+k%26)
                else:
                    ans += chr(ord('A')+k)
        print(ans)

if __name__ == '__main__':
    main()
