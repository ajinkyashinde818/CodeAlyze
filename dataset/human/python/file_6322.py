module Main where

import           Control.Monad
import           Debug.Trace
import qualified Data.Vector                   as V
import qualified Data.Vector.Mutable           as VM
import qualified Data.Vector.Unboxed           as VU
import qualified Data.Vector.Unboxed.Mutable   as VUM
import qualified Data.Vector.Generic.Mutable   as VGM
import           Data.List
import qualified Data.ByteString               as BS
import qualified Data.ByteString.Char8         as BSC8
import           Data.Char
import           Data.Maybe
import           Data.Ord
--import           Data.Vector.Algorithms.Search
import qualified Data.Array                    as A
import qualified Data.Array.Unboxed            as AU
import qualified Data.Array.IO                 as AIO
import qualified Data.Set                      as S

getVUIL :: IO (VU.Vector Int)
getVUIL = VU.unfoldr (BSC8.readInt . BSC8.dropWhile isSpace) <$> BSC8.getLine
readI :: BSC8.ByteString -> Int
readI = fst . fromJust . BSC8.readInt
readIL :: BSC8.ByteString -> [Int]
readIL = map readI . BSC8.words
readIT2 :: BSC8.ByteString -> (Int, Int)
readIT2 bs =
    let words = BSC8.words bs in (readI $ head words, readI $ last words)
getI :: IO Int
getI = readI <$> BSC8.getLine
getIL :: IO [Int]
getIL = readIL <$> BSC8.getLine
getIT2 :: IO (Int, Int)
getIT2 = readIT2 <$> BSC8.getLine

getNIS :: Int -> IO [(Int, BSC8.ByteString)]
getNIS 0 = return []
getNIS n = do
    [aFst, aSnd] <- BSC8.words <$> BSC8.getLine
    next         <- (getNIS (n - 1))
    return ((readI aFst, aSnd) : next)

il2ss :: [Int] -> String
il2ss = unwords . map show

il2sn :: [Int] -> String
il2sn = unlines . map show

modNum = 10 ^ 9 + 7
newtype Mint = M Int
instance Num Mint where
    (M a) + (M b) = M $ mod (a + b) modNum
    (M a) - (M b) = M (a - b)
    (M a) * (M b) = M $ mod (a * b) modNum
    fromInteger a = M $ mod (fromInteger a) modNum
    abs (M a) = M $ abs a
    signum (M a) = M $ signum a
instance Show Mint where
    show (M a) = show (mod a modNum)

int2MInt :: Int -> Mint
int2MInt a = M (mod a modNum)

main = do
    aN <- getI


    let ret = if odd aN then 0 else let test = div aN 2 in div5 test

    print ret

div5 x | x < 5     = 0
       | otherwise = let test = div x 5 in test + div5 test
