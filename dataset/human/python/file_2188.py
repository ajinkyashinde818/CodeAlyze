{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE BangPatterns #-}

import Control.Applicative
import Control.Monad
import Control.Arrow
import Data.List
import Data.Maybe
import Data.Char
import qualified Data.ByteString.Char8 as B
import Text.Printf

import Debug.Trace

readInt = ( readLn :: IO Int )
readInts = map ( read :: String -> Int ) . words <$> getLine

getList = map ( fst . fromJust . B.readInt ) . B.words <$> B.getLine

which a b f = if f then a else b
mp [ a, b ] = ( a, b )

main = do
	[ d, g ] <- readInts
	[ p, c ] <- transpose <$> replicateM d readInts
	print $ fromJust $ solve [ 100, 200 .. ] p c [] g

solve _ [] [] rest g
	| g <= 0 = Just 0
	| otherwise = solve2 rest g
solve ( s : ss ) ( p : ps ) ( c : cs ) rest g = min' res1 res2
	where
		solve' = solve ss ps cs 
		res1 = ( 0 + ) <$> solve' ( ( s, p - 1 ) : rest ) g
		res2 = ( p + ) <$> solve' rest ( g - s * p - c )

solve2 [] g = Nothing
solve2 ( ( s, p ) : rest ) g
	| g <= 0 = Just 0
	| g <= s * p = Just $ ( g + s - 1 ) `div` s
	| otherwise = ( p + ) <$> solve2 rest ( g - s * p )

min' ( Just a ) Nothing = Just a
min' Nothing ( Just b ) = Just b
min' a b = min <$> a <*> b
