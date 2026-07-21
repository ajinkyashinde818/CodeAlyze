module Main where
import Control.Monad
import Control.Applicative
import Data.Maybe
import Data.List
import qualified Text.Printf
import qualified Data.ByteString.Char8 as BC
import qualified Data.ByteString as BC

------------------------------------------

main :: IO ()
main = do
  [m, n] <- readInts
  if m == 0 && n == 0 then return ()
  else do
  bs <- replicateM n readInt
  print $ binarySearch (check bs m) 0 1500000
  main

check :: [Int] -> Int -> Int -> Bool
check bs n lw = go bs 0 0
  where go [] _ _ = True
        go (b:bs) i w
          | i == n = False
          | lw-w >= b = go bs i (w+b)
          | otherwise = go (b:bs) (i+1) 0

binarySearch :: (Int -> Bool) -> Int -> Int -> Int
binarySearch f l r
  | l >= r     = r
  | f m       = binarySearch f l m
  | otherwise = binarySearch f (m+1) r
  where m = (l+r) `div` 2

------------------------------------------

{- Int input -}

parseInt :: BC.ByteString -> Int
parseInt = fst . fromJust . BC.readInt

parseInts :: BC.ByteString -> [Int]
parseInts = map parseInt <$> BC.words

readInt :: IO Int
readInt = parseInt <$> BC.getLine

readInts :: IO [Int]
readInts = parseInts <$> BC.getLine

{- Double Formatting -}

doubleFmt :: Double -> String
doubleFmt = Text.Printf.printf "%.12f"
