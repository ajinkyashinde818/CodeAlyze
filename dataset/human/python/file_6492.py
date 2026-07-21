{-# LANGUAGE BangPatterns, OverloadedStrings #-}

import Control.Monad
import Data.List
import Data.Bits
import Debug.Trace
import Data.Maybe
import qualified Data.ByteString.Char8 as C

main :: IO ()
main = do
  s <- getLine
  [q] <- readInts
  queries <- replicateM q (words <$> getLine) 
  putStrLn $ solve s q queries

solve s q queries = translateQueriesSub False queries "" ""
  where
    translateQueriesSub rev (q:qs) hs ts = if head q == "1"
      then translateQueriesSub (not rev) qs hs ts
      else let f = head $ q !! 1 in let c = head $ q !! 2 in
        if (not rev && f == '1') || (rev && f == '2')
          then translateQueriesSub rev qs (c:hs) ts
          else translateQueriesSub rev qs hs (c:ts)
    translateQueriesSub rev [] hs ts =
      if rev
        then ts ++ (reverse s) ++ (reverse hs)
        else hs ++ s ++ (reverse ts)

-- 以下ライブラリ

readInts :: IO [Int]
readInts = map (fst . fromJust . C.readInt) . C.words <$> C.getLine

readNInts :: Int -> IO [[Int]]
readNInts = flip replicateM readInts

readIntegers :: IO [Integer]
readIntegers = map (fst . fromJust . C.readInteger) . C.words <$> C.getLine

readNIntegers :: Int -> IO [[Integer]]
readNIntegers = flip replicateM readIntegers

getNLns :: Int -> IO [String]
getNLns = flip replicateM getLine
