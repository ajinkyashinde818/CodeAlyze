module Main where
import Control.Monad
import Control.Applicative
import Data.Maybe
import Data.List
import qualified Text.Printf
import qualified Data.ByteString.Char8 as BC
import qualified Data.ByteString as BC

------------------------------------------

main :: IO ()
main = do
    s <- getLine
    putStrLn $ if '9' `elem` s then "Yes" else "No"

------------------------------------------

{- Int input -}

parseInt :: BC.ByteString -> Int
parseInt = fst . fromJust . BC.readInt

parseInts :: BC.ByteString -> [Int]
parseInts = map parseInt <$> BC.words

readInt :: IO Int
readInt = parseInt <$> BC.getLine

readInts :: IO [Int]
readInts = parseInts <$> BC.getLine

{- Double Formatting -}

doubleFmt :: Double -> String
doubleFmt = Text.Printf.printf "%.12f"
