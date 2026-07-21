{-# LANGUAGE DataKinds          #-}
{-# LANGUAGE ExplicitNamespaces #-}
{-# LANGUAGE KindSignatures     #-}
{-# LANGUAGE TypeOperators      #-}


import           Control.Exception (assert)
import           Data.List         (group, sort)
import           Data.Ratio        (denominator, numerator)
import           GHC.TypeLits      (type (+), KnownNat, Nat, type (^), natVal)

main :: IO ()
main = do
  n <- readLn
  s <- getLine
  assert (length s == n) $
    print $ solve s

type Modulus = 10 ^ 9 + 7

solve :: String -> Int
solve = subtract 1 . unModular' . product . map (fromIntegral . (+ 1) . length) . group . sort
  where
    unModular' :: Modular Int Modulus -> Int
    unModular' = unModular

newtype Modular a (modulus :: Nat) =
  Modular { unModular :: a }
  deriving (Eq)

instance Show a => Show (Modular a modulus) where
  show (Modular n) = show n

instance (Integral a, KnownNat modulus) => Num (Modular a modulus) where
  fromInteger           = toModular . fromInteger
  Modular n + Modular m = toModular $ n + m
  Modular n * Modular m = toModular $ n * m
  negate (Modular n)    = toModular $ negate n
  abs (Modular n)       = toModular $ abs n
  signum (Modular n)    = toModular $ signum n

instance (Integral a, KnownNat modulus) => Fractional (Modular a modulus) where
  recip m@(Modular n) = toModular $ modularReciprocal (fromInteger (natVal m)) n
  fromRational r = fromInteger (numerator r) / fromInteger (denominator r)

toModular :: (Integral a, KnownNat modulus) => a -> Modular a modulus
toModular n = let m = Modular $ n `mod` fromInteger (natVal m) in m

modularReciprocal :: Integral a => a -> a -> a
modularReciprocal modulus n = snd $ modularReciprocal' modulus n
  where
    -- modularReciprocal' n m = (x, y)
    -- n * x + m * y = 1
    modularReciprocal' _ 0 = notCoprimeError
    modularReciprocal' _ 1 = (0, 1)
    modularReciprocal' m l = (y, x - q * y)
      where
        (q, r) = m `divMod` l
        (x, y) = modularReciprocal' l r
    notCoprimeError =
      error $ unwords
        [ "divider"
        , parentheses $ showIntegral n
        , "must be coprime to modulus"
        , parentheses $ showIntegral modulus
        ]
    parentheses s = "(" ++ s ++ ")"
    showIntegral = show . toInteger
