import Data.List (group)


primes =
    let
        f (p : ps) = p : (filter $ (/= 0) . (`mod` p)) ps
    in
        f [ 2 .. ]

primeFactors n = [ x | x <- takeWhile (\y -> y * y <= n) primes, n `mod` x == 0 ]

factorize 1 = []
factorize n =
    let
        x = case primeFactors n of
            []     -> n
            p : ps -> p
    in
        x : factorize (n `div` x)

toInt :: String -> Int
toInt = read

steps' (n, count) set =
    let
        acc = n - head set
    in
        if acc >= 0
            then steps' (acc, count + 1) (tail set)
            else count

steps n = steps' (n, 0) [ 1 .. ]

main = do
    n <- toInt <$> getLine

    print . sum . map steps . map length . group $ factorize n
