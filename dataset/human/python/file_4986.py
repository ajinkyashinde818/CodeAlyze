import Data.List

rotJenny 0 = [1,4,1,4,1,2,1,2]
rotJenny n = (last (rotJenny (n-1))):(init (rotJenny (n-1)))

lstToInt [] val = val
lstToInt (x:xs) val = lstToInt xs (val*10+x)

jennyToInt n = lstToInt (rotJenny n) 0

waitLst waits = rotJenny $ fst $ head sorted'
    where waits' n = zipWith (\x y->if x<y then 0 else x-y) waits $ rotJenny n
          sorted = sortBy (\x y->compare (sum $ snd x) (sum $ snd y)) $ map (\x->(x,waits' x)) [0..7]
          minsum = sum $ snd $ head sorted
          filtered = filter (\x->(sum $ snd x)==minsum) sorted
          sorted' = sortBy (\x y->compare (jennyToInt $ fst x) (jennyToInt $ fst y)) filtered

mystr :: [Int]->String
mystr (x:xs) = if null xs then (show x) else (show x)++" "++(mystr xs)

solve ::[Int]->IO ()
solve waits = do
    putStrLn $ mystr $ waitLst waits

main = do
    ss <- getContents
    mapM_ solve $ map (\x->map (\y->read y::Int) $ words x) $ lines ss
