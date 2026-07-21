import string 
letters = string.ascii_letters

while True:
    n = int(input())
    if n == 0:
        exit(0)
    k = list(map(int, input().split()))
    s = input()
    
    res = ""
    i = 0
    for x in s:
        res += letters[letters.find(x) - k[i]]
        i = (i + 1) % n

    print(res)
