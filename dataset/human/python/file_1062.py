import Control.Monad
import Data.Maybe
import Data.List
import Text.Printf
import qualified Data.ByteString.Char8 as C

getInts :: IO [Int]
getInts = map (fst . fromJust . C.readInt) . C.words <$> C.getLine

main :: IO ()
main = do
  _ <- getInts
  as <- getInts
  bs <- getInts
  let bs' = reverse bs
      f = zip as bs'
      o = find (\(x, y) -> x == y) f
      p = snd $ fromJust o
      pp = repeat (p, p)
      ans = if isNothing o then Just bs' else g1
      g1 = if l3 > l1 + l5 then Nothing else Just g2
      (f1, f2') = span (\(x, y) -> x /= p && y /= p) f
      (f2, f3') = span (\(x, y) -> (x == p) /= (y == p)) f2'
      (f3, f4') = span (==(p, p)) f3'
      (f4, f5) = span (\(x, y) -> (x == p) /= (y == p)) f4'
      [l1, l2, l3, l4, l5] = map length [f1, f2, f3, f4, f5]
      [l, r] = [min l1 l3, min (l3 - (min l1 l3)) l5]
      (a, b) = splitAt l f1
      (c, d) = splitAt r f5
      g2 = map snd $ concat [take l pp, b, f2, a, c, f4, take r pp, d]
  putStrLn $ if isNothing ans
    then "No"
    else "Yes\n" ++ (concat $ intersperse " " $ map show (fromJust ans))
