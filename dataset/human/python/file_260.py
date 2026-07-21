{-# LANGUAGE BangPatterns #-}
import Control.Arrow
import Control.Monad.Fix
import Data.Foldable
import qualified Data.Vector.Unboxed as VU
import qualified Data.ByteString.Char8 as B
import Debug.Trace

solve :: Int -> VU.Vector Int -> Int
solve n hs = VU.sum hs' - if even countOfNegative then 0 else 2 * minhs
 where
  hs'             = VU.map abs hs
  countOfNegative = VU.length $ VU.filter (< 0) hs
  minhs           = VU.minimum hs'

main = do
  let readInt = fmap (second B.tail) . B.readInt

  n  <- (\vec -> (vec VU.! 0)) . VU.unfoldrN 1 readInt <$> B.getLine
  hs <- VU.unfoldrN n readInt <$> B.getLine
  print $ solve n hs
