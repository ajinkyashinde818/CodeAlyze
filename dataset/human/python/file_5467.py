{-# LANGUAGE FlexibleContexts, OverloadedStrings #-}
import Control.Applicative
import Control.Monad
import qualified Data.ByteString.Char8 as B
import Data.Maybe (fromJust)
import Text.Printf
import Debug.Trace

main = do
  [c1,c2] <- words <$> getLine
  putStrLn $ if c1 == c2 then "=" else if c1 < c2 then "<" else ">"


-- util
getInts :: IO [Int]
getInts = map (fst . fromJust . B.readInt) . B.words <$> B.getLine
