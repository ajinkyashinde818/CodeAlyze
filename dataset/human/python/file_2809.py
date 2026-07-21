import qualified Data.Text as T
import qualified Data.Text.IO as T
import qualified Data.Text.Read as T
import Data.List (unfoldr)
import Data.Maybe (catMaybes)

main :: IO ()
main = do
  let
    primeFactors :: Int -> [Int]
    primeFactors = catMaybes . unfoldr next . (,) 2
      where
        next :: (Int, Int) -> Maybe (Maybe Int, (Int, Int))
        next (_, 1)             = Nothing
        next (d, m) | m < d * d = Just (Just 1, (0, 1))
                    | otherwise = Just $ (,) (succ d) <$> ord d m
        ord :: Int -> Int -> (Maybe Int, Int)
        ord d = go 0
          where
            go :: Int -> Int -> (Maybe Int, Int)
            go c m | r == 0 = go (succ c) m'
              where
                (m', r) = m `divMod` d
            go 0 m = (Nothing, m)
            go c m = (Just c, m)
    f :: Int -> Int
    f m = unsafeBinaryMaxInt p (1, 8)
      where
        unsafeBinaryMaxInt :: (Int -> Bool) -> (Int, Int) -> Int
        unsafeBinaryMaxInt p = check
          where
            check :: (Int, Int) -> Int
            check ij@(_, j) | p j       = j
                            | otherwise = search ij
            search :: (Int, Int) -> Int
            search = fst . until ((==) <$> fst <*> pred . snd) halve
              where
                halve :: (Int, Int) -> (Int, Int)
                halve (i, j) | p m       = (m, j)
                             | otherwise = (i, m)
                  where
                    m = (i + j) `div` 2
        p :: Int -> Bool
        p = (<= 2 * m) . ((*) <$> id <*> succ)
  n <- unsafeTextToInt <$> T.getLine :: IO Int
  print . sum . map f . primeFactors $ n

unsafeTextToInt :: T.Text -> Int
unsafeTextToInt s = case T.signed T.decimal s of
  Right (n, _) -> n
{-# INLINE unsafeTextToInt #-}
