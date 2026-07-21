import Control.Monad

type Pic = [String]

subList :: Int -> Int -> [a] -> [a]
subList idx len = take len . (drop idx)

stripFromPic :: Pic -> Int -> Int -> Int -> Pic
stripFromPic pic len x y = map (subList x len) $ subList y len pic

main :: IO ()
main = do
    [n, m] <- map (read :: String -> Int) <$> words <$> getLine
    pic <- replicateM n getLine
    tmpl <- replicateM m getLine
    let strip = stripFromPic pic m
    let a = strip <$> [0..n-m] <*> [0..n-m]
    putStrLn $ if any (==tmpl) a then "Yes" else "No"
