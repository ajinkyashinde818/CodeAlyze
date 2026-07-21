import Data.List
import Data.Maybe

main = interact $ show . sol . read

sol :: Int -> Int
sol n = sum . map f . sig n $ takeWhile (\p -> p*p <= n) primes

f n = floor $ sqrt (2*fromIntegral n+0.25)-0.5

sig 1  _ = []
sig _ [] = [1]
sig n (p:ps) 
  | e > 0     = e:sig (n `div` p^e) ps
  | otherwise = sig n ps 
  where
  e = pred . fromJust $ find ((>0) . mod n . (p^)) [1..]

primes = 2:f [3,5..] where f (p:ps) = p:filter ((>0) . (`rem` p)) ps
