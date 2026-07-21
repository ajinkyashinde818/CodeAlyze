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

readInt = readLn :: IO Int
readInteger = readLn :: IO Integer
readInts = map ( fst . fromJust . B.readInt ) . B.words <$> B.getLine
readIntegers = map ( fst . fromJust . B.readInteger ) . B.words <$> B.getLine

which a b f = if f then a else b
mp [ a, b ] = ( a, b )

modifyArray a i f = writeArray a i =<< f <$> readArray a i

main = do
	[ k, n ] <- readInts
	as <- readInts
	let
		as' = as ++ [ head as + k ]
		diffs = zipWith (-) ( tail as' ) as'
	print $ k - maximum diffs
