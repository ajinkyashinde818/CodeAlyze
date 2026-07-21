import Control.Monad
import qualified Data.Set as S
 
 
main = do
  [n, m] <- map read . words <$> getLine
  es <- map words <$> replicateM m getLine
  putStr $ solve n es S.empty
 
solve _ [] _ = "IMPOSSIBLE"
solve n (["1", b]:es) s
  | S.member b s = "POSSIBLE"
  | otherwise = solve n es (S.insert b s)
solve n ([a, b]:es) s
  | b /= show n = solve n es s
  | S.member a s = "POSSIBLE"
  | otherwise = solve n es (S.insert a s)
