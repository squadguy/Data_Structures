class Node
	attr_accessor :value, :next_node

	def initialize val, next_in_line
		@value = val
		@next_node = next_in_line
		puts "Initialized a Node with value: " + value.to_s
	end
end

class LinkedList
	def initialize val
		@head = Node.new(val,nil)
	end
	
	def add(value)
		current = @head
		while current.next_node != nil
			current = current.next_node
		end
		current.next_node = Node.new(value,nil)
		self
	end

	def display
		current = @head
		full_list = []
		while current != nil
			puts current.value.to_s.to_s
			current = current.next_node
		end
	end
end



ll = LinkedList.new(5)
ll.add(7)
ll.add(6)
ll.display
