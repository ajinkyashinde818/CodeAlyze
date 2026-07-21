{-# LANGUAGE MultiWayIf #-}

module Main where
import           Prelude
import           Control.Monad
import           Data.Monoid
import qualified Data.Array                    as A
import qualified Data.Array.IO                 as AIO
import qualified Data.Array.Unboxed            as AU
import qualified Data.ByteString               as BS
import qualified Data.ByteString.Char8         as BSC8
import           Data.Char
import           Data.List
import qualified Data.Map.Strict               as M
import           Data.Maybe
import           Data.Ord
import qualified Data.Set                      as S
import qualified Data.Vector                   as V
--import           Data.Vector.Algorithms.Search
import qualified Data.Vector.Mutable           as VM
import qualified Data.Vector.Unboxed           as VU
import qualified Data.Vector.Unboxed.Mutable   as VUM
import           Debug.Trace
--import qualified Data.Heap                     as H
import qualified Data.Sequence                 as SQ
import qualified Data.Graph.Inductive.PatriciaTree
                                               as G
import qualified Data.Graph.Inductive.Graph    as G
import           Data.Int
import           Data.Bits



main = do
  iN <- getI

  --let primeVec    = myPrimes (10 ^ 12)
  let watta   = waruX iN 2
  let scanned = scanPrime (div iN (2 ^ watta)) 3 [(2, watta)] [2]
  let pat     = makePattern 100 0
  {-
  let needPrimes1 = needPrimes iN primeVec 0

  let ret = map (\x -> pat !! (needPrimesNum iN x)) needPrimes1
  print (show needPrimes1)
  print ret
  print "hoge"
  print $ VU.last primeVec
-}
  let ret     = sum $ map (\(f, s) -> pat !! s) scanned

  print ret

waruX :: Int -> Int -> Int
waruX iN x = if mod iN x == 0 then waruX (div iN x) x + 1 else 0

scanPrime :: Int -> Int -> [(Int, Int)] -> [Int] -> [(Int, Int)]
scanPrime iN t ret primes
  | t ^ 2 > iN = if iN > 1 then ((iN, 1) : ret) else ret
  | otherwise = if mod iN t == 0
    then scanPrime (div iN (t ^ (waruX iN t)))
                   (t + 2)
                   ((t, (waruX iN t)) : ret)
                   (t : primes)
    else scanPrime iN (t + 2) ret primes

primesq t primes = all (\x -> mod t x /= 0) primes

needPrimesNum n t = if mod n t == 0 then needPrimesNum (div n t) t + 1 else 0

makePattern n t | t > n  = []
                | t <= n = (replicate (t + 1) t) ++ (makePattern n (t + 1))

needPrimes n primeVec t
  | primeVec VU.! t ^ 2 > n
  = []
  | otherwise
  = let prime = primeVec VU.! t
    in  if mod n prime == 0
          then prime : (needPrimes n primeVec (t + 1))
          else needPrimes n primeVec (t + 1)


{-
myPrimes n = reMyPrimes n 2

reMyPrimes n t tests 
 |t^2 > n = tests
 |otherwise=  if myPrimesParts t tests 0 then reMyprimes n (t+2) (t:tests) else

myPrimesParts t [] n == true
myPrimesParts t (x:xs) 
 |otherwise = if mod t x == 0 then False else  myPrimesParts t xs

-}

{-
hMaxPoint :: Int
hMaxPoint = 101
hMaximum :: H.Heap Int -> Int
hMaximum h = hMaxPoint - (H.minimum h)
hInsertMax :: Int -> H.Heap Int -> H.Heap Int
hInsertMax x = H.insert (hMaxPoint - x)
hDeleteMax :: H.Heap Int -> H.Heap Int
hDeleteMax = H.deleteMin
-}

{-
aroundSquare y x h w =
  [ aYX
  | aYX@(aY, aX) <- [(y - 1, x), (y, x - 1), (y + 1, x), (y, x + 1), (y, x)]
  , aY >= 0
  , aY <= (h - 1)
  , aX >= 0
  , aX <= (w - 1)
  ]
-}

splitReadBSC8 :: BSC8.ByteString -> [Int]
splitReadBSC8 bs =
  let (bs1, newBs) = BSC8.splitAt 1 bs
  in  if newBs == BSC8.empty
        then [test $ BSC8.readInt bs1]
        else (test $ BSC8.readInt bs1) : (splitReadBSC8 newBs)
  where test (Just (i, _)) = i

read2DimChar :: VM.IOVector (VUM.IOVector Char) -> Int -> Int -> IO Char
read2DimChar vec y x = do
  vecY <- VM.read vec y
  VUM.read vecY x
write2DimChar :: VM.IOVector (VUM.IOVector Char) -> Int -> Int -> Char -> IO ()
write2DimChar vec y x t = do
  vecY <- VM.read vec y
  VUM.write vecY x t

readTwoDimVec :: VM.IOVector (VUM.IOVector Int) -> Int -> Int -> IO Int
readTwoDimVec vec y x = do
  vecY <- VM.read vec y
  VUM.read vecY x
writeTwoDimVec :: VM.IOVector (VUM.IOVector Int) -> Int -> Int -> Int -> IO ()
writeTwoDimVec vec y x t = do
  vecY <- VM.read vec y
  VUM.write vecY x t


getVUI :: IO (VU.Vector Int)
getVUI = VU.unfoldr (BSC8.readInt . BSC8.dropWhile isSpace) <$> BSC8.getLine

getRepVUI :: Int -> IO (VU.Vector Int)
getRepVUI n =
  VU.unfoldr (BSC8.readInt . BSC8.dropWhile isSpace)
    .   BSC8.unlines
    <$> replicateM n BSC8.getLine

getVS :: IO (V.Vector Char)
getVS = V.fromList <$> getLine

getVUC :: IO (VU.Vector Char)
getVUC = VU.fromList <$> getLine

readI :: BSC8.ByteString -> Int
readI = fst . fromJust . BSC8.readInt


readIL :: BSC8.ByteString -> [Int]
readIL = map readI . BSC8.words


readIT2 :: BSC8.ByteString -> (Int, Int)
readIT2 bs =
  let words = BSC8.words bs in (readI $ head words, readI $ last words)

getI :: IO Int
getI = readI <$> BSC8.getLine

getIL :: IO [Int]
getIL = readIL <$> BSC8.getLine


getIT2 :: IO (Int, Int)
getIT2 = readIT2 <$> BSC8.getLine

getIT2Order :: IO (Int, Int)
getIT2Order =
  getIL >>= \x@[xz, xo] -> if xz > xo then return (xo, xz) else return (xz, xo)

getNIS :: Int -> IO [(Int, BSC8.ByteString)]
getNIS 0 = return []
getNIS n = do
  [aFst, aSnd] <- BSC8.words <$> BSC8.getLine
  next         <- getNIS (n - 1)
  return ((readI aFst, aSnd) : next)

il2Words :: [Int] -> String
il2Words = unwords . map show

il2Lines :: [Int] -> String
il2Lines = unlines . map show

p :: Int -> Int
p x = x - 1

--modNum = 10 ^ 9 + 7
--modulus = 1000000007
modulus = 2019

newtype MInt = M Int

instance Num MInt where
  (M a) + (M b) = M $ mod (a + b) modulus

  (M a) - (M b) = M $ mod (a - b) modulus

  (M a) * (M b) = M $ mod (a * b) modulus

  fromInteger a = M $ mod (fromInteger a) modulus

  abs (M a) = M $ abs a

  signum (M a) = M $ signum a

instance Show MInt where
  show (M a) = show (mod a modulus)

int2MInt :: Int -> MInt
int2MInt a = M (mod a modulus)

mInt2Int :: MInt -> Int
mInt2Int (M a) = a

{-
factsMod :: V.Vector MInt
factsMod = V.scanl (\acc x -> M x * acc) 1 $ V.generate 2000000 (+ 1)

factMod :: Int -> MInt
factMod = (factsMod V.!)
-}

factMod :: Int -> MInt
factMod n | n == 0    = 1
          | n == 1    = 1
          | otherwise = M n * (factMod (n - 1))


factDivMod :: Int -> Int -> MInt
factDivMod n k | n == k    = M 1
               | otherwise = M n * (factDivMod (n - 1) k)

powMod :: MInt -> MInt -> MInt
powMod n mK@(M k) | k == 0       = M 1
                  | k == 1       = n
                  | mod k 2 == 0 = powMod (n ^ 2) (M (div k 2))
                  | otherwise    = n * powMod (n ^ 2) (M (div k 2))

invMod :: MInt -> MInt
invMod (M 0) = error "inverse of 0"
invMod x     = powMod x (M (modulus - 2))

{-
combiMod :: Int -> Int -> MInt
combiMod n k
  | n < 0 || k < 0 || k > n = 0
  | otherwise = factMod n * invMod (factMod (n - k)) * invMod (factMod k)
-}
combiMod :: Int -> Int -> MInt
combiMod n k | n < 0 || k < 0 || k > n = 0
             | k > n - k = factDivMod n k * invMod (factMod (n - k))
             | otherwise = factDivMod n (n - k) * invMod (factMod k)



combi :: Int -> Int -> Int
combi n k | n < 0 || k < 0 || k > n = 0
          | k == n                  = 1
          | otherwise               = div (div (fact n) (fact (n - k))) (fact k)

{-
primes :: Integral a => [a]
primes = map fromIntegral $ [2, 3] ++ primes'
 where
  primes' = [5] ++ f 1 7 primes'
  f m s (p : ps) = [ n | n <- ns, gcd m n == 1 ] ++ f (m * p) (p * p) ps
    where ns = [ x + y | x <- [s, s + 6 .. p * p - 2], y <- [0, 4] ]

prime n = primes !! n
primes = sieve [2 ..]
sieve (p : xs) = p : sieve [ x | x <- xs, x `mod` p /= 0 ]
-}
fact :: Int -> Int
fact 0         = 1
fact n | n > 0 = n * fact (n - 1)

knappsack :: Int -> [(Int, Int)] -> VU.Vector Int
knappsack maxW [] = VU.replicate (maxW + 1) 0
knappsack maxW ((w, v) : xs) =
  let tailDP = knappsack maxW xs
  in  VU.generate (maxW + 1) $ \i -> if w <= i
        then max (tailDP VU.! i) (tailDP VU.! (i - w) + v)
        else tailDP VU.! i

knappsackMaxVal
  :: AIO.IOArray (Int, Int) Int
  -> VU.Vector Int
  -> VU.Vector Int
  -> Int
  -> IO Int
knappsackMaxVal dp volumeVec valueVec dpSize = do
  mapM_
    (\i -> mapM_
      (\v -> do
        let volume = volumeVec VU.! i
            value  = valueVec VU.! i
        newdp <- if v < volume
          then AIO.readArray dp (i, v)
          else do
            dpIVm <- AIO.readArray dp (i, v - volume)
            dpIV  <- AIO.readArray dp (i, v)
            return (max (dpIVm + value) dpIV)
        AIO.writeArray dp (i + 1, v) newdp
      )
      [0 .. dpSize]
    )
    [0 .. VU.length volumeVec - 1]
  AIO.readArray dp (VU.length volumeVec, dpSize)

knappsackMinVol
  :: AIO.IOArray (Int, Int) Int
  -> VU.Vector Int
  -> VU.Vector Int
  -> Int
  -> Int
  -> IO Int
knappsackMinVol dp volumeVec valueVec dpSize maxVolume = do
  mapM_
    (\i -> mapM_
      (\v -> do
        let volume = volumeVec VU.! i
            value  = valueVec VU.! i
        newdp <- if (v + value) > dpSize
          then AIO.readArray dp (i, v)
          else do
            dpIVm <- AIO.readArray dp (i, v + value)
            dpIV  <- AIO.readArray dp (i, v)
            return (min (dpIVm - volume) dpIV)
        AIO.writeArray dp (i + 1, v) newdp
      )
      (reverse [0 .. dpSize])
    )
    [0 .. VU.length valueVec - 1]
  foldM
    (\acc x -> do
      num <- AIO.readArray dp (VU.length volumeVec, x)
      return $ if num <= maxVolume then x else acc
    )
    0
    [0 .. dpSize]


lcsTable :: BS.ByteString -> BS.ByteString -> V.Vector (VU.Vector Int)
lcsTable xs ys = V.scanl step (VU.replicate (m + 1) 0) xs'
 where
  n   = BS.length xs
  m   = BS.length ys
  xs' = V.generate n $ BSC8.index xs :: V.Vector Char
  ys' = VU.generate m $ BSC8.index ys :: VU.Vector Char
  step :: VU.Vector Int -> Char -> VU.Vector Int
  step v x = VU.scanl innerStep 0 (VU.zip3 v (VU.tail v) ys')
   where
    innerStep :: Int -> (Int, Int, Char) -> Int
    innerStep a (b, c, y) | x == y    = 1 + b
                          | otherwise = max a c
{-
main = do
xs <- BS.getLine
ys <- BS.getLine
print $ VU.last $ V.last $ lcsTable xs ys
-}


myFilter :: (a -> Bool) -> [a] -> ([a], [a])
myFilter _pred [] = ([], [])
myFilter pred (x : xs)
  | pred x    = let (l, r) = myFilter pred xs in (x : l, r)
  | otherwise = let (l, r) = myFilter pred xs in (l, x : r)

--UnionFindデータ構造
type UF_PARENT = VUM.IOVector Int
type UF_RANK = VUM.IOVector Int
type UF = (UF_PARENT, UF_RANK)
uf_makeSet :: Int -> IO UF
uf_makeSet n = do
  parent <- VU.thaw $ VU.generate n id
  rank   <- VUM.replicate n 0
  return (parent, rank)
uf_union :: UF -> Int -> Int -> IO ()
uf_union unionFind@(parents, ranks) x y = do
  xRoot     <- uf_find unionFind x
  yRoot     <- uf_find unionFind y
  xRootRank <- VUM.read ranks xRoot
  yRootRank <- VUM.read ranks yRoot
  if
    | xRootRank > yRootRank -> VUM.write parents yRoot xRoot
    | xRootRank < yRootRank -> VUM.write parents xRoot yRoot
    | xRoot /= yRoot -> do
      VUM.write parents yRoot xRoot
      VUM.write ranks xRoot (xRootRank + 1)
    | otherwise -> return ()

uf_find :: UF -> Int -> IO Int
uf_find unionFind@(parents, ranks) x = do
  xParent <- VUM.read parents x
  if xParent == x
    then return x
    else do
      xRootParent <- uf_find unionFind xParent
      VUM.write parents x xRootParent
      return xRootParent

--UnDirectedGraph(無向グラフ)データ構造
type UDG = M.Map Int [Int]
list2UDG :: [(Int, Int)] -> M.Map Int [Int]
list2UDG = foldl
  (\acc x ->
    let lr = M.insertWith (++) (fst x) [snd x] acc
    in  M.insertWith (++) (snd x) [fst x] lr
  )
  M.empty
