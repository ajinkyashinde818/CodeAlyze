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

import Data.Vector.Unboxed ((!))

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
modIntDivisor :: Int
modIntDivisor = floor 1e9 + 7

extGcd :: Integral a => Int -> Int -> (Int, Int)
extGcd a 0 = (1, 0)
extGcd a b = (x, y)
	where
		(x', y') = extGcd b (a `mod` b)
		x = y'
		y = x' - a `div` b * y'

newtype ModInt = ModInt { unModInt :: Int } deriving (Eq, Show)

modInt :: Int -> ModInt
modInt x = ModInt $ (x `mod` modIntDivisor + modIntDivisor) `mod` modIntDivisor

modIntMap2 :: (Int -> Int -> Int) -> ModInt -> ModInt -> ModInt
modIntMap2 f a b = modInt $ f (unModInt a) (unModInt b)

instance Num ModInt where
	(+) = modIntMap2 (+)
	(-) = modIntMap2 (-)
	(*) = modIntMap2 (*)
	abs = id
	signum _ = 1
	fromInteger = modInt . fromInteger

instance Enum ModInt where
	toEnum = modInt
	fromEnum = unModInt

minv :: ModInt -> ModInt
minv a = modInt y
	where (_, y) = extGcd modIntDivisor $ unModInt a

mdiv :: ModInt -> ModInt -> ModInt
mdiv x y = x * minv y

mperm :: ModInt -> ModInt -> ModInt
mperm _ 0 = 1
mperm n r = product [(n - r + 1)..n]

mcomb :: ModInt -> ModInt -> ModInt
mcomb n r = mperm n r `mdiv` product [1..r]


factorial :: (Integral a, Num b) => a -> b
factorial 1 = 1
factorial n = fromIntegral n * factorial (n - 1)

factoList :: (Integral a, Num b) => a -> [b]
factoList 0 = []
factoList 1 = [1]
factoList n = (fromIntegral n * head prev) : prev
	where prev = factoList (n - 1)

factoVector :: (Integral a, Num b) => a -> Vector b
factoVector = Vector.fromList . factoList

diffs :: Num a => [a] -> [a]
diffs ns = zipWith (flip (-)) ns $ tail ns

coefs' :: ModInt -> Int -> Int -> [ModInt]
coefs' fn m n
	| m == 0    = [fn]
	| otherwise = (fn `mdiv` ModInt (m + 1) + head prev) : prev
	where prev = coefs' fn (m - 1) n

coefs :: Int -> [ModInt]
coefs n = reverse $ coefs' (factorial n) (n - 1) n

slime :: [ModInt] -> ModInt
slime xs = sum $ zipWith (*) ds (coefs n)
	where
		n = length xs - 1
		ds = diffs xs

main :: IO ()
main = do
	n <- readLn
	xs <- map ModInt . readToListN n <$> BS.getLine
	print . unModInt $ slime xs
