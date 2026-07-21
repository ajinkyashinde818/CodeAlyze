{-# LANGUAGE BangPatterns #-}

module Main
  ( main
  )
where
 
import           Control.Applicative
import           Control.Monad
import           Data.Bits
import qualified Data.ByteString.Char8         as BS
import           Data.Char
import           Data.List
import           Data.Maybe
import qualified Data.Vector                   as V
 
parse = fst . fromJust
parseInt = parse . BS.readInt
parseInteger = parse . BS.readInteger
readInt = parseInt <$> BS.getLine
readInteger = parseInteger <$> BS.getLine
readIntList = map parseInt . BS.words <$> BS.getLine
readIntegerList = map parseInteger . BS.words <$> BS.getLine

res = 1000000000 + 7

main = do
  [n, m] <- readIntList
  pic <- V.fromList <$> replicateM n (V.fromList <$> getLine)
  temp <- V.fromList <$> replicateM m (V.fromList <$> getLine)
  let cands = [(i, j) | i <- [0..(n - m)], j <- [0..(n - m)]]
      includes = any (judge pic temp m) cands
  putStrLn $ if includes then "Yes" else "No"

judge pic temp m (x, y) = all (\(i, j) -> (pic V.! (x + i)) V.! (y + j) == (temp V.! i) V.! j) [(i, j) | i <- [0..(m - 1)], j <- [0..(m - 1)]]
