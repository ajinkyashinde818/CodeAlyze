{-# OPTIONS_GHC -O2 #-}
{-# LANGUAGE OverloadedStrings #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE LambdaCase #-}
{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE TypeApplications #-}

module Main where

import           Data.List
import           Control.Monad
import           Debug.Trace
import qualified Data.ByteString.Char8         as BC
import           Data.Maybe                     ( fromJust, fromMaybe )
import qualified Data.Set                      as S
import qualified Data.IntMap.Strict            as IM
import qualified Data.IntMap.Lazy            as IML
import qualified Data.Map.Strict               as M
import           Data.Char
import qualified Data.Array.IArray as A
import qualified Data.Array.Unboxed as UA
import Data.Bits
import Control.Monad.State.Strict
import qualified Data.Array.ST as STA
import qualified Data.Array.IO as IOA
import qualified Data.Array.MArray as MA
import Control.Monad.ST
import System.IO (stdin)
import Control.Arrow
import qualified Data.Vector as V
import qualified Data.Vector.Unboxed as UV
import qualified Data.Vector.Generic as GV
import qualified Data.Vector.Mutable as MV
import Data.Ix
import Data.Ord (Down(Down))
import qualified Data.Sequence as Seq
import Data.Foldable (toList)
import Data.Fixed
import Control.Lens

debug = False

ts :: Show a => a -> a
ts a = if debug then traceShowId a else a


readTuple2 :: IO (Int, Int)
readTuple2 = do
    [a, b] <- readInts
    return (a, b)

readTuple3 :: IO (Int, Int, Int)
readTuple3 = do
    [a, b, c] <- readInts
    return (a, b, c)


readInt :: IO Int
readInt = fst . fromJust . BC.readInt <$> BC.getLine

readInts :: IO [Int]
readInts = map (fst . fromJust . BC.readInt) . BC.words <$> BC.getLine

readIntV :: Int -> IO (UV.Vector Int)
readIntV n = GV.unfoldrN n (fmap (fmap BC.tail) . BC.readInt) <$> BC.getLine

readIntegersV :: Int -> IO (V.Vector Integer)
readIntegersV n = GV.unfoldrN n (fmap (fmap BC.tail) . BC.readInteger) <$> BC.getLine

readIntegers :: IO [Integer]
readIntegers = map (fst . fromJust . BC.readInteger) . BC.words <$> BC.getLine

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

primeFactors :: Int -> IM.IntMap Int
primeFactors 1 = IM.empty
primeFactors n = if r == 1 then mp else IM.insert r 1 mp
    where
    (mp, r) = foldl' go (IM.empty, n) [2..(ceiling $ sqrt $ fromIntegral n)]
    divCount divisor num acc = case num `divMod` divisor of
        (result, 0) -> divCount divisor result $ acc + 1
        (_, _) -> (acc, num)
    go (maps, num) divisor = case divCount divisor num 0 of
        (0, _) -> (maps, num)
        (m, num') ->  (IM.insert divisor m maps, num')

getCount :: Int -> Int
getCount 1 = 1
getCount n = go n 1 where
    go a i
      | a < i = i - 1
      | otherwise = go (a - i) $ i + 1

main :: IO ()
main = do
  n <- readInt
  let mp = ts $  IM.toList $ primeFactors $ n
      ans = sum $ getCount . snd <$> mp
  print ans
