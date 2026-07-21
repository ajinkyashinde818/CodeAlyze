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
import qualified Data.Vector.Mutable           as MV
import           Control.Monad.ST
 
parse = fst . fromJust
parseInt = parse . BS.readInt
parseInteger = parse . BS.readInteger
readInt = parseInt <$> BS.getLine
readInteger = parseInteger <$> BS.getLine
readIntList = map parseInt . BS.words <$> BS.getLine
readIntegerList = map parseInteger . BS.words <$> BS.getLine
 
main = do
  x <- readInt
  putStrLn $ if x < 1200 then "ABC" else "ARC"
