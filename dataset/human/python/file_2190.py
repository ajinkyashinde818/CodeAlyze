import System.IO
import Data.List
import Data.Char
import Debug.Trace

sumScore :: [(Int, Int, Int)] -> (Int, Int)
sumScore xs = (sum $ map (\(_, p, _) -> p) xs, sum $ map (\(d, p, c) -> (p * d * 100) + c) xs)

minp :: Int -> [(Int, Int, Int)] -> Int
minp g xs = f g xs 0
  where
  f g xs t
    | g <= 0 = t
    | xs == [] = t
    | otherwise = do
      let (d, p, c) = last xs
      let newxs = (init xs) ++ (if pred p == 0 then [] else [(d, pred p, c)])
      f (g - (d * 100)) newxs (succ t)

sp :: [Int] -> [(Int, Int)]
sp [] = []
sp xs = do
  let y = take 2 xs
  (y !! 0, y !! 1):(sp $ drop 2 xs)

main = do
  s <- getLine
  let g = read $ words s !! 1 :: Int
  s <- getContents
  let gg = sp $ map read $ words s :: [(Int, Int)]
  let i = zipWith (\d (p, c) -> (d, p, c)) [1..] gg
  let powi = map (\s -> (s, i \\ s)) $ subsequences i
  let p = map (\(x, y) -> (x , sumScore y)) powi
  print $ minimum $ map (\(x, y) -> (fst y) + (minp (g - (snd y)) x)) p
