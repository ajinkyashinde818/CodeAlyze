import Data.Bits
import Data.List
import Data.Maybe (fromJust)
import qualified Data.Vector.Unboxed as V
import qualified Data.ByteString.Lazy.Char8 as B
import Debug.Trace

type Ans = Int

solve :: Int -> [Int] -> Ans
solve n as =  max case1 case2
  where
    pos = V.fromList $ sort $ filter (0 <=) as
    neg = V.fromList $ sort $ filter (0 >) as
    lpos = V.length pos
    lneg = V.length neg
    case1 = if (lneg `mod` 2) == 0 then (V.sum pos) - (V.sum neg)
      else (V.sum pos) - (V.sum $ V.take (lneg-1) neg) + (V.last neg)
    case2 = if (lneg `mod` 2) == 0 then (V.sum pos) - (V.sum neg)
      else if pos == (V.fromList []) then (V.head neg) - (V.sum $ V.tail neg)
        else (V.sum $ V.tail pos) - (V.head pos) - (V.sum $ neg)

main :: IO ()
main = do
  n <- readLn :: IO Int
  as <- map read.words <$> getLine
  print $ solve n as
