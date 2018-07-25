
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
	end
end

ll = LL.new(5)
ll.insert_at_end 2 
ll.insert_at_end 15
ll.insert_at_end 20 
ll.display
