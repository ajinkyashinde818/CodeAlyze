{-# OPTIONS_GHC -O2 #-}
{-# LANGUAGE OverloadedStrings #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE LambdaCase #-}
{-# LANGUAGE BangPatterns #-}
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
import Data.Ix



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

data Hand = R | P | S deriving (Show, Eq,Ord, Ix)

winHand :: Char -> Hand
winHand 'r' = P
winHand 'p' = S
winHand 's' = R


main = do
    (k, s) <- readTuple2
    let ans = length $ do
            x <- [0..min k s]
            y <- [0..(s - x)]
            let z = s - x - y
            guard $ x <= k && y <= k && z <= k
            pure ()
    print ans
