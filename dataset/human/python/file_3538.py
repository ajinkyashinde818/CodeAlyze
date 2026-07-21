import sys
input = sys.stdin.readline
    
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

def main():
    N = int(input())
    if N == 1:
        print(0)
        return
    arr = factorization(N)
    CNT = 0
    for p, e in arr:
        CNT += 1
        for i in range(2, 100):
            if e > i:
                e -= i
                CNT += 1
            else:
                break
    print(CNT)

if __name__ == '__main__':
    main()
