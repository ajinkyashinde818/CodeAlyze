import Data.List

main = do
 [k,n] <- map read . words <$> getLine :: IO [Int]
 aList <- map read . words <$> getLine :: IO [Int]
 let bList = (map (\x -> x - k) aList) ++ aList ++ (map (\x -> x - k) aList)
 print $ minimum $ map (\x -> abs x) $ zipWith (-) (drop (n - 1) bList ) (take (length bList - n + 1) bList)
