K,S = map(int,input().split())
def main(K,S):
    if S > 3*K:
        print(0)
        
    else:
        count = 0
        for i in range(K+1):
            for j in range(K+1):
                if 0 <= S - i - j <= K:
                    count += 1
        print(count)
if __name__ == '__main__':
   main(K,S)
