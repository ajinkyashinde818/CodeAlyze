def B(info):
    rgb = [0]*3
    *rgb, n = map(int,info.split())
    rgb.sort(reverse = True)
    count = 0
    for i in range(n//rgb[0]+1):
        new_n = n - i*rgb[0]
        if new_n < rgb[2]:
            if new_n == 0:
                count += 1
            continue
        for j in range(new_n//rgb[1]+1):
            if (new_n-rgb[1]*j)%rgb[2] == 0:
                count += 1

    return count

    
if __name__ == '__main__':
    print(B(input()))
