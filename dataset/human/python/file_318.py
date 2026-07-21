def main():

    N = int(input())
    A = [int(a) for a in input().split()]

    B = [abs(a) for a in A]
    if 0 in A:
        print(sum(B))
    else:

        count = 0
        for a in A:
            if a < 0:
                count += 1

        if count % 2 == 0:
            print(sum(B))
        else:
            print(sum(B) - 2*min(B))    


main()
