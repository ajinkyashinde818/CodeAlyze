{-# LANGUAGE CPP #-}
module Main where

import qualified Data.Vector.Unboxed as V 
import qualified Data.Map.Strict as M
import Control.Monad
import qualified Data.ByteString.Char8 as BS
import Data.Maybe
import Data.Char
import qualified Data.List as L

dump :: (Show a) => a -> IO()
#if __GLASGOW_HASKELL__ >= 800
dump x = print x
#else
dump _ = pure ()
#endif

-- "101010" -> [1,0,1,0,1,0]
readToList :: String -> [Int]
readToList [] = []
readToList (x:xs) = read [x] : readToList xs

 
readInt :: BS.ByteString -> Int
readInt = fst . fromJust . BS.readInt

getInt :: IO Int
getInt = readInt <$> BS.getLine

-- "10 10 10" -> [10, 10, 10]
getlist :: IO [Int]
getlist = (fmap (read . BS.unpack) . BS.words) <$> BS.getLine

-- "10 10 10" -> [10, 10, 10]
getIntVec :: Int -> IO (V.Vector Int)
getIntVec n = V.unfoldrN n (BS.readInt . BS.dropWhile isSpace) <$> BS.getLine

readmat :: Int -> IO [[Int]]
readmat rows = replicateM rows getlist

newtype UF a = UF (M.Map a a) deriving (Show) -- Map node parent

makeuf :: Int -> UF Int
makeuf n = let m = M.fromList $ zip [0..n] [0..n]
                in UF m

union :: (Eq a, Ord a) => a -> a -> UF a -> UF a
union l r uf@(UF m) = let lp = find l uf
                          rp = find r uf
                      in if lp == rp
                         then uf
                         else if size l uf < size r uf
                              then UF $ M.update (const $ Just rp) lp m
                              else UF $ M.update (const $ Just lp) rp m

find :: (Eq a, Ord a) => a -> UF a -> a
find x uf@(UF m) = let px = m M.! x
                in if px == x
                   then px
                   else find px uf -- TODO 貼り直し

size :: (Eq a, Ord a) => a -> UF a -> Int
size x (UF m) = M.size $ M.filter (\par -> par==x) m

genbit :: Int -> [[Int]]
genbit 0 = []
genbit 1 = [[0],[1]]
genbit len = do
  x <- [0,1]
  map (x:) $ genbit (len-1)

base :: Int
base = 10 ^ 9 + 7

forn :: (Num a, Enum a, Monad m) => a -> (a -> m b) -> m [b]
forn x = forM [0..(x-1)]

count :: (Eq a) => a -> [a] -> Int
count y = length . filter (== y)

main :: IO()
main = do
  [a,b] <- getlist
  print $ (a `div` gcd a b) * b
