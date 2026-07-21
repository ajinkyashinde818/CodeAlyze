{-# LANGUAGE BangPatterns #-}
import           Control.Exception           (assert)
import           Control.Monad
import           Control.Monad.Primitive
import qualified Control.Monad.ST            as ST
import qualified Data.Array.IO               as IO
import qualified Data.Array.ST               as ST
import qualified Data.Array.Unboxed          as A
import           Data.Bits
import qualified Data.ByteString.Char8       as BS
import           Data.Char
import           Data.Foldable
import           Data.List
import qualified Data.Map.Strict             as Map
import           Data.Maybe
import qualified Data.Sequence               as Seq
import qualified Data.Set                    as Set
import qualified Data.Vector                 as VB
import qualified Data.Vector.Mutable         as VBM
import qualified Data.Vector.Unboxed         as V
import qualified Data.Vector.Unboxed.Mutable as VM
import           Debug.Trace

readInt = fst . fromJust . BS.readInt
readIntList = map readInt . BS.words
getInt = readInt <$> BS.getLine
getIntList = readIntList <$> BS.getLine
getIntVec n = V.unfoldrN n (BS.readInt . BS.dropWhile isSpace) <$> BS.getLine

readInteger = fst . fromJust . BS.readInteger
readIntegerList = map readInteger . BS.words
getInteger = readInteger <$> BS.getLine
getIntegerList = readIntegerList <$> BS.getLine

inf :: Int
inf = 10^18

newUF :: PrimMonad m => Int -> m (VM.MVector (PrimState m) Int)
newUF n = do
  d <- VM.new n
  VM.set d (-1)
  return d

findUF :: PrimMonad m => VM.MVector (PrimState m) Int -> Int -> m Int
findUF d x = do
  dx <- VM.read d x
  if dx < 0
    then return x
    else do dx' <- findUF d dx
            VM.write d x dx'
            return dx'

uniteUF :: PrimMonad m => VM.MVector (PrimState m) Int -> Int -> Int -> m ()
uniteUF d x y = do
  x' <- findUF d x
  y' <- findUF d y
  when (x' /= y') $ do
    let (x'', y'') = if (x' <= y') then (x', y') else (y', x')
    dx <- VM.read d x''
    dy <- VM.read d y''
    VM.write d x'' (dx + dy)
    VM.write d y'' x''
  return ()

sameUF :: PrimMonad m => VM.MVector (PrimState m) Int -> Int -> Int -> m Bool
sameUF d x y = do
  fx <- findUF d x
  fy <- findUF d y
  return $ fx == fy

sizeUF :: PrimMonad m => VM.MVector (PrimState m) Int -> Int -> m Int
sizeUF d x = do
  fx <- findUF d x
  dfx <- VM.read d fx
  return (-dfx)

main = do
  [n, k] <- getIntList
  tas <- getIntList

  uf <- newUF (n+1)

  let as = V.fromList (0:tas)

      getDests :: Int -> [Int] -> IO (Int, V.Vector Int)
      getDests i res = do
        let d = as V.! i
            res' = (d:res)
        same <- sameUF uf 1 d
        if same
          then return (d, V.fromList (reverse res))
          else do uniteUF uf 1 d
                  getDests d res'

  (x, dests) <- getDests 1 [1]

  let Just idx = V.findIndex (== x) dests
      dests' = V.drop idx dests
      m = V.length dests'
      k' = k - idx
      j = k' `mod` m

      ans = if k <= idx
            then dests V.! k
            else dests' V.! j

  print ans
