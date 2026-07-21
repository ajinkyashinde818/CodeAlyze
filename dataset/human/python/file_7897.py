module Main (main) where

import qualified Data.ByteString.Char8 as C8
import Data.Bool
import Data.List

main :: IO ()
main = do
  [s] <- readStrings
  print . showAnswer $ solve (s)

type Input  = (String)
type Output = Bool

solve :: Input -> Output
solve n = elem n $ permutations "abc"

showAnswer :: Output -> Answer
showAnswer = YesNo

-- utils
readStrings :: IO [String]
readStrings = map C8.unpack . C8.words <$> C8.getLine

data Answer
  = YesNo Bool
  | YESNO Bool
  | AB Bool
  | Number Int
  | String String
  | Compare Ordering
  | Compare2 Ordering

instance Show Answer where
  show (YesNo b)    = bool "No" "Yes" b
  show (YESNO b)    = bool "NO" "YES" b
  show (AB b)       = bool "B"  "A" b
  show (Number i)   = show i
  show (String s)   = s
  show (Compare o)  = ordering "<" "=" ">" o
  show (Compare2 o) = ordering "Right" "Balanced" "Left" o

ordering :: a -> a -> a -> Ordering -> a
ordering lt eq gt o = case o of
  LT -> lt
  EQ -> eq
  GT -> gt
