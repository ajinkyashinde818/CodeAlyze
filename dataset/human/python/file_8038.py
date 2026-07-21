{-# LANGUAGE BangPatterns #-}
 
module Main
  ( main
  )
where
 
import           Control.Applicative
import           Control.Monad
import           Control.Monad.ST
import           Data.Bits
import qualified Data.ByteString.Char8         as BS
import           Data.Char
import           Data.List
import           Data.Maybe
import           Data.Ord
import qualified Data.Vector                   as V
import qualified Data.Vector.Mutable           as MV
import qualified Data.Vector.Unboxed           as UV

parse = fst . fromJust
parseInt = parse . BS.readInt
parseInteger = parse . BS.readInteger
readInt = parseInt <$> BS.getLine
readInteger = parseInteger <$> BS.getLine
readIntList = map parseInt . BS.words <$> BS.getLine
readIntegerList = map parseInteger . BS.words <$> BS.getLine

main = do
  [k, s] <- readIntList
  let candidate = solve k s
  print $ length candidate

solve k s = do
  a <- [0..k]
  b <- [0..(min (s - a) k)]
  let c = s - a - b
  if c >= 0 && c <= k 
    then return (a, b, c) 
    else []
