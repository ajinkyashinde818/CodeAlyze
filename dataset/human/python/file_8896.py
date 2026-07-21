module Main where

import           Control.Monad
import           Data.List
import           Data.Ord
import           Data.List.Split
import qualified Data.Vector.Unboxed as V

solve [] = "YES"
solve s
  | "maerd" `isPrefixOf` s = (solve . drop 5) s
  | "remaerd" `isPrefixOf` s = (solve . drop 7) s
  | "esare" `isPrefixOf` s = (solve . drop 5) s
  | "resare" `isPrefixOf` s = (solve . drop 6) s
  | otherwise = "NO"

main :: IO ()
main = do
  s <- reverse <$> getLine
  putStrLn $ solve s
