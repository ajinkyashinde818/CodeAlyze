import qualified Data.Text as T
import qualified Data.Text.IO as T
import qualified Data.Text.Read as T
import qualified Data.Vector.Unboxed as VU
import Data.IntMap.Strict (IntMap)
import qualified Data.IntMap.Strict as IMS

main :: IO ()
main = do
  [n, k] <- map unsafeTextToInt . T.words <$> T.getLine :: IO [Int]
  as <- VU.map pred . unsafeTextToVectorInt <$> T.getLine :: IO (VU.Vector Int)
  let
    (start, period) = go 0 0 IMS.empty :: (Int, Int)
      where
        go :: Int -> Int -> IntMap Int -> (Int, Int)
        go l i m | Just s <- IMS.lookup i m = (s, l - s)
                 | otherwise               = go (succ l) (as VU.! i) (IMS.insert i l m)
    pos :: Int -> Int
    pos = go 0
      where
        go :: Int -> Int -> Int
        go i 0 = i
        go i l = go (as VU.! i) (pred l)
  print . succ . pos $ if k < start then k else start + (k - start) `mod` period

unsafeTextToVectorInt :: T.Text -> VU.Vector Int
unsafeTextToVectorInt = VU.unfoldr next
  where
    next :: T.Text -> Maybe (Int, T.Text)
    next s | T.null s  = Nothing
           | otherwise = Just . either undefined (T.stripStart <$>) . T.signed T.decimal $ s
{-# INLINE unsafeTextToVectorInt #-}

unsafeTextToInt :: T.Text -> Int
unsafeTextToInt s = case T.signed T.decimal s of
  Right (n, _) -> n
{-# INLINE unsafeTextToInt #-}
