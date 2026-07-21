module Main where

import Data.List
import Control.Monad
import Debug.Trace
import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust, catMaybes)
import qualified Data.Vector as V


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
readInts = do
    strs <- BC.words  <$> BC.getLine
    let bcList = catMaybes $ (BC.readInt <$> strs)
    pure $ fst <$> bcList

onOffLists :: Int -> Int -> [[Int]]
onOffLists i m = if i == m then [[0], [1]] else
    let
        prevLists = onOffLists (i + 1) m
    in
        [(1:), (0:)] <*> prevLists

checkVector :: [([Int], Int)] -> V.Vector Int -> Bool
checkVector ss v = all checker ss where
    checker (s,p) = ((foldr (\si acc -> (v V.! (si - 1) ) + acc ) 0 s) `mod` 2) == p

main = do
    [r, g, b, n] <- readInts
    let maxR =  n `div` r
    let ans = foldr (\rNum acc ->
            acc + foldr (\gNum acc -> 
                if (n - rNum * r - gNum * g) `mod` b == 0 then 1 + acc else 0 + acc
                ) 0 [0..(n - rNum * r) `div` g]
            ) 0 [0..maxR]
    print ans
