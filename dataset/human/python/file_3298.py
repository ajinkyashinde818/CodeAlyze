N = int(input())




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


## [[2, 3], [3, 1]] 
##  24 = 2^3 * 3^1

def ruisekiwa(n):
	if n<3:
		return 1
	elif n<6:
		return 2
	elif n<10:
		return 3
	elif n<15:
		return 4
	elif n<21:
		return 5
	elif n<28:
		return 6
	elif n<36:
		return 7
	else:
		return 8


a=factorization(N)
ans=0
#print(a)

for insu in a:
	#print(insu[1])
	#print(ruisekiwa(insu[1]))
	ans+=ruisekiwa(insu[1])

if N==1:
	print(0)
else:
	print(ans)




# 2darray [[0] * 4 for i in range(3)]
