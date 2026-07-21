{-# LANGUAGE MultiWayIf #-}

module Main where

import           Control.Monad
import qualified Data.Array            as A
import qualified Data.Array.IO         as AIO
import qualified Data.Array.Unboxed    as AU
import qualified Data.ByteString       as BS
import qualified Data.ByteString.Char8 as BSC8
import           Data.Char
import           Data.List
import qualified Data.Map.Strict       as M
import           Data.Maybe
import           Data.Ord
import qualified Data.Set              as S
import qualified Data.Vector           as V

--import           Data.Vector.Algorithms.Search
import qualified Data.Vector.Mutable   as VM
import qualified Data.Vector.Unboxed   as VU

--import qualified Data.Vector.Unboxed.Mutable   as VUM
import           Debug.Trace

main = do
  vSS <- getVUS
  let ret = makePalin vSS
  putStrLn $ show $ test ret
  where
    test (Just x) = x
    test Nothing  = -1

makePalin :: VU.Vector Char -> Maybe Int
makePalin x
  | VU.empty == x = return 0
  | VU.length x == 1 = return 0
  | otherwise =
    let headx = VU.head x
        lastx = VU.last x
     in if | headx == 'x' && lastx == 'x' -> makePalin (VU.tail $ VU.init x)
           | headx == 'x' -> makePalin (VU.tail x) >>= return . (+ 1)
           | lastx == 'x' -> makePalin (VU.init x) >>= return . (+ 1)
           | headx == lastx -> makePalin (VU.tail $ VU.init x)
           | otherwise -> Nothing

myFilter :: (a -> Bool) -> [a] -> ([a], [a])
myFilter _pred [] = ([], [])
myFilter pred (x:xs)
  | pred x =
    let (l, r) = myFilter pred xs
     in (x : l, r)
  | otherwise =
    let (l, r) = myFilter pred xs
     in (l, x : r)

fromJustList :: Maybe [a] -> [a]
fromJustList (Just x) = x
fromJustList Nothing  = []

fromJustInt :: Maybe Int -> Int
fromJustInt (Just x) = x
fromJustInt Nothing  = 0

getVUI :: IO (VU.Vector Int)
getVUI = VU.unfoldr (BSC8.readInt . BSC8.dropWhile isSpace) <$> BSC8.getLine

getRepVUI :: Int -> IO (VU.Vector Int)
getRepVUI n = VU.unfoldr (BSC8.readInt . BSC8.dropWhile isSpace) . BSC8.unlines <$> replicateM n BSC8.getLine

getVS :: IO (V.Vector Char)
getVS = V.fromList <$> getLine

getVUS :: IO (VU.Vector Char)
getVUS = VU.fromList <$> getLine

readI :: BSC8.ByteString -> Int
readI = fst . fromJust . BSC8.readInt

readIL :: BSC8.ByteString -> [Int]
readIL = map readI . BSC8.words

readIT2 :: BSC8.ByteString -> (Int, Int)
readIT2 bs =
  let words = BSC8.words bs
   in (readI $ head words, readI $ last words)

getI :: IO Int
getI = readI <$> BSC8.getLine

getIL :: IO [Int]
getIL = readIL <$> BSC8.getLine

get2IT :: IO (Int, Int)
get2IT = readIT2 <$> BSC8.getLine

getNIS :: Int -> IO [(Int, BSC8.ByteString)]
getNIS 0 = return []
getNIS n = do
  [aFst, aSnd] <- BSC8.words <$> BSC8.getLine
  next <- getNIS (n - 1)
  return ((readI aFst, aSnd) : next)

il2ss :: [Int] -> String
il2ss = unwords . map show

il2sn :: [Int] -> String
il2sn = unlines . map show

--modNum = 10 ^ 9 + 7
modulus = 2019

newtype MInt =
  M Int

instance Num MInt where
  (M a) + (M b) = M $ mod (a + b) modulus
  (M a) - (M b) = M (a - b)
  (M a) * (M b) = M $ mod (a * b) modulus
  fromInteger a = M $ mod (fromInteger a) modulus
  abs (M a) = M $ abs a
  signum (M a) = M $ signum a

instance Show MInt where
  show (M a) = show (mod a modulus)

int2MInt :: Int -> MInt
int2MInt a = M (mod a modulus)

mInt2Int :: MInt -> Int
mInt2Int (M a) = a

factsMod :: V.Vector MInt
factsMod = V.scanl (\acc x -> M x * acc) 1 $ V.generate 200000 (+ 1)

factMod :: Int -> MInt
factMod = (factsMod V.!)

powMod :: MInt -> Int -> MInt
powMod n k = n ^ k

invMod :: MInt -> MInt
invMod (M 0) = error "inverse of 0"
invMod x     = powMod x (modulus - 2)

combMod :: Int -> Int -> MInt
combMod n k
  | n < 0 || k < 0 || k > n = 0
  | otherwise = factMod n * invMod (factMod (n - k)) * invMod (factMod k)

comb :: Int -> Int -> Int
comb n k
  | n < 0 || k < 0 || k > n = 0
  | otherwise = div (div (fact n) (fact (n - k))) (fact k)

primes :: V.Vector MInt
primes = V.scanl (\acc x -> M x * acc) 1 $ V.generate 200000 (+ 1)

fact :: Int -> Int
fact 0 = 1
fact n
  | n > 0 = n * fact (n - 1)

knappsackMaxVal :: AIO.IOArray (Int, Int) Int -> VU.Vector Int -> VU.Vector Int -> Int -> IO Int
knappsackMaxVal dp volumeVec valueVec dpSize = do
  mapM_
    (\i ->
       mapM_
         (\v -> do
            let volume = volumeVec VU.! i
                value = valueVec VU.! i
            newdp <-
              if v < volume
                then AIO.readArray dp (i, v)
                else do
                  dpIVm <- AIO.readArray dp (i, v - volume)
                  dpIV <- AIO.readArray dp (i, v)
                  return (max (dpIVm + value) dpIV)
            AIO.writeArray dp (i + 1, v) newdp)
         [0 .. dpSize])
    [0 .. VU.length volumeVec - 1]
  AIO.readArray dp (VU.length volumeVec, dpSize)

knappsackMinVol :: AIO.IOArray (Int, Int) Int -> VU.Vector Int -> VU.Vector Int -> Int -> Int -> IO Int
knappsackMinVol dp volumeVec valueVec dpSize maxVolume = do
  mapM_
    (\i ->
       mapM_
         (\v -> do
            let volume = volumeVec VU.! i
                value = valueVec VU.! i
            newdp <-
              if (v + value) > dpSize
                then AIO.readArray dp (i, v)
                else do
                  dpIVm <- AIO.readArray dp (i, v + value)
                  dpIV <- AIO.readArray dp (i, v)
                  return (min (dpIVm - volume) dpIV)
            AIO.writeArray dp (i + 1, v) newdp)
         (reverse [0 .. dpSize]))
    [0 .. VU.length valueVec - 1]
  foldM
    (\acc x -> do
       num <- AIO.readArray dp (VU.length volumeVec, x)
       return $
         if num <= maxVolume
           then x
           else acc)
    0
    [0 .. dpSize]
