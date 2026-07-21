import Control.Monad
import Data.List

f c [] [] = c
f c (a:as) [] = if a=='x' then f (c+1) as [] else -2
f c [] (b:bs) = if b=='x' then f (c+1) [] bs else -2
f c (a:as) (b:bs)
  | a==b      = f c as bs
  | a=='x'    = f (c+1) as (b:bs)
  | b=='x'    = f (c+1) (a:as) bs
  | otherwise = -2

g s = flip div 2 $ f 0 s $ reverse s

main = getLine >>= print . g
