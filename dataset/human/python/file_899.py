import Control.Monad
import Data.List
import qualified Data.ByteString.Char8 as B

main = do
  [n,c] <- fmap (map read . words) getLine
  text <- B.getContents
  let xs = map ((\(x:v:_)-> x`seq`v`seq`(x,v)) . map readI . B.words) (B.lines text)
  print (solve c xs)


-- for fast read
readI :: B.ByteString -> Int
readI s = case B.readInt s of Just (n,_) -> n


-- MaxState, CurrentState, CurrentX
type State = (Int, (Int, Int))

solve :: Int -> [(Int,Int)] -> Int
solve c xs =
  solveTurn roundR roundL
  where
    roundR = scanl f (0,(0,0)) xs
    roundL = scanr (flip f) (0,(0,0)) [x'`seq`(x',v)|(x,v)<-xs, let x' = c-x]

    f (m,(s,y)) (x,v) = let s' = s-(x-y)+v in s'`seq`(max m s', (s', x))

solveTurn :: [State] -> [State] -> Int
solveTurn ss1 ss2 =
  foldl' f 0 (zip ss1 ss2)
  where
    f a (((m1,(s1,x1))),((m2,(s2,x2)))) = max a $! max (s1+m2-x1) $! (s2+m1-x2)
