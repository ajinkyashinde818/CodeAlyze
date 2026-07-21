import qualified Data.ByteString.Char8 as C
import Data.Maybe ( fromJust )

readInts :: IO [Int]
readInts = map (fst . fromJust . C.readInt) . C.words <$> C.getLine

main :: IO ()
main = do
  [k, s] <- readInts
  print $ f k s

numbers
  :: Int -> Int -> Int
numbers k = length . numbers' k 

numbers' :: Int -> Int -> [(Int,Int,Int)]
numbers' k s 
  = [ (x,y,z) | x <- [0..k]
              , y <- [0..k]
              , let z = s - x - y
              , 0 <= z && z <= k
              ]

-- https://atcoder.jp/contests/abc051/submissions/1127311
f :: Int -> Int -> Int
f k s = length [(x,y,z) | let m = max 0 (s-2*k)
                        , x <- [m .. k]
                        , y <- [m .. min k (s-x)]
                        , let z = s-x-y
                        , 0 <= z && z <= k
                        ]
