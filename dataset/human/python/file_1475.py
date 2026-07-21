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
  [n, m] <- readInts
  pm <- replicateM n getLine
  qm <- replicateM m getLine
  putStrLn $ if solve n m pm qm then "Yes" else "No"

solve :: Int -> Int -> [String] -> [String] -> Bool
solve n m pm qm = not . null $ do
  x <- [0..n-m]
  y <- [0..n-m]
  let rm = map (take m . drop y) $ take m $ drop x pm
  if rm == qm then [rm] else []

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
