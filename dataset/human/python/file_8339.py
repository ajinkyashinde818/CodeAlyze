module Main where
import qualified Control.Monad as C
import qualified Data.Char as C
import qualified Data.List as L
import qualified Data.Map as M
import qualified Data.Array as A

int = read :: String -> Int
getWord :: IO String
getWord = do
  c <- getChar
  if C.isSpace c
  then
    return []
  else do
    ws <- getWord
    return (c:ws)
getInt = fmap int getWord
replace pred a = map (\x -> if pred x then a else x)

main = interact $ printer . solver . parser
parser = map int . words
printer = unlines . (:[]) . show

solver (k:n:a0:as) = k - mx
  where
    bs = as ++ [ a0 + k ]
    cs = zipWith (-) bs (a0:as) 
    mx = maximum cs
