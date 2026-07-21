{-# LANGUAGE OverloadedStrings #-}
import Data.Char
import Data.List
import Control.Monad
import qualified Data.ByteString.Char8 as BS

main :: IO ()
main = do
  s <- BS.getLine
  q <- head.parseLine <$> BS.getLine
  qs <- replicateM q (BS.words <$> BS.getLine)
  let [h,m,l] = solve s qs
  BS.putStr h
  BS.putStr m
  BS.putStrLn l
  where
    parseLine = unfoldr (BS.readInt . BS.dropWhile isSpace)


solve :: BS.ByteString -> [[BS.ByteString]] -> [BS.ByteString]
solve s qs = lastProcess $ foldl process (True,[],[],s) qs

lastProcess :: (Bool, [BS.ByteString], [BS.ByteString], BS.ByteString) -> [BS.ByteString]
lastProcess (True, headStr, lastStr, s) = [BS.concat headStr, s, BS.concat.reverse $ lastStr]
lastProcess (False, headStr, lastStr, s) = [BS.concat headStr, BS.reverse s, BS.concat.reverse $ lastStr]

process :: (Bool, [BS.ByteString], [BS.ByteString], BS.ByteString) -> [BS.ByteString] -> (Bool, [BS.ByteString], [BS.ByteString], BS.ByteString)
process (dir, h, l, m) ("1":_) = (not dir, l, h, m)
process (dir, h, l, m) ("2":"1":c:_) = (dir, (c:h), l, m)
process (dir, h, l, m) ("2":"2":c:_) = (dir, h, (c:l), m)
