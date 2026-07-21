{-# LANGUAGE FlexibleContexts #-}
{-# LANGUAGE UnboxedTuples #-}
{-# LANGUAGE OverloadedStrings #-}
{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE LambdaCase #-}
{-# LANGUAGE ViewPatterns #-}
{-# LANGUAGE TupleSections #-}
{-# LANGUAGE MultiWayIf #-}

import Control.Monad
import Control.Monad.ST
import Control.Monad.State
import Control.Monad.Primitive
import Control.Applicative
import Control.Arrow
import Data.List
import Data.Array
import Data.Array.IO
import Data.Array.ST
import Data.IORef
import Data.STRef
import Data.Maybe
import Data.Bits
import Data.Ord
import Data.Ratio
import Data.Int
import Data.Char
import qualified Data.ByteString.Char8 as BS
import qualified Data.Set as Set
import qualified Data.Vector as V
import qualified Data.Vector.Mutable as VM
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import qualified Data.Vector.Generic as VG
import qualified Data.Vector.Generic.Mutable as VGM
import Data.Tuple
import Data.Function
import Text.Printf
import Debug.Trace
import Numeric

modifyArray arr i f = readArray arr i >>= \x -> writeArray arr i (f x)

listToTuple2 [a,b] = (a,b)
listToTuple3 [a,b,c] = (a,b,c)
listToTuple4 [a,b,c,d] = (a,b,c,d)
listToTuple5 [a,b,c,d,e] = (a,b,c,d,e)

readIntBS = fst . fromJust . BS.readInt

for = flip map

infixr 1 ?
(?) :: Bool -> (a,a) -> a
(?) b t = (if b then fst else snd) t

main :: IO ()
main = do
  [xs,ys,xt,yt] <- map read . words <$> getLine :: IO [Int64]
  n <- readLn :: IO Int

  bs <- replicateM n $ map read . words <$> getLine :: IO [[Int64]]


  let es =
        (0, n+1, distPointPoint (xs,ys) (xt,yt)) :
        [(i, j, distCircleCircle (x1,y1,r1) (x2,y2,r2)) | (i,[x1,y1,r1]) <- zip [1..] bs, (j,[x2,y2,r2]) <- zip [1..] bs, i<j] ++
        [(0, i, distPointCircle (xs,ys) (x,y,r)) | (i,[x,y,r]) <- zip [1..] bs] ++
        [(n+1, i, distPointCircle (xt,yt) (x,y,r)) | (i,[x,y,r]) <- zip [1..] bs]
  
      graph = buildWeightedUndirectedGraph (0,n+1) es


  putStrLn $ showFFloat Nothing ((dijkstra graph 0) ! (n+1)) ""


distPointPoint :: Integral a => (a,a) -> (a,a) -> Double
distPointPoint (px1,py1) (px2,py2) = sqrt . fromIntegral $ (px1-px2)^2 + (py1-py2)^2

distPointCircle ::Integral a => (a,a) -> (a,a,a) -> Double
distPointCircle (px,py) (cx,cy,r) = max ((sqrt . fromIntegral $ (px-cx)^2 + (py-cy)^2) - (fromIntegral r)) 0

distCircleCircle :: Integral a => (a,a,a) -> (a,a,a) -> Double
distCircleCircle (cx1,cy1,r1) (cx2,cy2,r2) = max ((sqrt . fromIntegral $ (cx1-cx2)^2 + (cy1-cy2)^2) - (fromIntegral $ r1 + r2)) 0





  
type Node = Int
type Cost = Double
type Edge = (Node, Cost)
type Graph = Array Node [Edge]

{-- 重み付き無向グラフ --}
buildWeightedUndirectedGraph :: (Node,Node) -> [(Node,Node,Cost)] -> Array Node [(Node,Cost)]
buildWeightedUndirectedGraph bound dat = runST $ do
  graph <- newArray bound [] :: ST s (STArray s Node [(Node,Cost)])
  forM_ dat $ \(s,e,c) -> do
    modifyArray graph s ((e,c):)
    modifyArray graph e ((s,c):)
  freeze graph



inf = 10^18 :: Double

dijkstra :: Graph -> Node -> Array Node Cost
dijkstra graph start = runST $ do
  cost <- newArray (bounds graph) inf :: ST s (STUArray s Node Cost)
  check <- newArray (bounds graph) False :: ST s (STUArray s Node Bool)
  writeArray cost start 0
  evalStateT (dijkstra' cost check) (Set.singleton (0, start))
  freeze cost
  where
    dijkstra' cost check = do
      isNull <- Set.null <$> get
      when (not $ isNull) $ do
        (curCost, cur) <- state Set.deleteFindMin
        let nextNodes = graph ! cur

        lift $ writeArray check cur True

        forM_ nextNodes $ \(next, edgeCost) -> do
          nextCost <- lift $ readArray cost next
          
          if nextCost == -1 then do
            lift $ writeArray cost next (curCost + edgeCost)
            modify $ Set.insert (curCost + edgeCost, next)
            else do
            when (curCost + edgeCost < nextCost) $ lift $ writeArray cost next (curCost + edgeCost)
            isChecked <- lift $ readArray check next
            unless isChecked $ do
              (\x -> modify $ \s -> Set.insert (x, next) $ Set.delete (nextCost, next) s) =<< (lift $ readArray cost next)
        dijkstra' cost check
