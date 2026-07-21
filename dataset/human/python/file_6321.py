module Main
  ( main
  )
where

import           Control.Applicative
import           Control.Monad
import           Data.List
import           Data.Array
import           Data.Char
import           Data.Bits
import qualified Data.ByteString.Char8 as BS
import Data.Maybe

parse = fst . fromJust
parseInt = parse . BS.readInt
parseInteger = parse . BS.readInteger
readInt = parseInt <$> BS.getLine
readInteger = parseInteger <$> BS.getLine
readIntList = map parseInt . BS.words <$> BS.getLine

main = do
  n <- readInteger
  print $ if n `mod` 2 == 1 then 0 else count n 10 5

count n d m
  | n < d = 0
  | otherwise = n `div` d + count n (d * m) m
