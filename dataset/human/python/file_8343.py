{-# LANGUAGE OverloadedStrings #-}
module Main where

import           Data.List
import           Control.Monad
import           Debug.Trace
import qualified Data.ByteString.Char8         as BC
import           Data.Maybe                     ( fromJust )
import qualified Data.Set                      as S
import qualified Data.IntMap.Strict            as IM
import           Data.Char


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
split f as =
    let (fo, la) = span f as
        las      = case la of
            [] -> []
            xs -> split f $ tail xs
    in  case fo of
            [] -> las
            xs -> xs : las

distance :: Int -> Int -> Int -> Int
distance k from to =
        if from > to then to + k - from
        else to - from

distances :: Int -> [Int] -> [Int]
distances k (d:ds) = let
    firstList = d:ds
    latterList = ds ++ [d]
    in
    zipWith (distance k) firstList latterList

main = do
    (k, n) <- readTuple2
    ds <- readInts
    let nds = distances k ds
    print $ k - maximum nds
