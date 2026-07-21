import Data.List

main = do
    n <- readLn
    let xs = sort . map snd $ factorize n
    let as = scanl1 (+) [1..]
    print $ solve 0 0 as xs

solve k _ _ [] = k
solve k l (a:as) (x:xs) | x < a = solve (k+l) l (a:as) xs
                        | otherwise = solve k (l+1) as (x:xs)

primes :: Integral a => [a]
primes = map fromIntegral primes'
  where
    primes' = [2, 3, 5] ++ f 5 7 (drop 2 primes')
    f m s (p:ps) = [n | n <- ns, gcd m n == 1] ++ f (m * p) (p * p) ps
      where
        ns = [x + y | x <- [s,s + 6 .. p * p - 2], y <- [0, 4]]

isPrime :: Integral a => a -> Bool
isPrime n = (n > 1) && isPrime' primes
  where
    isPrime' (x:xs)
      | x * x > n = True
      | rem n x == 0 = False
      | otherwise = isPrime' xs

factorize :: Integral a => a -> [(a, Int)]
factorize 1 = [(1, 0)]
factorize n = format $ factorize' n primes
  where
    format ps = [(x, length xs) | xs@(x:_) <- group ps]
    factorize' n ps@(p:ps')
      | p * p > n = [n]
      | rem n p == 0 = p : factorize' (div n p) ps
      | otherwise = factorize' n ps'
