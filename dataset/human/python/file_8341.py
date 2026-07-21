import qualified Data.ByteString.Char8 as BS
import Data.Char (isSpace)
import Data.List (unfoldr, maximumBy)

data Position =
  Position
    { idx :: Int
    , pos :: Int
    }
    deriving (Show, Eq)
data DistInfo =
  DistInfo 
    { start :: Position
    , end :: Position
    , distance :: Int
    }
    deriving (Show)

main = do
  [k, n] <- map read . words <$> getLine :: IO [Int]
  as <- unfoldr (BS.readInt . BS.dropWhile isSpace) <$> BS.getLine
  print =<< solve k n as

test0 = solve 14 11 [0,1,2,3,4,8,9,10,11,12,13]

solve :: Int -> Int -> [Int] -> IO Int
solve k n as = do
  let positions = indexedMap Position as
  let distInfo = maxDistInfo $ spacings k positions
  let i = idx $ start $ distInfo
  let shifted = (drop i positions) ++ (take i positions)
  let xs = take (length shifted - 1) $ spacings k shifted
  return $ foldr (\e acc -> (distance e) + acc) 0 xs

indexedMap :: (Int -> a -> b) -> [a] -> [b]
indexedMap f xs = zipWith f [0..(length xs)-1] xs

dist :: Int -> Position -> Position -> Int
dist k (Position _ x) (Position _ y) =
  min (abs $ x - y) (k - (abs $ x - y))

pairsLooped :: [a] -> [(a, a)]
pairsLooped [] = []
pairsLooped (h:xs) = help (h:xs)
  where
    help [] = []
    help (x0:[]) = [(x0,h)]
    help (x0:x1:xs) = (x0,x1):(help (x1:xs))
  

spacings :: Int -> [Position] -> [DistInfo]
spacings k positions =
  map help $ pairsLooped positions
  where
    help (x, y) =
      DistInfo
        { start = y
        , end = x
        , distance = dist k x y
        }

maxDistInfo :: [DistInfo] -> DistInfo
maxDistInfo xs = maximumBy (\a b -> compare (distance a) (distance b)) xs
