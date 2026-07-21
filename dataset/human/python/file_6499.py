{-# OPTIONS_GHC -O2 #-}
{-# LANGUAGE OverloadedStrings #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE LambdaCase #-}
{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE TupleSections #-}
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
-- import Control.Lens

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

readTuple4 :: IO (Int, Int, Int, Int)
readTuple4 = do
    [a, b, c, d] <- readInts
    return (a, b, c, d)

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

data Query = Reverse | AddFirst Char | AddLast Char

solve :: String -> [Query] -> String
solve first queries = if isReversed then reverse $ toList s else toList s where
  firstS = Seq.fromList first
  go (isReversed, s) Reverse = (not isReversed, s)
  go (False, s) (AddFirst c) = (False, c Seq.<| s)
  go (False, s) (AddLast c) = (False, s Seq.|> c)
  go (True, s) (AddFirst c) = (True, s Seq.|> c)
  go (True, s) (AddLast c) = (True, c Seq.<| s)
  (isReversed, s) = foldl' go (False, firstS) queries


main :: IO ()
main = do
  first <- getLine
  q <- readInt
  queries <- replicateM q $ do
    w <- BC.getLine
    if w == "1" then
      pure Reverse
    else do
      let 
        [_, a, b] = BC.words w
        c = head $ BC.unpack b
      pure $ if a == "1" then AddFirst c else AddLast c
  putStrLn $ solve first queries
