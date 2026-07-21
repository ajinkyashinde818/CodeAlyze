def L_search(A,key):
    for i in range(len(A)):
        if A[i] == key:
            return i

def main():
    N,K = map(int,input().split())
    A = list(map(int,input().split()))

    Loop_set,Loop_list = set([1]),[1]
    pt = 1 #最初の町
    while True:
        pt = A[pt-1]
        if pt not in Loop_set:
            Loop_set.add(pt)
            Loop_list.append(pt)
        else:
            break

    gosa = L_search(Loop_list,pt)
    shuki = len(Loop_list) - gosa
    if K < gosa:
        print(Loop_list[K])
    else:
        K -= gosa
        K %= shuki
        K += gosa
        print(Loop_list[K])

if __name__ == "__main__":
    main()
