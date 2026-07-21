{-# OPTIONS_GHC -O3 #-}
{-# LANGUAGE ViewPatterns, ScopedTypeVariables #-}

import qualified Data.ByteString as B (getLine)
import qualified Data.ByteString.Char8 as C (readInt, words, unpack, reverse, dropWhile)
import qualified Data.Maybe as M (fromJust)
import Data.Char as C (isSpace)
import Data.List as L (elem)

readInt = fst . M.fromJust . C.readInt
rstrip = C.reverse . C.dropWhile C.isSpace . C.reverse

main = do
    (C.unpack . rstrip -> xxs) <- B.getLine
    putStrLn $ if '9' `elem` xxs then "Yes" else "No"
