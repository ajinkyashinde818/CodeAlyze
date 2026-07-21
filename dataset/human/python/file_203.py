import Control.Monad
import Data.List

bsearch :: Integral a => (a -> Bool) -> (a, a) -> a
bsearch p (ok, ng)
  | abs (ok - ng) <= 1 = ok
  | p mid = bsearch p (mid, ng)
  | otherwise = bsearch p (ok, mid)
  where
    mid = div (ok + ng) 2

triangle :: Int -> Maybe Int
triangle n = let k = bsearch (\x -> x*(x+1)<=2*n) (0, 10000000000) in k <$ guard (k*(k+1)==2*n) 

create :: Int -> [[Int]]
create 0 = [[]]
create k = let range = [1 + div (k * (k-1)) 2 .. div (k * (k+1)) 2] in range : zipWith (:) range (create (k-1))

f :: Maybe Int -> IO ()
f (Just k) = putStrLn "Yes" >> print (k+1) >> mapM_ (putStrLn . unwords . map show . (k:)) (create k)
f Nothing = putStrLn "No"

main = readLn >>= f . triangle
