import Control.Monad

readIntLine :: IO ([Int])
readIntLine = do
    x <- getLine
    return $ map (read :: String -> Int) $ words x

main :: IO ()
main = do
    [r,g,b,n] <- readIntLine
    putStrLn $ show $ solve [r,g,b] n

solve (x:[]) n
    | mod n x == 0 = 1
    | otherwise    = 0

solve (x:xs) n =
    let mx = div n x
      in sum $ map (solve xs) $ map ((n-) . (x*)) [0..mx]
