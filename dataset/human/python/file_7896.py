{-# LANGUAGE OverloadedStrings #-}
{-# LANGUAGE OverloadedLists #-}

module Main where

import qualified Data.Text as T
import qualified Data.Text.IO as T
import Data.List

main :: IO ()
main = do
  input <- T.getLine
  putStrLn $ solve input

solve :: T.Text -> String
solve target = if target `elem` (map T.pack . permutations $ "abc")
  then "Yes"
  else "No"
