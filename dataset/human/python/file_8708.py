def main():
    k, n = list(map(int,input().strip().split()))
    a = list(map(int,input().strip().split()))

    point_start = 0
    point_end = 0
    max_dist = 0
    tmp_dist = 0

    for i in range(len(a)-1):
        tmp_dist = max(max_dist, a[i+1]-a[i])
        if(tmp_dist!=max_dist):
            point_start = i+1
            max_dist = tmp_dist

    tmp_dist = max(max_dist, (k-a[n-1])+a[0])
    if(tmp_dist!=max_dist):
        point_start = 0
        max_dist = tmp_dist


    dist = 0

    for i in range(len(a)-1):
        if(point_start!=(n-1)):
            dist = dist + (a[point_start+1]-a[point_start])
            point_start = point_start + 1
        else:
            dist = dist + ((k-a[point_start])+a[0])
            point_start = 0

    print(dist)

main()
