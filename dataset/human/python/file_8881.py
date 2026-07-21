import Control.Monad

check :: String -> Bool
check xs
  | null xs = True
  | five == "dream" && seven == "dreamer" = base || check (drop 7 xs)
  | five == "erase" && six == "eraser" = base || check (drop 6 xs)
  | five == "erase" || five == "dream" = base
  | otherwise = False
              where five = take 5 xs
                    six = take 6 xs
                    seven = take 7 xs
                    base = check (drop 5 xs)

main = do
  string <- getLine :: IO String
  if check string then putStrLn "YES" else putStrLn "NO"
