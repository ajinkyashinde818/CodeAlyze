import math 

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

factorization(24) 
if __name__ == "__main__":
    s = int(input())
    a = factorization(s) #行列
    if a[0][0] == 1:
        print(0)
    else:
        an = 0
        for list1 in a: #[3,6]の形
            z = 0
            check = 0
            count = list1[1]
            while True:
                z += 1
                count -= z
                if count < 0:
                    break
                check += 1
            an += check
        print(an)
