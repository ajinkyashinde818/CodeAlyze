import qualified Data.IntMap as IM

main :: IO ()
main = do
  getLine
  as <- map read . words <$> getLine
  bm <- IM.fromList . zip [1..] . map read . words <$> getLine
  cm <- IM.fromList . zip [1..] . map read . words <$> getLine
  print $ solve bm cm as

solve :: IM.IntMap Int -> IM.IntMap Int -> [Int] -> Int
solve bm cm as = sb + sc
  where
    sb = sum [ bm IM.! a | a <- as ]
    sc = sum [ cm IM.! a | a <- [ a1 | (a1, a2) <- zip as (tail as), a2 == a1 + 1 ] ]
