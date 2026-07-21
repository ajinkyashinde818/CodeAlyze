def main():


   N = int(input())
   buffeList = list(map(int,input().split()))
   gainList =  list(map(int,input().split()))
   addionList =  list(map(int,input().split()))
   ans = 0
   
   for i in range(N):
      wEat = gainList[buffeList[i]-1]
      ans += wEat
      if buffeList[i]-buffeList[i-1] == 1 and i>=1 :
         ans += addionList[buffeList[i-1]-1]
   print(ans)








if __name__== "__main__":
    main()
