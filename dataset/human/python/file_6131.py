{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE ExplicitForAll #-}
{-# LANGUAGE LambdaCase #-}
{-# LANGUAGE MultiWayIf #-}
{-# LANGUAGE Unsafe #-}
{-# LANGUAGE RecordWildCards #-}
{-# LANGUAGE FlexibleContexts #-}

import Data.Bits
import Data.List
import qualified Data.ByteString.Char8 as BS
import qualified Data.ByteString.Lazy.Char8 as BSL
import Data.IntMap.Strict (IntMap)
import qualified Data.IntMap.Strict as IMS
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
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import Control.Monad
import Control.Monad.ST
-- import Control.Monad.ST.Safe
import Control.Applicative
import Data.Maybe
import Data.Tuple
import Data.Ord
import Control.Monad.State.Strict
import Data.Int
import System.IO
import Data.Function
import Control.Monad.Primitive
import qualified Data.Vector.Primitive.Mutable as VPM
import qualified Data.Vector.Generic.Mutable as VGM
import Data.STRef

main :: IO ()
main = do
  [a,b,c] <- map read . words <$> getLine :: IO [Int64]
  let eatablePoisonous = c `min` (a+b+1)
  print $ eatablePoisonous + b
