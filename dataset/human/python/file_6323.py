module Main where

import Data.List
import qualified Data.Map.Strict as Map
import Control.Monad
import Data.Ord

main = do
    print =<< solve <$> readInteger

readInteger :: IO Integer
readInteger = read <$> getLine

solve :: Integer -> Int
solve n = if  mod n 2 == 0 then countZeros n 10 else 0

countZeros :: Integer -> Integer -> Int
countZeros n m
    | n < m = 0
    | otherwise = (countZeros n $ m * 5) + (fromIntegral $ div n m)
