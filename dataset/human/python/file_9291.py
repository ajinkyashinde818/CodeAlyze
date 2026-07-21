{-# LANGUAGE Strict #-}
{-# LANGUAGE StrictData #-}

import Data.Array.Unboxed
import qualified Data.ByteString.Char8 as BS
import Data.Char
import Data.List

main = do
  li <- BS.getLine
  let [n,k] = map (read . BS.unpack) $ BS.words li
  li <- BS.getLine
  let as = unfoldr (BS.readInt . BS.dropWhile isSpace) li
  let ans = compute n k as
  print ans

type A = UArray Int Int

compute :: Int -> Int -> [Int] -> Int
compute n k as = (loop arid k ar0 :: A) ! 1
  where
    ar0 = listArray (1,n) as :: A
    addAr ar1 ar2 = listArray (1,n) [ (ar2 :: A) ! ((ar1 :: A) ! i) | i <- [1..n] ] :: A
    arid = listArray (1,n) $ replicate n 1 :: A
    loop ar 0 _ = ar :: A
    loop ar k arn
      | odd k = loop (addAr ar arn) (k `div` 2) (addAr arn arn)
      | True  = loop ar             (k `div` 2) (addAr arn arn)
