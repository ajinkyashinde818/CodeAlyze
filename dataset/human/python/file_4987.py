import Data.List
import Data.Ord

main = interact $ unlines . map (unwords . map show . flying_jenny . map read . words) . lines

flying_jenny ns = fst $ head $ sortBy (comparing snd) $ sortBy (comparing fst) $
 [(p,w) | p <- take 8 $ map (take 8) $ tails $ cycle [4,1,4,1,2,1,2,1],
          let w = sum $ zipWith (\x y -> max 0 (x-y)) ns p]
