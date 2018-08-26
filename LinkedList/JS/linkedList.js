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
		tmp.nextNode = null;

		this.head = tmp;
	},

//add to front of list
	prepend : function(val){
		let tmp =  new Node();
		tmp.nextNode = null;
		tmp.value = val;

		let current = this.head;

		while (current.nextNode != null){
			current = current.nextNode;
		}

		current.nextNode = tmp;
	},

//print the list	
	display : function() {
		let current = this.head;

		while(current != null){
			console.log(current.value);
			current = current.nextNode;
		}
	},

//removes and return the first node
	pop : function(){
		let tmp = new Node();
		tmp.value = null;
		tmp.nextNode = null;

		tmp = this.head;

		this.head = this.head.nextNode;

		return tmp;
	},

	pushback : function(value){
		let tmp = new Node();
		tmp.nextNode = null;
		tmp.value = value;

		let current = this.head;

		while(current.nextNode != null){
			current = current.nextNode;
		}
		current.nextNode = tmp; 
	}
}


let ll = Object.create(linkedList);

ll.init(5);
ll.prepend(10);
ll.prepend(15);
ll.pushback(2000);

ll.display();
