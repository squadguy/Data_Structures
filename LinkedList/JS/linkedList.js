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

	append : function(val){
		let tmp =  new Node();
		tmp.next = null;
		tmp.value = val;

		let current = this.head;

		while (current.next != null){
			current = current.next;
		}

		current.next = tmp;
	},
	
	display : function() {
		let current = this.head;

		while( current != null){
			console.log(current.value);
			current = current.next;
		}
	},

	pop : function(){
		let tmp = new Node();
		tmp.value = null;
		tmp.next = null;

		tmp = this.head;

		this.head = this.head.next;

		return tmp;
	}
}


let ll = Object.create(linkedList);

ll.init(5);
ll.append(10)
ll.append(15)

ll.display();
console.log("###################");
ll.pop();
ll.display();
ll.pop()
console.log("###################");
ll.display();
ll.append(50000);
console.log("###################");
ll.display();
ll.pop();
console.log("###################");
ll.display();

