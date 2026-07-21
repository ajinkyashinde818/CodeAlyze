import Data.List
f l a n=if null l then (n+1) else if a==head l then f (tail l) a (n+1) else mod ((n+1)*f (tail l) (head l) 1) 1000000007
main=do
 n<-getLine
 s<-sort<$>getLine
 print$(f (tail s)(head s)1) -1
