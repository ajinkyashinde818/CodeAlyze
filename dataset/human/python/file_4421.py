import math

def prime(x):
    if x==1:
        prime=False
    else:
        prime=True
        for i in range(2,int(math.sqrt(x)+1)):
            if x%i==0:
                prime=False
                break
    return prime

def count_prime(N):
    p=[0 for n in range(int(math.sqrt(N)+1))]
    
    if prime(N):#初期値が素数の場合
        big_prime=True
        
    else:#初期値が素数でない場合
        big_prime=False
        rtN_init=int(math.sqrt(N)+1)
        
        #素因数分解。ルートＮまでの範囲で素因数を探す。見つかったらpの素因数インデックスを++
        while N>1:
            #素数がルートNを超える場合
            if prime(N) and N>rtN_init:
                big_prime=True
                break
            else:
                for i in range(2,rtN_init):
                    if N%i==0 and prime(i):
                        p[i]+=1
                        N=N//i
                        break
    return p,big_prime

def main():
    N=int(input())
    p,q=count_prime(N)
    cnt=0
    
    for n in range(len(p)):
        num=1
        while p[n]>=1:
            p[n]-=num
            if p[n]>=0:
                cnt+=1
                num+=1
    if q==True:
        cnt+=1
    print(cnt)
        
if __name__=="__main__":
    main()
