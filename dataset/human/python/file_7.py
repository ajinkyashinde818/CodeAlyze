import Data.List
main=do
    line<-getLine
    let ipn=[read x::Int|x<-words line]
    let iipn=(sort $ init ipn)
    let vr=iipn!!2
    let vg=iipn!!1
    let vb=iipn!!0
    let n=ipn!!3
-- can do some optimisim because of (vr,vg,vb) symmetry of functional displacement
    print $ length [nr|nr<-[0..(div n vr)],ng<-[0..(div n vg)],n-nr*vr-ng*vg>=0,mod (n-nr*vr-ng*vg) vb ==0]
