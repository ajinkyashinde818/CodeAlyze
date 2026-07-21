def main():
    k, n = list(map(int, input().split()))
    a = list(map(int, input().split()))
    
    d = []
    for i in range(len(a)):
        try:
            d.append(abs(a[i] - a[i+1]))
        except:
            break
    
    d_max = max(d)
    d_max2 = a[0] + (k-a[-1])
    print(k - max(d_max, d_max2))

if __name__ == '__main__':
    main()
