import qualified Data.ByteString.Char8 as B

solve :: B.ByteString -> String
solve bs = loop $ B.reverse bs
    where
        dream = B.pack $ reverse "dream"
        dreamer = B.pack $ reverse "dreamer"
        erase = B.pack $ reverse "erase"
        eraser = B.pack $ reverse "eraser"
        loop sb
            | B.null sb = "YES"
            | B.take 5 sb == dream || B.take 5 sb == erase = loop $ B.drop 5 sb
            | B.take 6 sb == eraser = loop $ B.drop 6 sb
            | B.take 7 sb == dreamer = loop $ B.drop 7 sb
            | otherwise = "NO"

main = do
    str <- B.getLine
    putStrLn $ solve str
