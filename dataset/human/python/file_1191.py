import qualified Data.IntSet as S
import Data.List
import Control.Monad
import Data.Maybe

main = do
 getLine
 ls <- map read. words <$> getLine
 let als = scanl1 (+) (init ls)
 let als' = scanr1 (+) (tail ls)
 let s1 = S.fromList als
 let s2 = S.fromList als'
 let med = div (sum ls) 2
 print $ pile s1 s2 med

pile s1 s2 med = min (abs (hi-lo)) (abs (hi'-lo'))
 where
  lo = maybe 0 id (S.lookupLE med s1)
  hi = maybe (maxBound :: Int) id (S.lookupGE med s2)
  lo' = maybe 0 id (S.lookupGE med s1)
  hi' = maybe (maxBound :: Int) id (S.lookupLE med s2)
