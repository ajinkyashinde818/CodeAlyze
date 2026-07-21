{-# LANGUAGE Strict #-}
import qualified Data.ByteString.Char8 as B
import           Data.Vector.Unboxed   (Vector)
import qualified Data.Vector.Unboxed   as V


main :: IO ()
main = do
  [k, n] <- map read . words <$> getLine
  as <- readIntsLn
  print $ solve k n as

readIntsLn :: IO (Vector Int)
readIntsLn = V.unfoldr (B.readInt . B.dropWhile (== ' ')) <$> B.getLine

solve :: Int -> Int -> Vector Int -> Int
solve k _ as = k - V.maximum bs
  where as' = as `V.snoc` a
        a = k + (V.head as)
        bs = V.zipWith (-) as' (0 `V.cons` as)
