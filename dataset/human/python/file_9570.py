import sys 
N,K = map(int,input().split())
l = list(map(int,input().split()))
m = [0 for i in range(N)]
location = 0
count = 0
for i in range(K):
    location = l[location] -1
    m[location] += 1
    if m[location] == 2:
        start = location
        for j in range(K-i-1):
            location = l[location] -1
            count += 1
            if location == start:
                for k in range((K-i-j-2)%count):
                    location = l[location] -1
                print(location + 1)
                sys.exit()
        print(location + 1)
        sys.exit()
print(location + 1)
