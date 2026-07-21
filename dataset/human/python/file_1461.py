import Control.Monad
f s p n m=(((take m).(drop n)).map ((take m).(drop p))) s
g a b l r=if r+(length b) > length a then False else if l+(length b) > length a then  g a b 0 (r+1) else
          if b==f a l r (length b) then True else g a b (l+1) r
main=do
 [n,m]<-map read.words<$>getLine
 a<-replicateM n getLine
 b<-replicateM m getLine
 putStrLn$if g a b 0 0 then"Yes"else"No"
