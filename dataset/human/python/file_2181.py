{-# LANGUAGE BangPatterns #-}
import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe
-- import Data.List
-- import qualified Data.Vector.Unboxed as VU
-- import qualified Data.Vector.Unboxed.Mutable as VUM
-- import Control.Monad
-- import Control.Monad.ST
-- import Debug.Trace

solve :: Int -> Int -> [(Int,Int)] -> Int
solve d g pcs = minimum (catMaybes (map f power_ipc))
  where
    power_ipc = power (zip [1..d] pcs)
    f (pos, neg) | cs >= g = Just cn
                 | otherwise = remainCount cn (g - cs) neg
      where
        (cn, cs) = complMark pos

power :: (Ord a) => [a] -> [([a], [a])]
power [] = [([], [])]
power (x:ys) = map (f1 x) zs ++ map (f2 x) zs
  where zs = power ys
        f1 x (ps, qs) = (x:ps, qs)
        f2 x (ps, qs) = (ps, g x qs)
        g x [] = [x]
        g x (z:zs) | x >= z = x:z:zs
                   | otherwise = z : g x zs

complMark [] = (0, 0)
complMark ((i,(p,c)):ipcs) = (num + p, score + 100*i*p + c)
  where (num, score) = complMark ipcs

remainCount !acc !goal [] = Nothing
remainCount !acc !goal ((i,(p,_)):ipcs)
  | 100*i*(p-1) >= goal = Just $ acc + ((goal + 100*i-1) `div` (100*i))
  | otherwise = remainCount (acc+(p-1)) (goal-i*(p-1)) ipcs

readBInt :: B.ByteString -> Int
readBInt = fst . fromJust . B.readInt

tmain :: B.ByteString -> Int
tmain cont =
  let remLines0 = map B.words (B.lines cont)
      [bs_d,bs_g]:remLines1 = remLines0
      d = readBInt bs_d
      g = readBInt bs_g
      pcs = map (\[x1,x2] -> (readBInt x1,readBInt x2)) remLines1
  in solve d g pcs

outAnswer :: Int -> IO ()
outAnswer = putStrLn . show

main :: IO ()
main = outAnswer . tmain =<< B.getContents
