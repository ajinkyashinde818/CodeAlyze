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
readInts = map ( fst . fromJust . B.readInt ) . B.words <$> B.getLine
readNInts = readInt >>= flip replicateM readInt

which a b f = if f then a else b
mp [ a, b ] = ( a, b )

main = do
	[ k, s ] <- readInts
	print $ length $ do
		x <- [ 0 .. k ]
		y <- [ 0 .. k ]
		let
			z = s - x - y
		guard $ 0 <= z && z <= min k s
		return ()
