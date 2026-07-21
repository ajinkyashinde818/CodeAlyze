{-# LANGUAGE OverloadedStrings #-}
import Data.Maybe
import Data.Char
import Data.List
import qualified Data.ByteString.Char8 as BS
import qualified Data.Vector.Unboxed as VU

main :: IO()
main = do
  n <- getInt
  ns <- getIntList
  ms <- getIntVec n
  ls <- getIntVec (n-1)
  print $ solve ms ls ns

solve ms ls ns = f ns
  where
    f [n] = ms VU.! (n-1)
    f (p:q:qs)
      | q - p == 1 = ms VU.! (p-1) + ls VU.! (p-1) + f (q:qs)
      | otherwise = ms VU.! (p-1) + f (q:qs)

-- IO
readInt :: BS.ByteString -> Int
readInt = fst . fromJust . BS.readInt

getInt :: IO Int
getInt = readInt <$> BS.getLine

getIntList :: IO [Int]
getIntList = unfoldr (BS.readInt . BS.dropWhile isSpace) <$> BS.getLine

getIntVec :: Int -> IO (VU.Vector Int)
getIntVec n = VU.unfoldrN n (BS.readInt . BS.dropWhile isSpace) <$> BS.getLine
