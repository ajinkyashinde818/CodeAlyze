import Base.parse
import Base.StringVector
using Primes
using DataStructures

parse(::Type{String},  str::AbstractString) = str

isdelim(x::UInt8, xs::Set{UInt8}) = x in xs

function myreaduntil(s::IO, delims::Set{UInt8})::Vector{UInt8}
    out = StringVector(0)
    c::UInt8 = 0x00
    while !eof(s)
        c = read(s, UInt8)
        if !isdelim(c, delims)
            break
        end
    end
    push!(out, c)
    if eof(s)
        return out
    end
    while !eof(s)
        c = read(s, UInt8)
        if isdelim(c, delims)
            break
        end
        push!(out, c)
    end
    return out
end

delimset = Set([0x0a, 0x20])

function readword(io::IO = stdin, delims = delimset)::String
    word = myreaduntil(io, delims)
    i = length(word)
    if i == 0 || word[i] != 0x0a
        return String(word)
    elseif i < 2 || word[i-1] != 0x0d
        return String(resize!(word,i-1))
    else
        return String(resize!(word,i-2))
    end
end

pread(ty) = parse(ty, readword())

reads(tys...)::Tuple{tys...} = Tuple{tys...}(pread(ty) for ty in tys)

readvec(tys::Tuple , len::Signed)::Vector{Tuple{tys...}} = @inbounds Tuple{tys...}[reads(tys...) for i in 1:len]

readvec(ty::Type, len::Signed)::Vector{ty} = @inbounds ty[pread(ty) for i in 1:len]

function readmat(ty::Type, s...)::Matrix{ty}
    v = Matrix{ty}(undef, s...)
    @inbounds for i = 1:s[1]
        v[i,:] = readvec(ty, s[2])
    end
    v
end

function main()
    N = pread(Int)
    fs = factor(DataStructures.SortedDict, N)
    ans = 0
    for f in fs
        c = f[2]
        ans += (-1+sqrt(1+8c))÷2
    end
    println(Int(ans))
end

main()
