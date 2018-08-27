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

//Add node to front of list
	enqueue : function(val){
		let tmp = new Node();
		tmp.value = val;
		tmp.nextNode = this.head;
	
		this.head = tmp;
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
	dequeue : function(){
		let tmp = new Node();
		tmp.value = null;
		tmp.nextNode = null;

		tmp = this.head;

		this.head = this.head.nextNode;

		return tmp;
	},

//append to list
	push : function(value){
		let tmp = new Node();
		tmp.nextNode = null;
		tmp.value = value;

		if (this.head == null){
			this.head = tmp;
		}
		else{	
			let current = this.head;

			while(current.nextNode != null){
				current = current.nextNode;
			}
		current.nextNode = tmp; 
		}
		
		this.length++;
	},

//build random linked list w/ push
//TO DO:  Init the list with a random variable rather than having to init it first and then run this method
	initRandPB : function(numOfItems, numLimit)
	{
		for (var i = 0; i < numOfItems; i++)
		{
			let num = Math.floor(Math.random() * numLimit);
			this.push(num);
			console.log(num);
		}

	},

	initIncreaseList : function (numOfItems){
		for (var i = 0; i < numOfItems; i++){
			this.push(i);
			//console.log(i);
		}
	},

	getMiddle: function()
	{
		if (this.head == null){
			return this;
		}
		let fastptr = this.head.nextNode;
		let slowptr = this.head;
		
		while (fastptr != null)
		{
			fastptr = fastptr.nextNode;
			if(fastptr != null)
			{
				slowptr = slowptr.nextNode;
				fastptr = fastptr.nextNode;
			}
		}

		return slowptr;
	}
}


let ll = Object.create(linkedList);
ll.initIncreaseList(10);
ll.display();
