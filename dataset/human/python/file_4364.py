def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append(cnt)

    if temp!=1:
        arr.append(1)

    if arr==[]:
        arr.append(1)

    return arr
n = int(input())
if n == 1:
  print(0)
else:
  arr = factorization(n)
  arr_len = len(arr)
  count = 0
  for i in range(arr_len):
    arr_i = arr[i]
    if arr_i < 3:
      count += 1
    elif arr_i < 6:
      count += 2
    elif arr_i < 10:
      count += 3
    elif arr_i < 15:
      count += 4
    elif arr_i < 21:
      count += 5
    elif arr_i < 28:
      count += 6
    elif arr_i < 36:
      count += 7
    else:
      count += 8
  print(count)
