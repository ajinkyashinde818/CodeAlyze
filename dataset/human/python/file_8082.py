from sys import stdin

def main():
    K, S = map(int, stdin.readline().rstrip().split())
    ans=0
    for X in range(K+1):
      for Y in range(K+1):
        Z = S - X -Y
        if Z >= 0 and Z <= K:
          ans +=1
        
    print(ans)

input = lambda: stdin.readline()
main()
