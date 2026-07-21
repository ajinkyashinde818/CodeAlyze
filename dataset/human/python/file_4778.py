def alf(a):
   A = "abcdefghijklmnopqrstuvwxyz"
   for l in range(26):
      if a == A[l]:
         return l
   return -1

def main():
   s = input()
   t = input()

   S = []
   for s in s:
      S.append([alf(s), s])
   T = []
   for t in t:
      T.append([alf(t), t])
   
   S.sort()
   T.sort()
   T = T[::-1]
   for i in range(len(S)):
      if i == len(T):
         return "No"
      elif S[i] < T[i]:
         return "Yes"
      elif S[i] > T[i]:
         return "No"
   if len(S)==len(T):
      return "No"
   else:
      return "Yes"

print(main())
