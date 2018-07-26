##Code for a doubly Linked List
##Class node defines everything needed to interface with a node
##Class Linked List define everything needed to interface with linked list

class Node
	def initialize data, ptr_next = nil 
		@data = data
		@ptr_next = ptr_next
	end

	def set_next node
		@ptr_next = node
	end
	def get_next
		@ptr_next
	end

	def next?
		!@ptr_next
	end

	def display
		puts @data
	end

end

class LL
	def initialize data
		@head = Node.new(data, nil)
		@length = 1
	end

	def display
		current = @head
		while (!current.next?)
			current.display 
			current = current.get_next
		end
		current.display 
	end

	def insert_at_end data 
		current = @head
		tmp = Node.new(data, nil)
		while (!current.next?)
			current = current.get_next
		end
		current.set_next(tmp)
		@length += 1

	end

	def insert_at_front data
		current = @head
		tmp = Node.new(data, nil)
		
		tmp.set_next(@head)
		@head = tmp

		@length +=1
	end

	def insert_at index, data
		current = @head
		tmp = Node.new(data,nil)
		iterator = 0
	#check if it's inbounds
		if(index <= @length)
			if (index == 0)
				insert_at_front(data)
			elsif (index == @length)
				insert_at_end(data)
				puts "calling insert_at_end"
			else
				while (!current.next? && iterator < index)
					current = current.get_next
					iterator += 1
				end
				tmp.set_next(current.get_next)
				current.set_next(tmp)

				@length += 1	
			end
		else
			puts "Index out of Range"	
		end
	end
		

	def get_length
		return @length
	end
end

ll = LL.new(1)
ll.display
puts ll.get_length
puts "\n"

ll.insert_at(1,3)
ll.display
puts ll.get_length
puts "\n"

ll.insert_at(1,2)
ll.display
puts ll.get_length
puts "\n"

