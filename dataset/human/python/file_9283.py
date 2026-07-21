import Base.parse
import Base.StringVector

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
    N,K = reads(Int, Int)
    v = readvec(Int, N)
    checked = zeros(Int, N)
    np = 1
    lp = 0
    fi = 0
    sa = 0
    for i in 0:K
        if i == K
            println(np)
            return
        end
        if checked[np] != 0
            sa = i - checked[np]
            lp = np
            fi = i
            break
        end
        checked[np] = i
        np = v[np]
    end
    np = lp
    for i in 1:(K-fi)%sa
        np = v[np]
    end
    println(np)
end

main()
