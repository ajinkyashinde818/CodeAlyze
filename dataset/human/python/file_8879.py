import Data.List

main = do
  s <- getLine
  putStrLn . showF $ f s
  
showF :: Bool -> String
showF True  = "YES"
showF False = "NO"
  
f :: String -> Bool
f [] = True
f s
  | "dream" `isPrefixOf` s && "dreamer" `isPrefixOf` s = f (drop 5 s) || f (drop 7 s)
  | "dream" `isPrefixOf` s = f (drop 5 s)
  | "dreamer" `isPrefixOf` s = f (drop 7 s)
  | "erase" `isPrefixOf` s && "eraser" `isPrefixOf` s = f (drop 5 s) || f (drop 6 s)
  | "erase" `isPrefixOf` s = f (drop 5 s)
  | "eraser" `isPrefixOf` s = f (drop 6 s)
  | otherwise = False
