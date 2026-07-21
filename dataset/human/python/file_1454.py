module Main where

import           Control.Monad
import           Debug.Trace
import qualified Data.Vector                   as V
import qualified Data.Vector.Mutable           as VM
import qualified Data.Vector.Unboxed           as VU
import qualified Data.Vector.Unboxed.Mutable   as VUM
import           Data.List
import qualified Data.ByteString               as BS
import qualified Data.ByteString.Char8         as BSC8
import           Data.Char
import           Data.Maybe
import           Data.Ord
--import           Data.Vector.Algorithms.Search
import qualified Data.Array                    as A
import qualified Data.Array.Unboxed            as AU
import qualified Data.Array.IO                 as AIO
import qualified Data.Set                      as S
import qualified Data.Map.Strict               as M

main = do
    [aN, aM] <- getIL
    aA       <- replicateM aN getLine
    aB       <- replicateM aM getLine

    let ret = scanPic aA aB
    putStrLn $ if ret then "Yes" else "No"


scanPic :: [String] -> [String] -> Bool
scanPic a b = scanPic' a b (length a) (length b) 0 0 0 0
scanPic'
    :: [String] -> [String] -> Int -> Int -> Int -> Int -> Int -> Int -> Bool
scanPic' a b la lb ny nx my mx
    | a !! (ny + my) !! (nx + mx) == b !! my !! mx = if mx == (lb - 1)
        then (my == (lb - 1)) || scanPic' a b la lb ny nx (my + 1) 0
        else scanPic' a b la lb ny nx my (mx + 1)
    | nx == (la - lb) = ny /= (la - lb) && scanPic' a b la lb (ny + 1) 0 0 0
    | otherwise = scanPic' a b la lb ny (nx + 1) 0 0





fromJustInt :: Maybe Int -> Int
fromJustInt (Just x) = x
fromJustInt Nothing  = 0

getVUI :: IO (VU.Vector Int)
getVUI = VU.unfoldr (BSC8.readInt . BSC8.dropWhile isSpace) <$> BSC8.getLine
readI :: BSC8.ByteString -> Int
readI = fst . fromJust . BSC8.readInt
readIL :: BSC8.ByteString -> [Int]
readIL = map readI . BSC8.words
readIT2 :: BSC8.ByteString -> (Int, Int)
readIT2 bs =
    let words = BSC8.words bs in (readI $ head words, readI $ last words)
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
    next         <- (getNIS (n - 1))
    return ((readI aFst, aSnd) : next)

il2ss :: [Int] -> String
il2ss = unwords . map show

il2sn :: [Int] -> String
il2sn = unlines . map show

modNum = 10 ^ 9 + 7
newtype Mint = M Int
instance Num Mint where
    (M a) + (M b) = M $ mod (a + b) modNum
    (M a) - (M b) = M (a - b)
    (M a) * (M b) = M $ mod (a * b) modNum
    fromInteger a = M $ mod (fromInteger a) modNum
    abs (M a) = M $ abs a
    signum (M a) = M $ signum a
instance Show Mint where
    show (M a) = show (mod a modNum)

int2MInt :: Int -> Mint
int2MInt a = M (mod a modNum)

knappsackMaxVal
    :: AIO.IOArray (Int, Int) Int
    -> VU.Vector Int
    -> VU.Vector Int
    -> Int
    -> IO Int
knappsackMaxVal dp volumeVec valueVec dpSize = do
    mapM_
        (\i -> mapM_
            (\v -> do
                let volume = volumeVec VU.! i
                    value  = valueVec VU.! i
                newdp <- if v < volume
                    then AIO.readArray dp (i, v)
                    else do
                        dpIVm <- AIO.readArray dp (i, v - volume)
                        dpIV  <- AIO.readArray dp (i, v)
                        return (max (dpIVm + value) dpIV)
                AIO.writeArray dp (i + 1, v) newdp
            )
            [0 .. dpSize]
        )
        [0 .. VU.length volumeVec - 1]
    AIO.readArray dp (VU.length volumeVec, dpSize)

knappsackMinVol
    :: AIO.IOArray (Int, Int) Int
    -> VU.Vector Int
    -> VU.Vector Int
    -> Int
    -> Int
    -> IO Int
knappsackMinVol dp volumeVec valueVec dpSize maxVolume = do
    mapM_
        (\i -> mapM_
            (\v -> do
                let volume = volumeVec VU.! i
                    value  = valueVec VU.! i
                newdp <- if (v + value) > dpSize
                    then AIO.readArray dp (i, v)
                    else do
                        dpIVm <- AIO.readArray dp (i, v + value)
                        dpIV  <- AIO.readArray dp (i, v)
                        return (min (dpIVm - volume) dpIV)
                AIO.writeArray dp (i + 1, v) newdp
            )
            (reverse [0 .. dpSize])
        )
        [0 .. VU.length valueVec - 1]

    foldM
        (\acc x -> do
            num <- AIO.readArray dp (VU.length volumeVec, x)
            return $ if num <= maxVolume then x else acc
        )
        0
        [0 .. dpSize]
