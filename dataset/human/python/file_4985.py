Table = %W(E N W S)

Man = Struct.new(:x, :y, :dir, :next_x, :next_y) do
  def next
    dx, dy = [[1, 0], [0, -1], [-1, 0], [0, 1]][self.dir]
    self.next_x, self.next_y = self.x + dx, self.y + dy
  end
  
  def move(field)
    field[self.y][self.x] = "."
    self.x, self.y = self.next_x, self.next_y
    self.next
    if field[self.y][self.x] == "X"
      return [self, true]
    else
      field[self.y][self.x] = Table[self.dir]
      return [self, false]
    end
  end
  
  def turn(field)
    [-1, 0, 1, 2].each do |step|
      next_dir = (self.dir + step) % 4
      dx, dy = [[1, 0], [0, -1], [-1, 0], [0, 1]][next_dir]
      type = field[self.y + dy][self.x + dx]
      if type == "." || type == "X"
        self.dir = next_dir
        field[self.y][self.x] = Table[next_dir]
        self.next
        return
      end
    end
  end
end

def passage(persons, field)
  h = Hash.new([])
  persons.each do |man|
    next_type = field[man.next_y][man.next_x]
    next unless next_type == "." || next_type == "X"
    h[[man.next_x, man.next_y]] += [man]
  end
  h.values
end


loop do
  w, h = gets.split.map(&:to_i)
  break if (w + h).zero?
  
  field = h.times.map {gets.chomp.chars}
  
  persons = []
  field.each_with_index do |row, y|
    row.each_with_index do |po, x|
      idx = Table.index(po)
      persons << Man.new(x, y, idx) if idx
    end
  end
  persons.each(&:next)
  
  t = 1
  loop do
    persons.each {|man| man.turn(field)}
    
    passage(persons, field).each do |ary|
      man, flag = if ary.size == 1
        ary[0].move(field)
      else
        ary.sort_by {|man0| (man0.dir + 2) % 4}[0].move(field)
      end
      persons.delete(man) if flag
    end
    
    break if t > 180
    break if persons.empty?
    t += 1
  end
  
  puts (t > 180) ? "NA" : t
end
