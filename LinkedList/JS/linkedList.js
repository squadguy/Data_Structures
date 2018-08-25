function Node()
{
	var value = 0;
	nextNode = null;

}

let linkedList = {

	head : null,

	init: function(val){
		var tmp = new Node();
		tmp.value = val;
		tmp.next = null;

		this.head = tmp;
	},

//add to front of list
	prepend : function(val){
		let tmp =  new Node();
		tmp.next = null;
		tmp.value = val;

		let current = this.head;

		while (current.next != null){
			current = current.next;
		}

		current.next = tmp;
	},

//print the list	
	display : function() {
		let current = this.head;

		while( current != null){
			console.log(current.value);
			current = current.next;
		}
	},

//removes and return the first node
	pop : function(){
		let tmp = new Node();
		tmp.value = null;
		tmp.next = null;

		tmp = this.head;

		this.head = this.head.next;

		return tmp;
	},

	pushback : function(){
		
	}
}


let ll = Object.create(linkedList);

ll.init(5);
ll.prepend(10)
ll.prepend(15)

ll.display();
console.log("###################");
ll.pop();
ll.display();
ll.pop()
console.log("###################");
ll.display();
ll.prepend(50000);
console.log("###################");
ll.display();
ll.pop();
console.log("###################");
ll.display();

