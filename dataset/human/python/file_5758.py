import Data.List
import Control.Monad
import qualified Data.Vector.Unboxed as V
import qualified Data.ByteString.Char8 as BS

getIntList :: IO [Int]
getIntList = unfoldr (BS.readInt . BS.dropWhile (== ' ')) <$> BS.getLine

mod' :: Integral a => a -> a
mod' n = if n < 1000000007 then n else n `mod` 1000000007

f :: V.Vector Int -> [Int] -> Int
f cs (a:aa:as) = if (a+1) == aa then (cs V.! (a-1)) + (f cs (aa:as)) else f cs (aa:as)
f _ _ = 0

main :: IO ()
main = do
  n <- readLn :: IO Int
  as <- getIntList
  bs <- getIntList
  cs <- V.fromList <$> getIntList
  print $ (f cs as) + (sum bs)
