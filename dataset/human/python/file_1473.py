import Data.Bool
import qualified Data.Set as S
import Control.Monad

main = do
 [n,m] <- map read . words <$> getLine
 ta <- concat <$> replicateM n getLine
 tb <- concat <$> replicateM m getLine
 let pa = map fst $ filter ((=='#') . snd) $ zip [(h,w) | h<-[0..n-1], w<-[0..n-1]] ta
 let pb = map fst $ filter ((=='#') . snd) $ zip [(h,w) | h<-[0..m-1], w<-[0..m-1]] tb
 let sa = S.fromDistinctAscList pa
 let sb = S.fromDistinctAscList pb
 let d = n - m
 putStrLn $ bool "No" "Yes" (templateMatch d sa sb)

templateMatch d sa sb = any (match sa sb) [(dh,dw) | dh<-[0..d], dw<-[0..d]]

match sa sb (dh,dw) = S.mapMonotonic (move dh dw) sb `S.isSubsetOf` sa

move dh dw (h,w) = (h+dh, w+dw)
