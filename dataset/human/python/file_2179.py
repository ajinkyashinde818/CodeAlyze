{-# LANGUAGE BangPatterns #-}
import Control.Monad
import Control.Applicative
import Data.List
import Data.Maybe
import Data.Bits
import qualified Data.IntMap.Strict as M
import qualified Data.ByteString.Char8 as B
import qualified Data.Vector.Unboxed as V
import Data.Vector.Unboxed ((!))

modulus :: Int
modulus = 10^9 + 7

query :: Int -> V.Vector Int -> V.Vector Int -> Int -> Maybe Int
query d numq cplt g = loop d Nothing g
  where
    loop _ _ g' | g' <= 0 = Just 0
    loop 0 Nothing _ = Nothing
    loop 0 (Just k) g' = if k * (numq ! (k-1)) - k >= g'
                         then Just $ (g'+k-1) `div` k
                         else Nothing
    loop i v g' = min <$> ans1 <*> ans2 <|> ans1 <|> ans2
      where
        ans1 = loop (i-1) (v <|> Just i) g'
        ans2 = ((numq ! (i-1)) +) <$>
               loop (i-1) v (g' - (numq ! (i-1)) * i - (cplt ! (i-1)))
                         

main :: IO ()
main = do
  [d,g_] <- map read . words <$> getLine
  (numq_,cplt_) <- unzip
    <$> replicateM d ((\[x,y] -> (read x, read y)) . words <$> getLine)
  let numq = V.fromList numq_
      cplt = V.fromList $ map (`div` 100) cplt_
      g = g_ `div` 100
  putStrLn $ show $ fromJust $ query d numq cplt g
