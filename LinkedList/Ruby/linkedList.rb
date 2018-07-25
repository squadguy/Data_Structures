class Node
	attr_accessor :value, :next_node

	def initialize val, next_in_line
		@value = val
		@next_node = next_in_line
		puts "Initialized a Node with value: " + value.to_s
	end
end

#Test Driver to see if class Node is working
#
	linkedList = Node.new(1,nil)
	tmpNode = Node.new(2,nil)
	linkedList.next_node = tmpNode
	tmpNode = Node.new(3,nil)
	linkedList.next_node.next_node = tmpNode
	tmpNode = Node.new(4,nil)
	linkedList.next_node.next_node.next_node = tmpNode
	tmpNode = Node.new(5,nil)
	linkedList.next_node.next_node.next_node.next_node = tmpNode
	puts linkedList.value.to_s
	puts linkedList.next_node.value.to_s
	puts linkedList.next_node.next_node.value.to_s
	puts linkedList.next_node.next_node.next_node.value.to_s
	puts linkedList.next_node.next_node.next_node.next_node.value.to_s

