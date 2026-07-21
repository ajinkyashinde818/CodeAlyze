{-# LANGUAGE MultiWayIf #-}

import Data.Maybe (fromJust)
import qualified Data.ByteString.Char8 as B

main :: IO ()
main = do
    [k, s] <- map (fst . fromJust . B.readInt) . B.words <$> B.getLine :: IO [Int]
    let [a, b] = if | s <= k -> [0, s]
                    | s <= k * 2 -> [0, k]
                    | otherwise -> [s - k * 2, k]
    let solve x i = let t = s - i
                    in x + (if t <= k then t + 1 else k * 2 - t + 1)
    print $ foldl solve 0 [a..b]
