import qualified Data.ByteString.Char8 as BC
import qualified Data.Vector.Unboxed as VU
import Data.Char
import Data.List

main = do
  [k,n] <- map read . words <$> getLine :: IO [Int]
  xs <- VU.unfoldrN n (BC.readInt . BC.dropWhile isSpace) <$> BC.getLine
  let ys = xs VU.++ VU.map (+k) xs
  print $ minimum  $ map (\i -> ys VU.! (i+n-1) - (ys VU.! i)) [0..n-1]
