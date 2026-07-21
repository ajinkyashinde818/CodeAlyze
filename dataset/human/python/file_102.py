def pat(R,G,B,N):
    output = 0
    for r in range(N//R+1):
        for g in range((N-R*r)//G+1):
            if (N-R*r-G*g) % B == 0:
                output += 1
    return output

def main():
    R,G,B,N = map(int,input().split())

    ans = pat(R,G,B,N)

    print(ans)

if __name__ == "__main__":
    main()
