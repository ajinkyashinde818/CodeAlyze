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



def pop(stack):
	return stack[0],stack[1:]

def push(stack,x):
	stack.append(x)
	s = set(stack)
	p = list(s)
	p.sort()
	return p

n = int(input())
#a = sympy.factorint(n)
a = factorization(n)
ans = 0
if n != 1:
	for i in a:
		t = 1
		k = 1
		while t <= i[1]:
			#print(t,k,i[1])
			ans += 1
			k += 1
			t += k
			#print(t,k,i[1])
	
print(ans)
