module Main where

import Data.List
import Data.Char (digitToInt)
import Control.Monad
import Debug.Trace
import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import qualified Data.Map.Strict as M


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


main = do
    (n, r) <- readTuple2
    if n >= 10 then
        print r
    else
        print $ r + (100 * (10 - n))
