import sys
input = sys.stdin.buffer.readline
import bisect

def main():
    N = int(input())
    if N == 1:
        print(0)
        exit()
    
    def factorization(n):
        arr = []
        temp = n
        for i in range(2, int(-(-n**0.5//1))+1):
            if temp%i==0:
                cnt=0
                while temp%i==0:
                    cnt+=1
                    temp //= i
                arr.append([i, cnt])

        if temp!=1:
            arr.append([temp, 1])   

        if arr==[]:
            arr.append([n, 1])

        return arr
    
    c = factorization(N)
    
    can = []
    for i in range(1,50):
        can.append((i*(i+1))//2)

    ans = 0
    for _,cnt in c:
        ind = bisect.bisect_right(can,cnt)
        ans += ind
    
    print(ans)

if __name__ == "__main__":
    main()
