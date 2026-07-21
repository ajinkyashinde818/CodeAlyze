import qualified Data.Vector.Unboxed as U
import Data.Bits
import Data.List
import Control.Monad

solve :: Int -> Int -> U.Vector (Int, Int) -> Int
solve d g pc = minimum ans where
  ans =
    [ num | b <- [(0 :: Int)..2^d-1]
    , let (num, scr) = f b, scr >= g ] 
  f b = (ncmp + nres, comp + rest) where
    (ncmp, comp) = foldl pairAdd (0, 0) $
      [ (p, p*(i+1)*100 + c)
      | i<-[0..d-1], testBit b i, let (p, c) = pc U.! i ]
    (nres, rest) = case find (not.testBit b) [d-1,d-2..0] of
      Nothing -> (0, 0)
      Just i -> let (p, c) = pc U.! i in
        let nres = max 0 $ min p ((g-comp) `divC` (100*(i+1))) in
        (nres, nres * 100 * (i+1))

pairAdd (a,b) (c,d) = (a+c, b+d)
a `divC` b = (a+b-1) `div` b

main = do
  [d, g] <- readWords
  pc <- replicateM d $ (\[a,b]->(a,b)) <$> readWords
  print $ solve d g (U.fromList pc)

readWords = map read . words <$> getLine
