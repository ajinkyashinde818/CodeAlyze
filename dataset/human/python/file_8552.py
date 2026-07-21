import math




perimeter,N = map(int,input().split())
data = list(map(int,input().split()))


biggest_gap = perimeter-(data[-1]-data[0])

for i in range(1,len(data)):
    biggest_gap = max(biggest_gap,data[i]-data[i-1])

shortest_path = perimeter-biggest_gap

print(shortest_path)
