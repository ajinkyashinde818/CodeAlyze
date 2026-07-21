import Data.List

main = do
  s <- getLine

  let
    a = filter (/= 'x') s
    b = countX s

  if isPalindrome a then
    print $ aux b
    else
    print $ -1

  where
    isPalindrome xs = xs == (reverse xs)

    countX xs = length a : (if null b then [] else countX $ tail b)
      where (a,b) = span (=='x') xs

    aux xs
      | even len  = sum $ (\(x,y) -> zipWith (\a b -> abs $ a - b) (reverse x) y) $ splitAt (len`div`2) xs
      | otherwise = sum $ (\(x,y) -> zipWith (\a b -> abs $ a - b) (reverse x) (tail y)) $ splitAt (len`div`2) xs 
        where len = length xs
