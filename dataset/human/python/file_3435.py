import sys
 
if __name__ == '__main__':
    val = int(input().strip())

    arr = []
    i = 2
    while i < int(val ** 0.5 + 1):
        if val % i == 0:
            arr.append(i)
            val //= i
            continue
        i += 1
    if val != 1:
        arr.append(val)
    
    
    count = 0
    cur_val = 0

    for e in arr:
        if cur_val != e:
            cur_val = e
            times = 1
            n = 1
        if times == n * (n + 1) // 2:
            count += 1
            n += 1
        times += 1
    
    print(count)
