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
import qualified Data.Array                    as A
import qualified Data.Array.Unboxed            as AU
import qualified Data.Array.IO                 as AIO



getvuil :: IO (VU.Vector Int)
getvuil = VU.unfoldr (BSC8.readInt . BSC8.dropWhile isSpace) <$> BSC8.getLine
readi :: BSC8.ByteString -> Int
readi = fst . fromJust . BSC8.readInt
readil :: BSC8.ByteString -> [Int]
readil = map readi . BSC8.words
geti :: IO Int
geti = readi <$> BSC8.getLine
getil :: IO [Int]
getil = readil <$> BSC8.getLine

getNis :: Int -> IO [(Int, BSC8.ByteString)]
getNis 0 = return []
getisl n = do
    [aFst, aSnd] <- BSC8.words <$> BSC8.getLine
    next         <- (getisl (n - 1))
    return ((readi aFst, aSnd) : next)

il2ss :: [Int] -> String
il2ss = unwords . map show

il2sn :: [Int] -> String
il2sn = unlines . map show

main :: IO ()
main = do
    aS  <- getLine
    aQ  <- geti
    aQD <- getQuery aQ
    let (rF, rB, rR) = foldl
            (\acc@(f, b, r) x ->
                let (q1, q2, q3) = x
                in  if q1 == 1
                        then (f, b, not r)
                        else if q2 == 1
                            then if r == False
                                then ((q3 !! 0 : f), b, r)
                                else (f, (q3 !! 0 : b), r)
                            else if r == True
                                then ((q3 !! 0 : f), b, r)
                                else (f, (q3 !! 0 : b), r)
            )
            ("", "", False)
            aQD
    putStrLn
        (if rR == False
            then rF ++ aS ++ (reverse rB)
            else rB ++ (reverse aS) ++ (reverse rF)
        )

getQuery :: Int -> IO [(Int, Int, String)]
getQuery aQ = mapM
    (\_ -> do
        x <- BSC8.words <$> BSC8.getLine
        return
            (if x !! 0 == (BSC8.pack "1")
                then (1, 0, "")
                else (2, (readi (x !! 1)), BSC8.unpack (x !! 2))
            )
    )
    [1 .. aQ]
