{-# LANGUAGE MultiParamTypeClasses,FlexibleContexts,FlexibleInstances,TypeSynonymInstances,BangPatterns,RankNTypes,TupleSections #-}
import Control.Monad
import Control.Monad.ST
import Control.Applicative
import Control.Arrow
import Debug.Trace
import Text.Printf

import Data.List
import Data.Int
import Data.Bits
import Data.Maybe
import Data.Monoid
import Data.Array.Unboxed
import Data.Array.ST
import Data.Array.Base
import Data.Function(on)
import Data.Tuple(swap)
import qualified Data.Map as M
import qualified Data.Set as S
import qualified Data.ByteString.Char8 as B

main :: IO ()
main = do
    (k,s) <- readIntPair
    print $ length $ do
        x <- [0..k]
        y <- [0..k]
        let z = s - x - y
        guard $ 0 <= z && z <= k
        return ()

-- IO
readInt :: B.ByteString -> Int
readInt = fromJust . fmap fst . B.readInt
readInts :: IO [Int]
readInts = map readInt . B.words <$> B.getLine
readIntPair :: IO (Int,Int)
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
readAllInts :: IO [[Int]]
readAllInts = map (map readInt . B.words) . B.lines <$> B.getContents
readLns :: Read a => IO [a]
readLns = map read . words <$> getLine

-- Utilities
l2p :: [a] -> (a,a)
l2p (a:b:_) = (a,b)
l2p _ = error "l2p: the input list is too short"
p2l :: (a,a) -> [a]
p2l (a,b) = [a,b]
itof :: Int -> Double
itof = fromIntegral
inf :: Int
inf = maxBound `div` 2

-- Monad
stepM_ :: Monad m => a -> (a -> Bool) -> (a -> a) -> (a -> m ()) -> m ()
stepM_ i0 judge incr step = sub i0 where 
    sub i | judge i = step i >> sub (incr i) 
          | otherwise = return ()
rep_ :: Monad m => Int -> (Int -> m ()) -> m ()
rep_ n = stepM_ 0 (<n) (+1)
thru :: Monad m => (v -> m ()) -> v -> m v
thru m v = m v >> return v
memoize :: (Monad m) => (k -> m (Maybe v)) -> (k -> v -> m ()) -> k -> m v -> m v
memoize getter setter key action = do
    mv <- getter key
    case mv of
        Just v -> return v
        Nothing -> action >>= thru (setter key)

-- Array
newUArray :: (MArray (STUArray s) e (ST s),Ix i) => 
             (i,i) -> e -> ST s (STUArray s i e)
newUArray = newArray
newBArray :: (Ix i) => (i,i) -> e -> ST s (STArray s i e)
newBArray = newArray
defaultArray :: (IArray a e,Ix i) => e -> (i,i) -> [(i,e)] -> a i e
defaultArray = accumArray $ curry snd
fromEdges :: Ix i => (i,i) -> [(i,e)] -> Array i [e]
fromEdges = accumArray (flip (:)) []
