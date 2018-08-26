function Node()
{
	var value = 0;
	nextNode = null;

}

let linkedList = {

	head : null,
	length: 0,

	init: function(val){
		var tmp = new Node();
		tmp.value = val;
		tmp.nextNode = null;

		this.head = tmp;

		this.length++;
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

//append to list
	pushback : function(value){
		let tmp = new Node();
		tmp.nextNode = null;
		tmp.value = value;

		let current = this.head;

		while(current.nextNode != null){
			current = current.nextNode;
		}
		current.nextNode = tmp; 
		
		this.length++;
	},

//build random linked list w/ pushback
//TO DO:  Init the list with a random variable rather than having to init it first and then run this method
	initRandPB : function(numOfItems, numLimit)
	{
		for (var i = 0; i < numOfItems; i++)
		{
			let num = Math.floor(Math.random() * numLimit);
			this.pushback(num);
		}

	}
}


let ll = Object.create(linkedList);

ll.init(15);
ll.initRandPB(50, 100);
ll.display();
console.log(ll.length);
