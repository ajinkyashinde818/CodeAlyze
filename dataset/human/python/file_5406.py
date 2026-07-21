module Main (main) where

import qualified Data.ByteString.Char8     as C8
import           Data.Maybe

main :: IO ()
main = do
  [n] <- readInts
  print . showAnswer $ solve n

type Input  = (Int)
type Output = Bool

solve :: Input -> Output
solve = any (=='9') . show

showAnswer :: Output -> Answer
showAnswer = YesNo

-- utils
readInts :: IO [Int]
readInts = map (fst . fromJust . C8.readInt) . C8.words <$> C8.getLine

data Answer
  = YesNo Bool
  | AB Bool
  | Number Int

instance Show Answer where
  show (YesNo b)  = if b then "Yes" else "No"
  show (AB b)     = if b then "A"   else "B"
  show (Number i) = show i
