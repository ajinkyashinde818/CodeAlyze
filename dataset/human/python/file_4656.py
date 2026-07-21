import Data.Char
import Data.List

main = interact $ unlines . map (show' . sum . map read' . words) . tail . lines
 where
  read' [] = 0
  read' (x:xs)
   | isDigit x = digitToInt x * alphaToInt (head xs) + read' (tail xs)
   | otherwise = alphaToInt x + read' xs

  show' = concat . insertUnit . normalize . show

  alphaToInt c = case c of {'m'->1000; 'c'->100; 'x'->10; 'i'->1}
  normalize = reverse . take 4 . (++ "000") . reverse
  insertUnit = map simplify . transpose . (: ["mcxi"])
   where simplify [n,c] = if n=='0' then [] else (if n=='1' then [c] else [n,c])
