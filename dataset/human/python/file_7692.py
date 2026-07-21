{-# LANGUAGE FlexibleInstances    #-}
{-# LANGUAGE TypeSynonymInstances #-}

import           Control.Applicative
import           Control.DeepSeq
import           Control.Monad
import           Control.Monad.ST
import qualified Data.Array                    as A
import qualified Data.Array.IArray             as IA
import qualified Data.Array.IO                 as AI
import qualified Data.Array.MArray             as MA
import qualified Data.Array.ST                 as STA
import qualified Data.Array.Unboxed            as AU
import           Data.Bits
import qualified Data.ByteString.Char8         as BS
import           Data.Char
import qualified Data.Graph                    as G
import           Data.Int
import qualified Data.IntMap                   as IM
import qualified Data.IntSet                   as IS
import           Data.List
import qualified Data.Map.Strict               as M
import           Data.Maybe
import           Data.Ord
import qualified Data.Sequence                 as SQ
import qualified Data.Set                      as S
import           Data.Time
import qualified Data.Tree                     as T
import qualified Data.Vector                   as V
import qualified Data.Vector.Mutable           as VM
import qualified Data.Vector.Unboxed           as VU
import qualified Data.Vector.Unboxed.Mutable   as VUM

readInt :: IO [Int]
readInt = map (fst . fromJust . BS.readInt) . BS.words <$> BS.getLine

readInts :: Int -> IO [[Int]]
readInts n = replicateM n readInt

readInteger :: IO [Integer]
readInteger = map (fst . fromJust . BS.readInteger) . BS.words <$> BS.getLine

readIntegers :: Int -> IO [[Integer]]
readIntegers n = replicateM n readInteger

readString :: IO [String]
readString = map BS.unpack . BS.words <$> BS.getLine

readStrings :: Int -> IO [[String]]
readStrings n = replicateM n <$> readString

toPair :: [a] -> (a, a)
toPair [x, y] = (x, y)

count :: Eq a => a -> [a] -> Int
count a as = length $ filter (== a) as

put :: Show a => a -> IO ()
put = putStr . show

putList :: Show a => [a] -> IO ()
putList [n     ] = put n
putList (n : ns) = do
  put n
  putStr " "
  putList ns

putStrList :: [String] -> IO ()
putStrList [n     ] = putStr n
putStrList (n : ns) = do
  putStr n
  putStr " "
  putStrList ns

yesNoUpper b | b         = putStrLn "YES"
             | otherwise = putStrLn "NO"

yesNo b | b         = putStrLn "Yes"
        | otherwise = putStrLn "No"

main = do
  [x] <- readInt
  if x < 1200 then putStrLn "ABC" else putStrLn "ARC"
