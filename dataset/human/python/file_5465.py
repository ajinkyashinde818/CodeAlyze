module Main (main) where

import qualified Data.ByteString.Char8     as C8

main :: IO ()
main = do
  [x,y] <- readStrings
  print . showAnswer $ solve (x,y)

type Input  = (String, String)
type Output = Ordering

solve :: Input -> Output
solve (x,y) = compare (toInt x) (toInt y)
  where
    toInt "A" = 10
    toInt "B" = 11
    toInt "C" = 12
    toInt "D" = 13
    toInt "E" = 14
    toInt "F" = 15

showAnswer :: Output -> Answer
showAnswer = Compare

-- utils
readStrings :: IO [String]
readStrings = map C8.unpack . C8.words <$> C8.getLine

data Answer
  = YesNo Bool
  | YESNO Bool
  | AB Bool
  | Number Int
  | Compare Ordering

instance Show Answer where
  show (YesNo b)   = if b then "Yes" else "No"
  show (YESNO b)   = if b then "YES" else "NO"
  show (AB b)      = if b then "A"   else "B"
  show (Number i)  = show i
  show (Compare o)
    | o == EQ = "="
    | o == LT = "<"
    | o == GT = ">"
