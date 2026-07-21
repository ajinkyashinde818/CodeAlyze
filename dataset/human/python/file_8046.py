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
  [k, s] <- readInts
  let twoSums = [max 0 $ min (x+1) (2*k+1-x) | x <- [0..s]]
  print $ sum $ drop (s-k) twoSums

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
