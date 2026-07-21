{-# LANGUAGE OverloadedStrings #-}
{-# LANGUAGE FlexibleContexts #-}
{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE TypeFamilies #-}
import           Data.Maybe
import           Data.Int
import           Data.List
import           Data.Char
-- import qualified Data.Vector.Unboxing as VU
import qualified Data.Vector as V
import qualified Data.Vector.Mutable as VM
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import qualified Data.ByteString.Char8 as BS
import           Data.List (scanl')
import           Data.IORef
import           Control.Monad
import           Control.Monad.ST
import           Control.Monad.State.Strict
import           Control.Applicative
import           Debug.Trace
import           Text.Printf


readInt = BS.readInt . BS.dropWhile isSpace
getVector f = VU.unfoldr f <$> BS.getLine
getIntVector = getVector readInt
getBSVector = getVector BS.uncons
getInt = readLn :: IO Int
getIntTuple = (\vec -> (vec VU.! 0, vec VU.! 1)) <$> getIntVector

main = do
  s <- getLine
  q <- getInt
  qq <- V.replicateM q $ getLine
  putStrLn . ans $ solve qq s

ans (b,s,first,end) = if b then sFinal  else reverse sFinal
  where
    sFinal = first ++ s ++ (reverse end)

solve qq s = V.foldl' check (True, s, [], []) qq
  where
    check (b,s',first, end) x
      | length x == 1 = operateT1 (b,s', first, end)
      | otherwise = operateT2 (b,s', first, end) (x !! 2) (x !! 4)


operateT1 (b,s,first,end) = (not b,s,first,end)

operateT2 :: (Bool,String,String,String) -> Char -> Char -> (Bool, String, String, String)
operateT2 (b,s,first,end) f c  = case f of '1' -> if b then operateF1 else operateF2
                                           '2' -> if b then operateF2 else operateF1
                                           _ -> undefined
  where
    -- operateF1 = (b, c `BS.cons` s)
    operateF1 = (b, s, c:first, end)
    -- operateF2 = (b, s `BS.snoc` c)
    operateF2 = (b, s, first, c:end)
