module Main where

import Data.Bool (bool)
import Data.Char (isSpace)
import Data.Maybe (fromJust)
import Data.List (unfoldr)
import qualified Data.ByteString.Char8 as BS


main :: IO ()
main = do
  [k,s] <- readIntList . head <$> plainInputs
  print $ sum $ tiles k s

tiles :: Int -> Int -> [Int]
tiles k s = do
  x <- [0..lim s]
  y <- [0..lim (s-x)]
  pure $ bool 0 1 $ inbound (s-x-y)
  where
    inbound a = 0 <= a && a <= k
    lim a = min a k


-- utils
readInt :: BS.ByteString -> Int
readInt = fst . fromJust . BS.readInt

readIntList :: BS.ByteString -> [Int]
readIntList = unfoldr (BS.readInt . BS.dropWhile isSpace)

plainInputs :: IO [BS.ByteString]
plainInputs = BS.lines <$> BS.getContents
