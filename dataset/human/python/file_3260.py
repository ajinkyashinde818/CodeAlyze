def fanction(n):
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
    z_list=[]
    arr = fanction(N)
    k=0
    for i in range(len(arr)):
        p=arr[i][1]
        for j in range(1,arr[i][1]+1):
            if p>=j:
                z = arr[i][0]
                z_list.append(z)
                k+=1
                p-=j
    if N==1:
        k=0
    print(k)

main()
