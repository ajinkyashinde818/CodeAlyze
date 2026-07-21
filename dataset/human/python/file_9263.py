def resolve()

    s=gets.strip
    while s!= ""

        if s.end_with?("dream")
            s=s.slice!(0,s.length-5)
            next
        end


        if s.end_with?("dreamer")
            s=s.slice!(0,s.length-7)
            next
        end

        if s.end_with?("erase")
            s=s.slice!(0,s.length-5)
            next
        end

        if s.end_with?("eraser")
            s=s.slice!(0,s.length-6)
            next
        end

        puts "NO"
        return

    end
    puts "YES"



end



resolve()
