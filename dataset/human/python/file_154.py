def counter(r,g,b,n):
    count = 0
    max_y = n//g
    max_z = n//b

    for y in range(max_y + 1):
        for z in range(max_z + 1):
            x_before = n - g*y - b*z
            if( (x_before / r) < 0 ):
                break
            if( (x_before % r == 0) ):
                count += 1
    return count

r,g,b,n = map(int, input().split())
print(counter(r,g,b,n))
