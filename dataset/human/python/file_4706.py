{-# LANGUAGE OverloadedLists     #-}
{-# LANGUAGE OverloadedStrings   #-}
{-# LANGUAGE ScopedTypeVariables #-}

import           Control.Monad
--import           Control.Monad.Loops
import           Data.IORef
import           Data.Maybe
import qualified Data.Text     as T
import qualified Data.Text.IO  as T
import           GHC.Base
import           System.IO

import qualified Data.Array    as A
import           Data.Char
import qualified Data.IntMap   as I
import           Data.List
import qualified Data.Map      as M
import qualified Data.Set      as S
import qualified Data.Vector   as V

-- for Text
(+.+) = T.append
(!.!) = T.index

-- for Vector
count :: (a -> Bool) -> V.Vector a -> Int
count p = V.length . V.filter p

-- for IO
readT :: Read a => T.Text -> a
readT = read . T.unpack

getLineSpc :: Read a => IO [a]
getLineSpc = do
  t <- T.getLine
  let xs = map readT $ T.split (== ' ') t
  return xs

getLineSpcVec :: Read a => IO (V.Vector a)
getLineSpcVec = do
  t <- T.getLine
  let xs = V.fromList $ map readT $ T.split (== ' ') t
  return xs

----------
-- main --
----------
main :: IO ()
main = twoAnagrams

twoAnagrams :: IO ()
twoAnagrams = do
  s <- getLine
  t <- getLine
  let s' = sort s
      t' = sortBy (flip compare) t
  if s' < t'
    then
    putStrLn "Yes"
    else
    putStrLn "No"
