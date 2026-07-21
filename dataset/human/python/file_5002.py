from copy import copy

p = []
while(1):
    try:
        p = [int(i) for i in input().split()]
        min_ = 10**10
        point = 0
        arrmin = []
        arr = [4,1,4,1,2,1,2,1]
        for _ in range(8):
            temp = copy(arr[0])
            repl = copy(arr[1:8])
            arr[0:7] = repl
            arr[7] = temp
            point = sum([j-i if i < j else 0 for i,j in zip(arr,p)])
            if point == min_:
                arrmin.append(copy(arr))
                min_ = point
            elif point < min_:
                arrmin = [copy(arr)]
                min_ = point
        arrmin = ["".join([str(i) for i in j]) for j in arrmin]
        amin = min([int(i) for i in arrmin])
        out = list(str(amin))
        print(" ".join(out))
    except EOFError:
        break
