module Main where

import           Control.Monad
import           Data.List
import           Data.Ord
import           Data.List.Split
import           Data.Array.IO
import qualified Data.Vector            as V
import           Data.Maybe
import           Text.Printf

main :: IO ()
main = do
  n <- readLn :: IO Int
  as <- map read . words <$> getLine
  let abas = map abs as
  if (even . length . filter (< 0)) as
    then (print . sum) abas
    else print $ sum abas - (2 * minimum abas)
