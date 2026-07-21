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

readInt = ( readLn :: IO Int )
readInts = map ( read :: String -> Int ) . words <$> getLine

getList = map ( fst . fromJust . B.readInt ) . B.words <$> B.getLine

which a b f = if f then a else b
mp [ a, b ] = ( a, b )

main = do
	[ x, y ] <- map head . words <$> getLine
	putStrLn $ comp2s $ compare x y

comp2s LT = "<"
comp2s EQ = "="
comp2s GT = ">"
