import sys
input = sys.stdin.readline
def main():
    n,k = map(int,input().split())
    l = list(map(int,input().split()))
    roop = [1]
    stayed = [0]*n
    for i in range(n):
        next_city = l[roop[-1]-1]
        if stayed[next_city-1]:
            endindex = i
            for j,r in enumerate(roop):
                if r == next_city:
                    startindex = j
            break
        else:
            roop.append(next_city)
            stayed[next_city-1] = 1

    if k < startindex:
        print(roop[k])
    else:
        dis = endindex - startindex + 1
        a = (k - startindex) % dis
        print(roop[a + startindex])
main()
