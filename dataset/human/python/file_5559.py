import qualified Data.Sequence as SQ

--挿入数ストア、処理すべきシーケンス、最終スコア
solver::Int -> SQ.Seq Char -> (Int,Bool)
solver score sq =  if SQ.length sq <= 1 then (score,True)
                                        else let (left SQ.:< sq') = SQ.viewl sq  in
                                             let (rest SQ.:> right) = SQ.viewr sq' in
                                             case (left=='x',right=='x',left==right) of
                                               (_,_,True)        -> solver score rest
                                               (True,False,False)-> solver (score+1) sq'
                                               (False,True,False)-> solver (score+1) (left SQ.<| rest)
                                               (_,_,False)       -> (score,False)
                                               

main::IO()
main=do
  str<-getLine
  let (sc,b) = solver 0 (SQ.fromList str)
  print (if b then sc else (-1))
