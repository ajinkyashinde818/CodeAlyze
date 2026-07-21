module Main where

import Data.List
import Data.Char (digitToInt)
import Control.Monad
import Debug.Trace
import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import qualified Data.Map.Strict as M
import qualified Data.Vector.Unboxed as V


readTuple2 :: IO (Int, Int)
readTuple2 = do
    [a, b] <- map (fst . fromJust . BC.readInt) . BC.words <$> BC.getLine
    return (a, b)

readTuple3 :: IO (Int, Int, Int)
readTuple3 = do
    [a, b, c] <- map (fst . fromJust . BC.readInt) . BC.words <$> BC.getLine
    return (a, b, c)

readInt :: IO Int
readInt = fst . fromJust . BC.readInt <$> BC.getLine

readInts :: IO [Int]
readInts = map (fst . fromJust . BC.readInt) . BC.words <$> BC.getLine

split :: (a -> Bool) -> [a] -> [[a]]
split f [] = []
split f as = let
    (fo, la) = span f as
    las = case la of
        [] -> []
        xs -> split f $ tail xs
    in
        case fo of
            [] -> las
            xs -> xs : las

fastPowerMod :: Int -> Int -> Int -> Int
fastPowerMod b 0 _ = 1
fastPowerMod b 1 modnum = b `mod` modnum
fastPowerMod b n modnum
            | even n = (fastPowerMod b (n `div` 2) modnum ^ 2) `mod` modnum
            | otherwise = (fastPowerMod b (n - 1) modnum * b) `mod` modnum


solve :: [Int] -> Int
solve ns = case findNum of
                1 -> -1
                _ -> break
    where
    inner (findNum, break) num
            | findNum == num = (findNum + 1, break)
            | otherwise = (findNum, break + 1)
    (findNum, break) = foldl' inner (1, 0) ns

main = do
    (a,b ) <- readTuple2
    print $ lcm a b
