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

	def del(val)
		current = @head
		if current.value == val
			@head = @head.next_node
		else
			current = @head
			while (current != nil && current.next_node != nil && ((current.next_node).value != val))
			       current = current.next_node
			end
			if (current.value != nil) && (current.next_node != nil)
				current.next_node = (current.next_node).next_node
			end
		end
	end


	def display
		current = @head
		full_list = []
		while current != nil
			full_list += [current.value.to_s]
			current = current.next_node
		end
		full_list +=[current.to_s]
		puts full_list.join("->")
	end
end


#Test LinkedList class with Display Method
ll = LinkedList.new(5)
ll.add(7)
ll.add(6)
ll.add(8)
ll.display
ll.del(8)
ll.display
ll.del(7)
ll.display
ll.add(7)
ll.display
ll.del(99)
ll.display
ll.add(99)
ll.display
ll.del(99)
ll.display
