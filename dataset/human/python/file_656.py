{-# LANGUAGE BangPatterns #-}
import Control.Arrow
import Control.Monad.Fix
import Data.Foldable
import qualified Data.Vector as V
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import qualified Data.ByteString.Char8 as B
import Data.ByteString.Internal (accursedUnutterablePerformIO)
import Debug.Trace

uread :: VU.Unbox a => Int -> VUM.IOVector a -> a
uread !i !v = accursedUnutterablePerformIO $ VUM.unsafeRead v i

uwrite :: VU.Unbox a => Int -> a -> VUM.IOVector a -> VUM.IOVector a
uwrite !i !a !v =
  accursedUnutterablePerformIO $ VUM.unsafeWrite v i a >> return v

umodify :: VU.Unbox a => Int -> (a -> a) -> VUM.IOVector a -> VUM.IOVector a
umodify !i !f !v =
  accursedUnutterablePerformIO $ VUM.unsafeModify v f i >> return v

uthaw :: VU.Unbox a => VU.Vector a -> VUM.IOVector a
uthaw = accursedUnutterablePerformIO . VU.unsafeThaw

ufreeze :: VU.Unbox a => VUM.IOVector a -> VU.Vector a
ufreeze = accursedUnutterablePerformIO . VU.unsafeFreeze

dijkstra
  :: (VU.Unbox a, Bounded a, Ord a, Num a)
  => Int  -- ^ nodes
  -> V.Vector (VU.Vector (Int, a))  -- ^ edges from i-th node: (end, cost)
  -> Int  -- ^ start node
  -> VU.Vector a  -- ^ constructed graph
dijkstra !n !edges !s = ufreeze $ fst $ fix
  ( \f (!costs, !visited) -> case findMinView costs visited of
    (-1) -> (costs, visited)
    n ->
      let visited' = uwrite n True visited
          c        = uread n costs
      in  if c <= uread n costs
            then f $ flip (,) visited' $ VU.foldl'
              ( \(!cs) (!e, !ec) ->
                let c' = c + ec
                in  if c' < uread e costs then uwrite e c' cs else cs
              )
              costs
              (edges V.! n)
            else f (costs, visited')
  )
  (costs0, visited0)
 where
  costs0 :: (VU.Unbox a, Bounded a, Num a) => VUM.IOVector a
  costs0 = uwrite s 0 (uthaw $ VU.replicate n maxBound)

  visited0 :: VUM.IOVector Bool
  visited0 = uthaw $ VU.replicate n False

  findMinView
    :: (VU.Unbox a, Bounded a, Ord a)
    => VUM.IOVector a
    -> VUM.IOVector Bool
    -> Int
  findMinView vec visited =
    fst
      $ foldl'
          ( \(!j, !acc) !i ->
            let a = uread i vec in if a < acc then (i, a) else (j, acc)
          )
          (-1, maxBound)
      $ filter (\(!i) -> uread i visited == False) [0 .. n - 1]

instance Bounded Double where
  maxBound = fromIntegral (maxBound :: Int)
  minBound = fromIntegral (minBound :: Int)

solve :: Int -> Int -> Int -> Int -> Int -> VU.Vector (Int, Int, Int) -> Double
solve xs ys xt yt n xyr = graph VU.! (n + 1)
 where
  big = fromIntegral (maxBound :: Int)

  dist2C :: (Int, Int, Int) -> (Int, Int, Int) -> Double
  dist2C (x1, y1, r1) (x2, y2, r2) =
    ( sqrt (fromIntegral $ (x1 - x2) ^ 2 + (y1 - y2) ^ 2)
      - fromIntegral (r1 + r2)
      )
      `max` 0

  toIndex (i, j) = i * (n + 2) + j

  distMemo = ufreeze $ foldl'
    ( \(!acc) (!i, !j) ->
      let c1 = if i == n
            then (xs, ys, 0)
            else if i == n + 1 then (xt, yt, 0) else xyr VU.! i
          c2 = if j == n
            then (xs, ys, 0)
            else if j == n + 1 then (xt, yt, 0) else xyr VU.! j
      in  uwrite (toIndex (i, j)) (dist2C c1 c2) acc
    )
    (uthaw $ VU.replicate ((n + 2) * (n + 2)) big)
    [ (i, j) | i <- [0 .. n + 1], j <- [0 .. n + 1], i /= j ]
  edges = V.force $ V.generate
    (n + 2)
    ( \(!e) -> VU.map (\(!i) -> (i, distMemo VU.! toIndex (i, e)))
      $ VU.fromList [0 .. n + 1]
    )
  graph = dijkstra (n + 2) edges n

main = do
  let readInt = fmap (second B.tail) . B.readInt

  (xs, ys, xt, yt) <-
    (\vec -> (vec VU.! 0, vec VU.! 1, vec VU.! 2, vec VU.! 3))
    .   VU.unfoldrN 4 readInt
    <$> B.getLine
  n   <- (\vec -> (vec VU.! 0)) . VU.unfoldrN 1 readInt <$> B.getLine
  xyr <-
    VU.replicateM n
    $   (\vec -> (vec VU.! 0, vec VU.! 1, vec VU.! 2))
    .   VU.unfoldrN 3 readInt
    <$> B.getLine
  print $ solve xs ys xt yt n xyr
