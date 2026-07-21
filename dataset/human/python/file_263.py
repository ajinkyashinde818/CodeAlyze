{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE BinaryLiterals #-}
{-# LANGUAGE MultiWayIf #-}
{-# LANGUAGE NumDecimals #-}
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE TupleSections #-}

import Control.Applicative
import Control.Arrow
import Control.Monad
import Control.Monad.ST

import Data.Char
import Data.List
import Data.Maybe

import qualified Data.ByteString.Char8 as B

import Data.Array.ST.Safe
import Data.STRef

import Debug.Trace
import Text.Printf

import Data.Int

readInt = readLn :: IO Int
readInts = map ( fst . fromJust . B.readInt ) . B.words <$> B.getLine
readIntegers = map ( fst . fromJust . B.readInteger ) . B.words <$> B.getLine
readNInts = readInt >>= flip replicateM readInt

which a b f = if f then a else b
mp [ a, b ] = ( a, b )

modifyArray a i f = writeArray a i =<< f <$> readArray a i

main = getLine >> readIntegers >>= print . solve . map fromIntegral

solve as = runST $ do
	let
		n = length as
	dp <- newArray ( ( 0, 0 ), ( n, 1 ) ) ( minBound `div` 2 :: Int64 ) :: ST s ( STUArray s ( Int, Int ) Int64 )
	writeArray dp ( 0, 0 ) 0
	forM_ ( zip [ 0 .. ] as ) $ \( i, a ) -> do
		forM_ [ 0, 1 ] $ \j -> do
			modifyArray dp ( i + 1, 0 ) =<< max . ( + ( if j == 0 then a else -a ) ) <$> readArray dp ( i, j )
			when ( i + 1 < n ) $ do
				modifyArray dp ( i + 1, 1 ) =<< max . ( + ( if j == 0 then -a else a ) ) <$> readArray dp ( i, j ) 
	readArray dp ( n, 0 )
