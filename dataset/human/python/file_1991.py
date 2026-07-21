{-# LANGUAGE
  ScopedTypeVariables, BangPatterns, TupleSections, ExplicitForAll,
  LambdaCase, MultiWayIf, Unsafe, RecordWildCards, FlexibleContexts, CPP,
  NoMonomorphismRestriction, GADTs,
  RankNTypes, EmptyDataDecls, EmptyCase, ViewPatterns #-}


import Data.Bits
import Data.List
import Data.Maybe
import Data.Tuple
import Data.Ord
import Data.Int
import Data.Word
import Data.Char
import Data.Function
import Data.STRef
import Data.IORef
import System.IO
import Control.Applicative
import Control.Monad
import Control.Monad.Primitive
import Control.Monad.State.Strict
import Control.Monad.ST
-- import Control.Monad.ST.Safe
import Control.DeepSeq
import qualified Data.ByteString.Char8 as BS
import qualified Data.ByteString.Lazy.Char8 as BSL
import Data.IntMap (IntMap)
import qualified Data.IntMap.Strict as IMS
import qualified Data.IntMap.Lazy as IML
import Data.IntSet (IntSet)
import qualified Data.IntSet as IS
import qualified Data.Sequence as Seq
import Data.Sequence (Seq)
import qualified Data.Array.IArray as A
import qualified Data.Array.MArray.Safe as A
import qualified Data.Array.MArray as A
import Data.Array (Array)
import Data.Array.Unboxed (UArray)
import Data.Array.IArray (IArray)
import Data.Array.MArray.Safe (MArray)
import Data.Array.IO.Safe (IOArray, IOUArray)
import Data.Array.ST.Safe (STArray, STUArray, runSTArray, runSTUArray)
import qualified Data.Vector as V
import qualified Data.Vector.Mutable as VM
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import qualified Data.Vector.Primitive as VP
import qualified Data.Vector.Primitive.Mutable as VPM
import qualified Data.Vector.Generic as VG
import qualified Data.Vector.Generic.Mutable as VGM

-- import Control.Monad.ST.Unsafe

main :: IO ()
main = do
  n <- readInt <$> getLine
  s <- VU.map toNum . VU.unfoldrN n BS.uncons <$> BS.getLine
  let cnts = VU.accumulate (+) (VU.replicate 26 0) (VU.zip s (VU.replicate n 1))
  print $ subtract 1 $ VU.foldl' mult 1 $ VU.map (+1) cnts

toNum :: Char -> Int
toNum x = fromEnum x - fromEnum 'a'

mult x y = x * y `mod` modulus

modulus = 10^9 + 7 :: Int

rInt :: StateT BSL.ByteString Maybe Int
rInt = StateT $ BSL.readInt . BSL.dropWhile (<'!')
rIntS :: StateT BS.ByteString Maybe Int
rIntS = StateT $ BS.readInt . BS.dropWhile (<'!')


#define D(f,r,d) f::Integral a=>a->d;f=fromIntegral;r::String->d;r=read
#define C(f,r,g,h,d) D(f,r,d);g,h::RealFrac a=>a->d;g=floor;h=ceiling
C(_toInteger_,readInteger,floorInteger,ceilInteger,Integer)
C(toInt,readInt,floorInt,ceilInt,Int)
C(toI8,readI8,floorI8,ceilI8,Int8)
C(toI16,readI16,floorI16,ceilI16,Int16)
C(toI32,readI32,floorI32,ceilI32,Int32)
C(toI64,readI64,floorI64,ceilI64,Int64)
C(toWord,readWord,floorWord,ceilWord,Word)
C(toW8,readW8,floorW8,ceilW8,Word8)
C(toW16,readW16,floorW16,ceilW16,Word16)
C(toW32,readW32,floorW32,ceilW32,Word32)
C(toW64,readW64,floorW64,ceilW64,Word64)
D(toDouble,readDouble,Double)
D(toFloat,readFloat,Float)
#undef D
#undef C

{-# INLINE wrA #-}
wrA = A.writeArray
{-# INLINE rdA #-}
rdA = A.readArray
{-# INLINE mdA #-}
mdA arr f i = do
  ai <- rdA arr i
  let fai = f ai 
  wrA arr i fai
  return (ai,fai)
{-# INLINE mdA' #-}
mdA' arr f i = do
  !ai <- rdA arr i
  let !fai = f ai
  wrA arr i fai
  return (ai,fai)
{-# INLINE swapA #-}
swapA arr i j = do
  ai <- rdA arr i
  wrA arr i =<< rdA arr j
  wrA arr j ai

#define N(f,g,a,m)\
  f :: forall e i s. (C(a,m)A.Ix i) => (i,i) -> e -> m (a i e); f=A.newArray;\
  g :: forall e i s. (C(a,m)A.Ix i) => (i,i) -> m (a i e); g=A.newArray_
#define C(a,m)
N(newIOA,newIOA_,IOArray,IO)
N(newSTA,newSTA_,STArray s,ST s)
#undef C
#define C(a,m) MArray (a) e (m), 
N(newIOUA,newIOUA_,IOUArray,IO)
N(newSTUA,newSTUA_,STUArray s,ST s)
#undef C
#undef N
