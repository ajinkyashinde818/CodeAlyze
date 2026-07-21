{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE MultiWayIf #-}
{-# LANGUAGE TypeFamilies #-}

module Main where

import Control.Monad
import Control.Monad.Extra
import qualified Data.Array as A
import qualified Data.Array.IO as AIO
import qualified Data.Array.Unboxed as AU
import Data.Bits
import Data.Bool
import qualified Data.ByteString as BS
import qualified Data.ByteString.Char8 as BSC8
import Data.Char
import Data.Either
import Data.Function
import qualified Data.Graph.Inductive.Graph as G
import qualified Data.Graph.Inductive.PatriciaTree as G
import qualified Data.Heap as H
import Data.Int
import Data.List
import qualified Data.Map.Strict as M
import Data.Maybe
import Data.Ord
import Data.Semigroup
import qualified Data.Sequence as SQ
import qualified Data.Set as S
import Data.Time
import Data.Tuple
import qualified Data.Vector as V
import Data.Vector.Algorithms.Search
import qualified Data.Vector.Mutable as VM
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import qualified Data.Vector.Unboxing as VUG
import qualified Data.Vector.Unboxing.Mutable as VUGM
import Debug.Trace
import GHC.Base
import GHC.Stack

main :: IO ()
main = do
  --aN       <- getI
  --[aA, aB] <- getIL
  --aS       <- getLine
  [aN, aK] <- getIL
  aA <- getVUI
  let dTarget = VU.map (\a -> (pred a, Last a)) aA :: VU.Vector (Int, Last Int)
  let ans = getLast $snd $getDoubling (stimes aK $ Doubling dTarget) VU.! 0

  print ans

  return ()

--すいませんあまりにかっこいいのでパクりました。orz

newtype Doubling a = Doubling {getDoubling :: VU.Vector (Int, a)} deriving (Show)

instance (Semigroup a, VU.Unbox a) => Semigroup (Doubling a) where
  (Doubling next0) <> (Doubling next1) =
    Doubling $
      VU.map
        ( \(nv, x) ->
            let (nnv, y) = next1 VU.! nv
                !z = x <> y
             in (nnv, z)
        )
        next0

--雑多系
t :: Int -> (Int, Int)
t x = (x, 1)

i def f t = bool t def $ f t

shiftRCnt k = shiftRCntP k 1

shiftRCntP k c =
  let nk = shiftR k 1
   in if nk == 0
        then c
        else shiftRCntP nk (c + 1)

myVUmap f vu =
  if vu == VU.empty
    then VU.empty
    else
      VU.unfoldr
        ( \x ->
            let ret = f $ VU.head x
                tailx = VU.tail x
             in if x == VU.empty
                  then Nothing
                  else
                    if isLeft ret
                      then Just (either id id ret, tailx)
                      else Just (either id id ret, VU.empty)
        )
        vu

myVUmapM f vu =
  if vu == VU.empty
    then return VU.empty
    else
      VU.unfoldrM
        ( \x -> do
            ret <- f $ VU.head x
            let tailx = VU.tail x
            if x == VU.empty
              then return Nothing
              else
                if isLeft ret
                  then return $ Just (either id id ret, tailx)
                  else return $ Just (either id id ret, VU.empty)
        )
        vu

myVUmapM_ f vu =
  if vu == VU.empty
    then return ()
    else do
      ret1 <-
        VU.unfoldrM
          ( \x -> do
              ret2 <- f $ VU.head x
              let tailx = VU.tail x
              if x == VU.empty
                then return Nothing
                else
                  if isLeft ret2
                    then return $ Just (either id id ret2, tailx)
                    else return $ Just (either id id ret2, VU.empty)
          )
          vu
      return ()

myVUfor vu f = myVUmap f vu

myVUforM vu f = myVUmapM f vu

myVUforM_ vu f = myVUmapM_ f vu

myVUfoldl f acc vu =
  if vu == VU.empty
    then return acc
    else do
      let ret = f acc (VU.head vu)
      if isLeft ret
        then myVUfoldl f (either id id ret) (VU.tail vu)
        else return $ either id id ret

myVUfoldr f acc vu =
  if vu == VU.empty
    then return acc
    else do
      let ret = f acc (VU.last vu)
      if isLeft ret
        then myVUfoldr f (either id id ret) (VU.init vu)
        else return $ either id id ret

myVUfoldM f acc vu =
  if vu == VU.empty
    then return acc
    else do
      ret <- f acc (VU.head vu)
      if isLeft ret
        then myVUfoldM f (either id id ret) (VU.tail vu)
        else return $ either id id ret

--周りのマス
aroundSquare y x h w =
  VU.concatMap
    ( \a ->
        VU.mapMaybe
          ( \b ->
              let ya = y + a
                  xb = x + b
               in if abs a + abs b == 1
                    then
                      if ya < 0 || ya >= h || xb < 0 || xb >= w
                        then Nothing
                        else Just (ya, xb)
                    else Nothing
          )
          $ VU.enumFromN (-1) 3
    )
    $ VU.enumFromN (-1) 3

--入力系
splitReadBSC8 :: BSC8.ByteString -> [Int]
splitReadBSC8 bs =
  let (bs1, newBs) = BSC8.splitAt 1 bs
   in if newBs == BSC8.empty
        then [test $ BSC8.readInt bs1]
        else test (BSC8.readInt bs1) : splitReadBSC8 newBs
  where
    test (Just (i, _)) = i

read2DimChar :: VM.IOVector (VUM.IOVector Char) -> Int -> Int -> IO Char
read2DimChar vec y x = do
  vecY <- VM.read vec y
  VUM.read vecY x

write2DimChar :: VM.IOVector (VUM.IOVector Char) -> Int -> Int -> Char -> IO ()
write2DimChar vec y x t = do
  vecY <- VM.read vec y
  VUM.write vecY x t

readTwoDimVec :: VM.IOVector (VUM.IOVector Int) -> Int -> Int -> IO Int
readTwoDimVec vec y x = do
  vecY <- VM.read vec y
  VUM.read vecY x

writeTwoDimVec :: VM.IOVector (VUM.IOVector Int) -> Int -> Int -> Int -> IO ()
writeTwoDimVec vec y x t = do
  vecY <- VM.read vec y
  VUM.write vecY x t

getVUI :: IO (VU.Vector Int)
getVUI = VU.unfoldr (BSC8.readInt . BSC8.dropWhile isSpace) <$> BSC8.getLine

getRepVUI :: Int -> IO (VU.Vector Int)
getRepVUI n =
  VU.unfoldr (BSC8.readInt . BSC8.dropWhile isSpace) . BSC8.unlines
    <$> replicateM n BSC8.getLine

getVS :: IO (V.Vector Char)
getVS = V.fromList <$> getLine

getVUC :: IO (VU.Vector Char)
getVUC = VU.fromList <$> getLine

readI :: BSC8.ByteString -> Int
readI = fst . fromJust . BSC8.readInt

readInteger :: BSC8.ByteString -> Integer
readInteger = fst . fromJust . BSC8.readInteger

readIL :: BSC8.ByteString -> [Int]
readIL = map readI . BSC8.words

readIT2 :: BSC8.ByteString -> (Int, Int)
readIT2 bs =
  let words = BSC8.words bs
   in (readI $ head words, readI $ last words)

readIT3 :: BSC8.ByteString -> (Int, Int, Int)
readIT3 bs =
  let words = BSC8.words bs
   in (readI $ head words, readI $ words !! 1, readI $ words !! 2)

getI :: IO Int
getI = readI <$> BSC8.getLine

getInteger :: IO Integer
getInteger = readInteger <$> BSC8.getLine

getIL :: IO [Int]
getIL = readIL <$> BSC8.getLine

getIT2 :: IO (Int, Int)
getIT2 = readIT2 <$> BSC8.getLine

getIT3 :: IO (Int, Int, Int)
getIT3 = readIT3 <$> BSC8.getLine

getIT2Order :: IO (Int, Int)
getIT2Order =
  getIL
    >>= \x@[xz, xo] ->
      if xz > xo
        then return (xo, xz)
        else return (xz, xo)

getNIS :: Int -> IO [(Int, BSC8.ByteString)]
getNIS 0 = return []
getNIS n = do
  [aFst, aSnd] <- BSC8.words <$> BSC8.getLine
  next <- getNIS (n - 1)
  return ((readI aFst, aSnd) : next)

il2Words :: [Int] -> String
il2Words = unwords . map show

il2Lines :: [Int] -> String
il2Lines = unlines . map show
