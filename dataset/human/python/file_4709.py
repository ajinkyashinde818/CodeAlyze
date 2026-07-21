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
	s <- sort <$> getLine
	t <- reverse . sort <$> getLine
	putStrLn $ which "Yes" "No" $ s < t
