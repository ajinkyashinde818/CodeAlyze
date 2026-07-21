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

parseInt = fst . fromJust . BS.readInt
readInt = parseInt <$> BS.getLine
readIntList = map parseInt . BS.words <$> BS.getLine

main = do
  [a, b] <- readIntList
  print $ leastCommonMultiple a b

leastCommonMultiple a b = (a * b) `div` greatestCommonDivisor a b
greatestCommonDivisor a b 
  | b == 0 = a
  | otherwise = greatestCommonDivisor b (a `mod` b)
