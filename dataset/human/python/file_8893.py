{-# LANGUAGE OverloadedStrings #-}
import Data.List
import Data.Ord
import Data.Char
import Data.Ratio
import Data.Maybe
import Data.String
import qualified Data.Text as T
import qualified Data.ByteString.Char8 as BS
---------------------------------------------------------------------------------
main = do
  s <- getLine'
  putStrLn' $ hakuchumu s

hakuchumu s
  | s=="" = "YES"
  | BS.isSuffixOf "dream" s = hakuchumu $ take' (length' s - 5) s
  | BS.isSuffixOf "dreamer" s = hakuchumu $ take' (length' s - 7) s
  | BS.isSuffixOf "erase" s = hakuchumu $ take' (length' s - 5) s
  | BS.isSuffixOf "eraser" s = hakuchumu $ take' (length' s - 6) s
  | otherwise = "NO"


---------------------------------------------------------------------------------

{-ByteString関連-}
--IO
getLine' = BS.getLine
getContents' = BS.getContents
getInt' = fst . fromJust . BS.readInt <$> getLine'
getIntListw' = map (fst . fromJust. BS.readInt) .words' <$> getContents'
getIntListl' = map (fst . fromJust. BS.readInt) .lines' <$> getContents'
getInteger' = fst . fromJust. BS.readInteger <$> getLine'
putStr' = BS.putStr
putStrLn' = BS.putStrLn
--演算子
bs1 |++| bs2 = BS.append bs1 bs2
chr |:+| bs2 = BS.cons chr bs2
bs1 |+:| chr = BS.snoc bs1 chr
--部分文字列操作
head' bs = BS.head bs
last' bs = BS.last bs
init' bs = BS.init bs
tail' bs = BS.tail bs
take' n bs = BS.take n bs
drop' n bs = BS.drop n bs
takeWhile' f bs = BS.takeWhile f bs
dropWhile' f bs = BS.dropWhile f bs
--リスト操作
length' bs = BS.length bs
reverse' bs = BS.reverse bs
transpose' bs = BS.transpose bs
sort' bs = BS.sort bs
group' bs = BS.group bs
lines' bs = BS.lines bs
words' bs = BS.words bs
unlines' bs = BS.unlines bs
unwords' bs = BS.unwords bs
--要素の有無
elem' chr bs = BS.elem chr bs
notElem' chr bs = BS.notElem chr bs
elemIndex' chr bs = BS.elemIndex chr bs
elemIndices' chr bs = BS.elemIndices chr bs
count' chr bs = BS.count chr bs
--整形
--justifyRight'::Char -> ByteString -> ByteString
--justifyRight' chr bs = convertString $ T.justifyRight chr (convertString bs)

{-elem関連-}
--elemの第一引数をリストにしたもの。
--elemList "abc" "atcoder" -> [True,False,True]
elemList [] _ = []
elemList (x:xs) list  = elem x list : elemList xs list

--elemIndexの第一引数をリストにしたもの。
elemIndexList [] list = []
elemIndexList (x:xs) list  = elemIndex x list : elemIndexList xs list

--elemIndicesの第一引数をリストにしたもの。
elemIndicesList [] list = []
elemIndicesList (x:xs) list  = elemIndices x list : elemIndicesList xs list
