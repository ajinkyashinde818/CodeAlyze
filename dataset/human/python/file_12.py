{-# LANGUAGE
  ScopedTypeVariables, BangPatterns, TupleSections, ExplicitForAll,
  LambdaCase, MultiWayIf, Unsafe, RecordWildCards, FlexibleContexts, CPP,
  NoMonomorphismRestriction, GADTs, PatternGuards,
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
import Data.Monoid
import Data.Functor
import System.IO
import Control.Arrow
import Control.Applicative
import Control.Monad
import Control.Monad.Primitive
import Control.Monad.State.Strict
import Control.Monad.ST
import Control.Monad.ST.Lazy (strictToLazyST, lazyToStrictST)
import qualified Control.Monad.ST.Lazy as STL
-- import Control.Monad.ST.Safe
import Control.DeepSeq
import qualified Data.ByteString.Char8 as BS
import qualified Data.ByteString.Lazy.Char8 as BSL
import qualified Data.ByteString.Builder as BSB
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
import qualified Data.Attoparsec.ByteString.Char8 as Atto
import GHC.Exts (build)

main :: IO ()
main = do
  [r,g,b,n] <- map readInt . words <$> getLine
  let lsR   = cycle (1 : replicate (r-1) 0)
      lsRG  = zipWith (+) lsR  (replicate g 0 ++ lsRG)
      lsRGB = zipWith (+) lsRG (replicate b 0 ++ lsRGB)
  print $ (!! n) $ evalVals $ lsRGB

#define IL(f) {-# INLINE f #-}; f

IL(evalVals) :: [a] -> [a]
evalVals xs = build $ \c n -> foldr (c $!) n xs
IL(forceVals) :: (NFData a) => [a] -> [a]
forceVals xs = build $ \c n -> foldr (c $!!) n xs

rInt :: StateT BSL.ByteString Maybe Int
IL(rInt) = StateT $ BSL.readInt . BSL.dropWhile (<'!')
rIntS :: StateT BS.ByteString Maybe Int
IL(rIntS) = StateT $ BS.readInt . BS.dropWhile (<'!')

unlessM, whenM :: (Monad m) => m Bool -> m () -> m ()
IL(whenM) = (. flip when) . (>>=)
IL(unlessM) = (. flip unless) . (>>=)

IL(wrA) = A.writeArray
IL(rdA) = A.readArray
IL(mdA) = \arr f !i -> do
  ai <- rdA arr i
  let fai = f ai 
  wrA arr i fai
  return (ai,fai)
{-# INLINE mdA' #-}
mdA' = \arr f !i -> do
  !ai <- rdA arr i
  let !fai = f ai
  wrA arr i fai
  return (ai,fai)
IL(swapA) = \arr !i !j -> do
  ai <- rdA arr i
  wrA arr i =<< rdA arr j
  wrA arr j ai

#define D(f,r,d)\
  IL(f) :: Integral a=>a->d; f=fromIntegral;\
  IL(r) :: String->d; r=read
#define C(f,r,g,h,d) D(f,r,d);\
  g,h :: RealFrac a=>a->d; IL(g)=floor; IL(h)=ceiling
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

#define N(f,g,h,a,m)\
  IL(f) :: forall e i s. (C(a,m)A.Ix i) => (i,i) -> e -> m (a i e);\
  f=A.newArray;\
  IL(g) :: forall e i s. (C(a,m)A.Ix i) => (i,i) -> m (a i e);\
  g=A.newArray_;\
  IL(h) :: forall e i s. (C(a,m)A.Ix i) => (i,i) -> [e] -> m (a i e);\
  h=A.newListArray
#define C(a,m)
N(newIOA,newIOA_,newIOAL,IOArray,IO)
N(newSTA,newSTA_,newSTAL,STArray s,ST s)
#undef C
#define C(a,m) MArray (a) e (m), 
N(newIOUA,newIOUA_,newIOUAL,IOUArray,IO)
N(newSTUA,newSTUA_,newSTUAL,STUArray s,ST s)
#undef C
#undef N

#undef IL
