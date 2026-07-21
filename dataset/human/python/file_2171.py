import Control.Applicative
import Control.Monad
import Data.List
import Data.Maybe
import Data.Ord

calc g ps = f 0 0 Nothing ps
  where
    f :: Int -> Int -> Maybe (Int, Int) -> [(Int, Int, Int)] -> Maybe Int
    f get probs Nothing [] = Just probs
    f get probs (Just (maxi, maxp)) []
      | get >= g = Just probs
      | get + (maxi * (maxp - 1)) >= g = let remain = g - get in Just (probs + div (remain + maxi - 1) maxi)
      | otherwise = Nothing
    f get probs maxprob ((i, p, c) : remains) = listToMaybe $ sort $ catMaybes [f get probs (maxprob <|> Just (i, p)) remains, f (get + i * p + c) (probs + p) maxprob remains]

main = do
    [d, g] <- map read . words <$> getLine
    ps <- sortBy (flip compare) . zipWith (\i [p, c] -> (100 * i, p, c)) [1..] <$> replicateM d (map read . words <$> getLine) :: IO [(Int, Int, Int)]
    print $ fromJust $ calc g ps
