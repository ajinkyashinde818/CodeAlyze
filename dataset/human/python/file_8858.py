lap_distance, house_count = gets.split.map(&:to_i)
distance_list = gets.split.map(&:to_i)

def section_data(d, p1, p2)
  {
    distance: d,
    start_point_index: p1,
    end_point_index: p2
  }
end

sections = distance_list.map.with_index do |distance, index|
  if index + 1 == distance_list.size
    section_data(distance_list[0] + (lap_distance - distance), 0, index + 1)
  else
    section_data(distance_list[index + 1] - distance, index, index + 1)
  end
end

longest_section = sections.max { |x, y| x[:distance] <=> y[:distance] }
#index = sections.find_index(longest_section)
#sections.delete_at(index)

#p sections.inject(0) { |result, v| result + v[:distance].to_i }

p lap_distance - longest_section[:distance]
