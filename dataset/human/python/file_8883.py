import Data.List

main = do
    s <- reverse <$> getLine
    putStrLn $ if check s then "YES" else "NO"

check [] = True
check s | "maerd" `isPrefixOf` s = check (drop 5 s)
        | "remaerd" `isPrefixOf` s = check (drop 7 s)
        | "esare" `isPrefixOf` s = check (drop 5 s)
        | "resare" `isPrefixOf` s = check (drop 6 s)
        | otherwise = False
