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
  (k,n) <- getIntTuple
  as <- getIntVector
  print $ ans k n as

ans :: Int -> Int -> VU.Vector Int -> Int
ans k n as = k - (loop n 0)
  where
    loop 0 maximumPath = maximumPath
    loop n maximumPath = loop (n-1) $ max maximumPath $ lengthPath n
    lengthPath 1 = k - as VU.! (n-1) + as VU.! 0
    lengthPath n = as VU.! (n-1) - as VU.! (n-2)
