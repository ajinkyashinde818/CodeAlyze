def make_divisors(n):
    lower_divisors = []
    upper_divisors = []
    for i in range(1, int(n**0.5)+1):
        if n % i == 0:
            lower_divisors.append(i)
            if i != n // i:
                upper_divisors.append(n//i)

    upper_divisors.reverse()
    return lower_divisors + upper_divisors

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

n = int(input())

ans = []
used_list = []

def solve(n, used_list):
  if n == 1:
    return len(used_list)
  div_list = make_divisors(n)[1:]
  for i in div_list:
    z_kouho = factorization(i)
    if i not in used_list and len(z_kouho) == 1:
      used_list.append(i)
      return solve(int(n/i),used_list)
  
  return len(used_list)
      
print(solve(n, used_list))
