{-# LANGUAGE FlexibleContexts #-}
{-# LANGUAGE GeneralizedNewtypeDeriving #-}
{-# LANGUAGE Rank2Types #-}
{-# LANGUAGE BinaryLiterals #-}
{-# LANGUAGE BangPatterns #-}

-- Default Imports

import Control.Monad
import Control.Monad.ST
import Control.Monad.Trans.Class

import qualified Control.Monad.Reader as Reader
import Control.Monad.Reader (Reader, ReaderT, runReader, runReaderT)

import qualified Data.Array.MArray as MArray
import qualified Data.Array.ST as STArray
import Data.Array.ST (STArray, STUArray, runSTArray, runSTUArray)
import Data.Ix (Ix)

import qualified Data.Bits as Bits
import Data.Bits ((.&.), (.|.))

import qualified Data.ByteString.Char8 as BS
import Data.ByteString.Char8 (ByteString)

import qualified Data.Char as Char
import qualified Data.List as List
import qualified Data.Map as Map
import Data.Map (Map)
import qualified Data.Maybe as Maybe
import qualified Data.Set as Set
import Data.Set (Set)

import qualified Data.Vector as Vector
import qualified Data.Vector.Generic as GVector
import qualified Data.Vector.Mutable as MVector
import Data.Vector.Mutable (STVector)
import qualified Data.Vector.Unboxed as UVector

import Numeric

import Debug.Trace
-- ----------

-- Custom Import Here


-- ----------

-- Default Definitions

type Vector = Vector.Vector
-- type GVector = GVector.Vector
type UVector = UVector.Vector

readIntToList :: ByteString -> [Int]
readIntToList = List.unfoldr (fmap (second $ BS.dropWhile Char.isSpace) . BS.readInt)

readToList :: Read a => ByteString -> [a]
readToList = List.unfoldr $ fmap (mapTaken . mapRemain) . span' (not . Char.isSpace)
	where
		mapTaken  = first $ read . BS.unpack
		mapRemain = second $ BS.dropWhile Char.isSpace
		span' pred s
			| BS.null taken = Nothing
			| otherwise     = Just (taken, remain')
			where
				(taken, remain) = BS.span pred s
				remain' = BS.dropWhile Char.isSpace remain

readToListN :: Read a => Int -> ByteString -> [a]
readToListN n = take n . readToList

readIntToVector :: ByteString -> Vector Int
readIntToVector = Vector.unfoldr (fmap stripRemain . BS.readInt)
	where stripRemain = second $ BS.dropWhile Char.isSpace

readIntToUVector :: ByteString -> UVector.Vector Int
readIntToUVector = UVector.unfoldr (fmap stripRemain . BS.readInt)
	where stripRemain = second $ BS.dropWhile Char.isSpace

readIntToVectorN :: Int -> ByteString -> Vector.Vector Int
readIntToVectorN n = Vector.unfoldrN n (fmap stripRemain . BS.readInt)
	where stripRemain = second $ BS.dropWhile Char.isSpace

readIntToUVectorN :: Int -> ByteString -> UVector.Vector Int
readIntToUVectorN n = UVector.unfoldrN n (fmap stripRemain . BS.readInt)
	where stripRemain = second $ BS.dropWhile Char.isSpace


first :: (a -> a') -> (a, b) -> (a', b)
first f (a, b) = (f a, b)

second :: (b -> b') -> (a, b) -> (a, b')
second f (a, b) = (a, f b)

average :: Fractional a => [a] -> a
average xs = sum xs / (fromIntegral . length) xs

-- ----------

charToInt :: Char -> Int
charToInt c = Char.ord c - Char.ord '0'

min' :: (Int, Int) -> (Int, Int) -> (Int, Int)
min' (a, b) (c, d) = (min a c, min b d)

ans :: (Int, Int) -> Int -> (Int, Int)
ans (a, b) n = min' (sameDig (a, b) n) (upDig (a, b) n)

sameDig :: (Int, Int) -> Int -> (Int, Int)
sameDig (a, b) n = (n + a, n + a + 1)

upDig :: (Int, Int) -> Int -> (Int, Int)
upDig (a, b) n = (10 - n + b, 10 - n + b - 1)

ans' :: [Int] -> Int
ans' = fst . List.foldl' ans (0, 1)

main :: IO ()
main = do
	ns <- map charToInt <$> getLine
	print $ ans' ns
